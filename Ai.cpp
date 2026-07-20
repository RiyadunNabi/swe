#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <random>
#include <sstream>
#include <vector>

using namespace std;
namespace fs = std::filesystem;

// Structure to represent an edge cleanly
struct Edge {
    int u;
    int v;
    double weight;
};

// Separate class for random number generation, kept apart from the solver
// so all randomness (coin flips, RCL picks, seeding) goes through one place.
class RNG {
  public:
    static mt19937& engine() {
        static mt19937 rng(random_device{}());
        return rng;
    }

    static void seed(unsigned s) {
        engine().seed(s);
    }

    // Uniform integer in [lo, hi], inclusive on both ends
    static int uniformInt(int lo, int hi) {
        uniform_int_distribution<> dist(lo, hi);
        return dist(engine());
    }

    // Coin flip: 0 or 1, each with probability 1/2
    static int coinFlip() {
        return uniformInt(0, 1);
    }
};

// Class to encapsulate the Graph and MAX-CUT Algorithms
class MaxCutSolver {
  private:
    int numVertices;
    int numEdges;
    vector<vector<pair<int, double>>> adjList;
    vector<Edge> edges;

  public:
    // Constructor
    MaxCutSolver(int n, int m) : numVertices(n), numEdges(m) {
        adjList.resize(numVertices + 1);
    }

    // Method to build the graph
    void addEdge(int u, int v, double weight) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
        edges.push_back({u, v, weight});
    }

    int getNumVertices() const {
        return numVertices;
    }
    int getNumEdges() const {
        return numEdges;
    }

    // Factory: build a solver directly from a benchmark graph file
    // File format: first line "n m", then m lines "u v w"
    static MaxCutSolver fromFile(const string& path) {
        ifstream fin(path);
        if (!fin)
            throw runtime_error("Cannot open graph file: " + path);

        int n, m;
        fin >> n >> m;
        MaxCutSolver solver(n, m);
        for (int i = 0; i < m; ++i) {
            int u, v;
            double w;
            fin >> u >> v >> w;
            solver.addEdge(u, v, w);
        }
        return solver;
    }

    // Utility method to evaluate a solution
    double calculateCutWeight(const vector<int>& partition) const {
        double cutWeight = 0.0;
        for (const auto& edge : edges) {
            if (partition[edge.u] != partition[edge.v]) {
                cutWeight += edge.weight;
            }
        }
        return cutWeight;
    }

    // 1. Randomized Heuristic
    double solveRandomized(int iterations) {
        double totalCutWeight = 0.0;

        for (int i = 0; i < iterations; ++i) {
            vector<int> partition(numVertices + 1, 0);
            for (int v = 1; v <= numVertices; ++v) {
                // Uniformly place vertex in X (0) or Y (1)
                partition[v] = RNG::coinFlip();
            }
            totalCutWeight += calculateCutWeight(partition);
        }

        // Return the average over n iterations
        return totalCutWeight / iterations;
    }

    // Also expose a single Randomized-1 construction (used as Local Search starting points)
    vector<int> randomPartition() {
        vector<int> partition(numVertices + 1, 0);
        for (int v = 1; v <= numVertices; ++v) 
            partition[v] = RNG::coinFlip();
        return partition;
    }

    // 2. Greedy Heuristic
    vector<int> solveGreedy() {
        vector<int> partition(numVertices + 1, -1);  // -1 means unassigned

        // Find edge with maximum weight to start
        double maxWeight = -1.0;
        int startU = -1, startV = -1;
        for (const auto& edge : edges) {
            if (edge.weight > maxWeight) {
                maxWeight = edge.weight;
                startU = edge.u;
                startV = edge.v;
            }
        }

        // Assign endpoints of the heaviest edge to different sets
        partition[startU] = 0;  // Set X
        partition[startV] = 1;  // Set Y

        // Process the remaining unassigned vertices
        for (int z = 1; z <= numVertices; ++z) {
            if (partition[z] != -1)
                continue;

            double weightX = 0.0;
            double weightY = 0.0;

            for (const auto& neighbor : adjList[z]) {
                if (partition[neighbor.first] == 1)
                    weightX += neighbor.second;
                else if (partition[neighbor.first] == 0)
                    weightY += neighbor.second;
            }

            // Greedily place in the set that contributes more to the cut
            if (weightX > weightY) {
                partition[z] = 0;
            } else {
                partition[z] = 1;
            }
        }

        return partition;
    }

    // 3. Semi-Greedy Heuristic
    //
    // Maintains sigmaX[v]/sigmaY[v] (v's total edge weight into X / into Y so
    // far) incrementally: after each assignment we only touch the neighbors
    // of the vertex just placed, instead of re-summing every unassigned
    // vertex's whole adjacency list on every step. That keeps one full
    // construction to O(V + E) total instead of O(V*E).
    vector<int> solveSemiGreedy(double alpha) {
        vector<int> partition(numVertices + 1, -1);
        vector<double> sigmaX(numVertices + 1, 0.0);
        vector<double> sigmaY(numVertices + 1, 0.0);

        double maxWeight = -1.0;
        int startU = -1, startV = -1;
        for (const auto& edge : edges) {
            if (edge.weight > maxWeight) {
                maxWeight = edge.weight;
                startU = edge.u;
                startV = edge.v;
            }
        }

        partition[startU] = 0;
        partition[startV] = 1;
        for (const auto& neighbor : adjList[startU]){ 
            sigmaX[neighbor.first] += neighbor.second;
        }
        for (const auto& neighbor : adjList[startV]){
            sigmaY[neighbor.first] += neighbor.second;
        }
        int assignedCount = 2;

        while (assignedCount < numVertices) {
            double w_min = 1e18, w_max = -1e18;

            for (int v = 1; v <= numVertices; ++v) {
                if (partition[v] != -1)
                    continue;
                w_min = min({w_min, sigmaX[v], sigmaY[v]});
                w_max = max({w_max, sigmaX[v], sigmaY[v]});
            }

            // Calculate the cut-off threshold for the Restricted Candidate List (RCL)
            double mu = w_min + alpha * (w_max - w_min);
            vector<int> rcl;

            for (int v = 1; v <= numVertices; ++v) {
                if (partition[v] == -1 && max(sigmaX[v], sigmaY[v]) >= mu) {
                    rcl.push_back(v);
                }
            }

            // Select randomly from the RCL
            int chosen_v = rcl[RNG::uniformInt(0, (int)rcl.size() - 1)];

            int placeSide = (sigmaX[chosen_v] >= sigmaY[chosen_v]) ? 1 : 0;
            partition[chosen_v] = placeSide;
            assignedCount++;

            // Only the newly-assigned vertex's neighbors need updating
            for (const auto& neighbor : adjList[chosen_v]) {
                if (partition[neighbor.first] != -1)
                    continue;
                if (placeSide == 0)
                    sigmaX[neighbor.first] += neighbor.second;
                else
                    sigmaY[neighbor.first] += neighbor.second;
            }
        }

        return partition;
    }

    // 4. Local Search
    vector<int> solveLocalSearch(vector<int> partition) {
        bool improvement = true;

        while (improvement) {
            improvement = false;

            for (int v = 1; v <= numVertices; ++v) {
                double sigma_S = 0.0;      // Edges to nodes in the SAME set
                double sigma_S_bar = 0.0;  // Edges to nodes in the OPPOSITE set

                int currentSet = partition[v];

                for (const auto& neighbor : adjList[v]) {
                    if (partition[neighbor.first] == currentSet) {
                        sigma_S += neighbor.second;
                    } else {
                        sigma_S_bar += neighbor.second;
                    }
                }

                // Change in cut value if vertex v is moved to the opposite set
                double delta = sigma_S - sigma_S_bar;

                if (delta > 0) {
                    partition[v] = 1 - partition[v];  // Swap the partition (0 -> 1 or 1 -> 0)
                    improvement = true;               // Continue searching
                }
            }
        }
        return partition;
    }

    // "Local-1" table entry: run local search `reps` times, each starting from an
    // independent Randomized-1 construction, and report (iterations, average value).
    pair<int, double> solveLocalSearchAveraged(int reps) {
        double total = 0.0;
        for (int i = 0; i < reps; ++i) {
            vector<int> start = randomPartition();
            vector<int> finished = solveLocalSearch(start);
            total += calculateCutWeight(finished);
        }
        return {reps, total / reps};
    }

    // 5. GRASP (Greedy Randomized Adaptive Search Procedure)
    double solveGrasp(int maxIterations, double alpha) {
        double bestCutWeight = -1.0;

        for (int i = 0; i < maxIterations; ++i) {
            // Construction Phase
            vector<int> constructedSolution = solveSemiGreedy(alpha);

            // Local Search Phase
            vector<int> localOptimum = solveLocalSearch(constructedSolution);

            double currentCutWeight = calculateCutWeight(localOptimum);

            if (currentCutWeight > bestCutWeight) {
                bestCutWeight = currentCutWeight;
            }
        }

        return bestCutWeight;
    }
};

// ============================================================
// Known best / upper bound table (24 benchmark graphs, from the assignment PDF)
// ============================================================
double lookupKnownBest(const string& graphFileName, bool& found) {
    static const map<string, double> table = {
        {"G1", 12078}, {"G2", 12084}, {"G3", 12077}, {"G11", 627},   {"G12", 621},   {"G13", 645},
        {"G14", 3187}, {"G15", 3169}, {"G16", 3172}, {"G22", 14123}, {"G23", 14129}, {"G24", 14131},
        {"G32", 1560}, {"G33", 1537}, {"G34", 1541}, {"G35", 8000},  {"G36", 7996},  {"G37", 8009},
        {"G43", 7027}, {"G44", 7022}, {"G45", 7020}, {"G48", 6000},  {"G49", 6000},  {"G50", 5988}};

    string stem = graphFileName;
    size_t dot = stem.find_last_of('.');
    if (dot != string::npos)
        stem = stem.substr(0, dot);

    // Normalize to the table's "G<number>" form regardless of case
    // (dataset uses "g1.rud", table keys use "G1")
    for (char& c : stem) c = (char)toupper((unsigned char)c);

    auto it = table.find(stem);
    found = (it != table.end());
    return found ? it->second : 0.0;
}

// ============================================================
// One CSV row's worth of results for a single graph
// ============================================================
struct ResultRow {
    string name;
    int V = 0, E = 0;
    double randomizedAvg = 0.0;
    double greedy = 0.0;
    double semiGreedy = 0.0;
    int lsIters = 0;
    double lsAverage = 0.0;
    int graspIters = 0;
    double graspBest = 0.0;
    bool hasKnownBest = false;
    double knownBest = 0.0;
};

ResultRow runAllAlgorithms(const string& path, const string& name, double alpha, int randReps,
                           int lsReps, int graspIters) {
    MaxCutSolver solver = MaxCutSolver::fromFile(path);

    ResultRow row;
    row.name = name;
    row.V = solver.getNumVertices();
    row.E = solver.getNumEdges();

    row.randomizedAvg = solver.solveRandomized(randReps);
    row.greedy = solver.calculateCutWeight(solver.solveGreedy());
    row.semiGreedy = solver.calculateCutWeight(solver.solveSemiGreedy(alpha));

    auto [iters, avgVal] = solver.solveLocalSearchAveraged(lsReps);
    row.lsIters = iters;
    row.lsAverage = avgVal;

    row.graspIters = graspIters;
    row.graspBest = solver.solveGrasp(graspIters, alpha);

    row.knownBest = lookupKnownBest(name, row.hasKnownBest);

    return row;
}

void writeCsv(const string& outPath, const vector<ResultRow>& rows, double alpha) {
    ofstream fout(outPath);
    fout << "Name,|V| or n,|E| or m," << "Simple Randomized or Randomized-1,"
         << "Simple Greedy or Greedy-1," << "Semi-greedy-1 (alpha=" << alpha << "),"
         << "Local search: No. of iterations,Local search: Average value,"
         << "GRASP-1: No. of iterations,GRASP-1: Best value,"
         << "Known best solution or upper bound\n";

    fout << fixed << setprecision(2);
    for (const auto& r : rows) {
        fout << r.name << "," << r.V << "," << r.E << "," << r.randomizedAvg << "," << r.greedy
             << "," << r.semiGreedy << "," << r.lsIters << "," << r.lsAverage << "," << r.graspIters
             << "," << r.graspBest << ",";
        if (r.hasKnownBest)
            fout << r.knownBest;
        fout << "\n";
    }
}

// ============================================================
// Minimal CLI option lookup
// ============================================================
string getOpt(int argc, char** argv, const string& key, const string& def) {
    for (int i = 0; i < argc; ++i)
        if (key == argv[i] && i + 1 < argc)
            return argv[i + 1];
    return def;
}
bool hasOpt(int argc, char** argv, const string& key) {
    for (int i = 0; i < argc; ++i)
        if (key == argv[i])
            return true;
    return false;
}

void printUsage() {
    cerr << "Usage:\n"
         << "  ./maxcut <graph_file>                         run all algorithms on one graph\n"
         << "  ./maxcut --batch <graph_folder> <output.csv>  run all algorithms on every graph\n"
         << "                                                  in the folder and write the CSV\n"
         << "Options (apply to both modes):\n"
         << "  --alpha <double>   semi-greedy RCL alpha        (default 0.5)\n"
         << "  --n <int>          Randomized-1 averaging reps  (default 30)\n"
         << "  --ls-reps <int>    Local-1 averaging reps       (default 20)\n"
         << "  --iters <int>      GRASP iterations              (default 50)\n"
         << "  --seed <int>       RNG seed\n";
}

// Extracts the trailing number from a filename stem, e.g. "g12" -> 12, "G3" -> 3.
// Returns -1 if the stem has no trailing digits (so it sorts before numbered ones).
int trailingNumber(const string& stem) {
    size_t i = stem.size();
    while (i > 0 && isdigit((unsigned char)stem[i - 1])) --i;
    if (i == stem.size())
        return -1;
    return stoi(stem.substr(i));
}

// Natural sort: "g2.rud" before "g10.rud" (plain string sort would put g10 first).
bool naturalFileLess(const fs::path& a, const fs::path& b) {
    string stemA = a.stem().string();
    string stemB = b.stem().string();
    int numA = trailingNumber(stemA);
    int numB = trailingNumber(stemB);
    if (numA != -1 && numB != -1 && numA != numB)
        return numA < numB;
    return stemA < stemB;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printUsage();
        return 1;
    }

    double alpha = stod(getOpt(argc, argv, "--alpha", "0.5"));
    int randReps = stoi(getOpt(argc, argv, "--n", "30"));
    int lsReps = stoi(getOpt(argc, argv, "--ls-reps", "20"));
    int graspIters = stoi(getOpt(argc, argv, "--iters", "50"));

    if (hasOpt(argc, argv, "--seed")) {
        RNG::seed((unsigned)stoi(getOpt(argc, argv, "--seed", "0")));
    }

    // Batch mode: run every graph in a folder and produce the assignment CSV
    if (string(argv[1]) == "--batch") {
        if (argc < 4) {
            printUsage();
            return 1;
        }
        string folder = argv[2];
        string outCsv = argv[3];

        vector<fs::path> files;
        for (auto& entry : fs::directory_iterator(folder))
            if (entry.is_regular_file())
                files.push_back(entry.path());
        sort(files.begin(), files.end(), naturalFileLess);

        vector<ResultRow> rows;
        for (auto& path : files) {
            string name = path.filename().string();
            cout << "Processing " << name << " ...\n";
            try {
                rows.push_back(
                    runAllAlgorithms(path.string(), name, alpha, randReps, lsReps, graspIters));
            } catch (exception& e) {
                cerr << "  Failed on " << name << ": " << e.what() << "\n";
            }
        }

        writeCsv(outCsv, rows, alpha);
        cout << "Done. Results written to " << outCsv << "\n";
        return 0;
    }

    // Single-graph mode: same five algorithms, printed to stdout
    string graphFile = argv[1];
    MaxCutSolver solver = MaxCutSolver::fromFile(graphFile);

    cout << fixed << setprecision(2);

    double randResult = solver.solveRandomized(randReps);
    cout << "Randomized (avg over " << randReps << " runs): \t" << randResult << endl;

    vector<int> greedyPartition = solver.solveGreedy();
    double greedyResult = solver.calculateCutWeight(greedyPartition);
    cout << "Greedy: \t\t\t" << greedyResult << endl;

    vector<int> semiGreedyPartition = solver.solveSemiGreedy(alpha);
    double semiGreedyResult = solver.calculateCutWeight(semiGreedyPartition);
    cout << "Semi-Greedy (alpha=" << alpha << "): \t" << semiGreedyResult << endl;

    auto [lsIters, lsAvg] = solver.solveLocalSearchAveraged(lsReps);
    cout << "Local Search (avg over " << lsIters << " random starts): \t" << lsAvg << endl;

    double graspResult = solver.solveGrasp(graspIters, alpha);
    cout << "GRASP (Iterations=" << graspIters << "): \t" << graspResult << endl;

    return 0;
}
