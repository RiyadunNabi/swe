Let me go through every single page of every exam paper very carefully, one by one.

---

# COMPLETE DESIGN PATTERN QUESTIONS — ALL YEARS

---

## 🏭 1. FACTORY METHOD PATTERN

**1.** (19 Batch | L-3/T-1, 2021-2022 | Date: 07/05/2023 | Q.1b)
Your younger brother wanted to build an *Avengers* themed game. He wrote a method which takes a Super Hero's name as input and returns the Super Hero item used by that Super Hero:
```
class GetSuperHeroItem {
    public SuperHeroItem getItem(String heroName) {
        if (heroName.equalsIgnoreCase("IronMan")) return suit;
        else if (heroName.equalsIgnoreCase("Thor")) return hammer;
        else if (heroName.equalsIgnoreCase("CaptainAmerica")) return shield;
        else if (heroName.equalsIgnoreCase("Hawkeye")) return arrow;
        else return null;
    }
}
```
You know a better way to implement the functionality he wanted. Now **re-write the code** in such a way that would be much easier to read and maintain, also your method should have **constant run-time (amortized)**. *(13 marks)*

---

**2.** (17 Batch | L-3/T-1, 2019-2020 | Date: 19/10/2022 | Q.4a-i)
For each of the situations below, identify the most specific pattern used:
You are building your own video streaming platform named *NuetFlix*. In the earlier version of *NuetFlix*, it only provides three types of genres: Horror, Thriller and Comedy. A user can choose any one or more of these genres as their preferred genre. When a movie releases you must **recommend the movie to the users** who are interested in that particular genre (in which the newly released movie belongs). *(Part of 20 marks)*

---

**3.** (16 Batch | L-3/T-1, 2018-2019 | Date: 06/11/2019 | Q.5c)
Assume that you are trying to implement **syntax highlighting** in a programming language editor. To perform this, you need to be able to parse different kinds of files such as .c, .cpp, .java, .html etc. All the parsers implement an interface named `Parser` which contains all the functions required to parse a file. When a file is selected, you will decide which parser to use based on the **extension of the file**. Now which design pattern should be followed to implement the selection process? **Write appropriate Java implementation** of your solution.
[Hint: You don't need to write the parsers. Clearly mention the assumptions you have made.] *(3+7=10 marks)*

---

**4.** (12 Batch | L-3/T-1, 2014-2015 | Date: 17/05/2014 | Q.1c)
Suppose you have to develop an application that takes a string of the format **A operator1 B operator2 C** as input and provides the result of the corresponding operation. Here, A, B and C are number strings and the operator1 and operator2 are any one of +, −, *, / operators. Which design pattern will you choose to design a solution to the problem and why? **Draw the appropriate class diagram** for your proposed solution approach. *(4+10=14 marks)*

---

**5.** (11 Batch | L-3/T-1, 2013-2014 | Date: 23/09/2013 | Q.1a)
Discuss the different **implementation issues and consequences of Composite Pattern**.
*(Note: Same question also touches Factory in context — Singleton pattern code fragment question in same paper)*

---

## 🏭 2. ABSTRACT FACTORY PATTERN

**1.** (21 Batch | L-2/T-2, 2023-2024 | Date: 09/02/2025 | Q.5a)
A software system is being developed for a **pizza delivery service** that allows customers to order pizzas with regional styles. The service operates in two countries, **Italy and America**, each with distinct preferences for pizza types. For instance, the crust type and toppings differ between regions. The system must ensure that each pizza is created with region-specific ingredients and should be easily extendable in the future to accommodate additional countries. **Identify the most suitable design pattern to solve the given problem. Justify your choice and provide the corresponding code implementation.** *(15 marks)*

---

**2.** (19 Batch | L-3/T-1, 2021-2022 | Date: 07/05/2023 | Q.1a)
Differentiate the use cases of the following design patterns with necessary examples and/or figures:
**Factory Method Pattern, Abstract Factory Pattern, Builder Pattern and Bridge Pattern** *(16 marks)*

---

**3.** (18 Batch | L-3/T-1, 2020-2021 | Date: 19/10/2022 | Q.1a)
Consider a burger shop selling burger, appetizer and drinks. The following points describe the services:
(1) Three different types of pizza are being sold: Veggi, Beef and Chicken
(2) There are provisions to add extra cheese on those pizza
(3) There are provisions of different types of drinks: Coffee, Water and Coke. The prices of these different types of drinks are different. The customer can select one or more drinks in an order
(4) Onion Rings and French Fries are two different types of appetizers available
(5) A customer can order a meal which consists of an appetizer, a pizza with necessary cheese and drinks

Construct a class indicating the following using **three different patterns**:
(1) Beef pizza with French fry and cheese
(2) Chicken Pizza with onion rings and Bottle of Water
(3) A combo meal with Veggi pizza, French Fry and two bottles of Coke
(4) A combo meal with Veggi pizza, Onion Rings, Coffee and Water
In each of the cases determine the price of the options shown above as a method of the class to be created. *(28 marks)*

---

**4.** (17 Batch | L-3/T-1, 2019-2020 | Date: 19/10/2022 | Q.3a)
Suppose you are working on a restaurant's software development team. Your restaurant provides four kinds of set menus such as: *Veggie Harvest, Chicken Delight, Beef Fiesta, Sea Shanty*.
- *Veggie Harvest* contains Mushroom Rice, Paneer Masala and Fried Vegetable Pakora
- *Chicken Delight* contains Chicken Fried Rice, Butter Chicken and Fried Chicken wings
- *Beef Fiesta* contains Beef Fried Rice, Beef Chili Onion and Fried Beef Bacon
- *Sea Shanty* contains Rice with Shrimp, Crab Masala and Fried Calamari

Your restaurant has three different kitchens named as *Rice Station* where all the rice based items are prepared, *Main Mania* where all the main dishes are prepared and *Fry More* where the fried items are prepared.

Your restaurant takes orders from the user, then assembles the items prepared by the kitchens and delivers it. **Identify the design pattern that can best capture the scenario above and implement it using your preferred language (you can use pseudo syntax). You must provide the UML class diagram of your implementation. ***Be careful, as users are very sensitive to their orders.*** *(20 marks)*

---

**5.** (15 Batch | L-3/T-1, 2017-2018 | Date: 29/09/2018 | Q.1a)
There are several options of ERP implementation for an organization which has 250 users *(decision tree / cost analysis question — Abstract Factory not directly tested here, skip)*

---

## 🔒 3. SINGLETON PATTERN

**1.** (19 Batch | L-3/T-1, 2021-2022 | Date: 07/05/2023 | Q.1a)
Differentiate the use cases of **Factory Method Pattern, Abstract Factory Pattern, Builder Pattern and Bridge Pattern** with necessary examples and/or figures. *(16 marks)*
*(Singleton contrasted as a creational pattern in same section)*

---

**2.** (17 Batch | L-3/T-1, 2019-2020 | Date: 19/10/2022 | Q.5a)
Describe **eager and lazy initialization** of singleton class.
Give an example where **lazy initialization should be preferred** over eager initialization. *(5+5+5=15 marks)*

---

**3.** (16 Batch | L-3/T-1, 2018-2019 | Date: 06/11/2019 | Q.5a)
Describe **eager and lazy initialization** of singleton class.
Give an example where **lazy initialization should be preferred** over eager initialization. *(5+5+5=15 marks)*

---

**4.** (14 Batch | L-3/T-1, 2016-2017 | Date: 15/07/2017 | —)
*(No direct Singleton standalone question in this paper)*

---

**5.** (12 Batch | L-3/T-1, 2014-2015 | Date: 17/05/2014 | Q.2a)
Differentiate between **lazy and eager initialization** of Singleton pattern. Draw the structure of singleton pattern. *(6+4=10 marks)*

---

**6.** (11 Batch | L-3/T-1, 2013-2014 | Date: 23/09/2013 | Q.1b)
Write a **Java code fragment** based on Singleton Pattern. There should be a class called `Base`, which can be inherited by other classes. Define two classes called `Derived1` and `Derived2` that will inherit Base. The maximum number of instances of `Derived1` and `Derived2` that can be created is **5 and 10** respectively. Write a main function where two arrays of Derived1 and Derived2 are created respectively and show the Singleton implementation. *(18⅔ marks)*

---

**7.** (10 Batch | L-3/T-1, 2012-2013 | Date: 19/03/2012 | Q.4a)
Which of the following (i) and (ii) is a **valid implementation of Singleton Pattern**? Give specific reason for each of the following implementation:

*(i)*
```java
public class Singleton {
    private static Singleton s_singleton = new Singleton();
    private Singleton() {}
    private static Singleton getInstance() {
        return s_singleton;
    }
}
```
*(ii)*
```java
public class Singleton {
    private Singleton() {}
    private static class SingletonHolder {
        private static final Singleton instance = new Singleton();
    }
    public static Singleton getInstance() {
        return SingletonHolder.instance;
    }
}
```
*(5 marks)*

---

**8.** (09 Batch | L-3/T-1, 2011-2012 | Date: 19/03/2012 | Q.1a)
*(Web-based application with userID, districtID, qualificationID, TxID — all serially generated from 1, unique, used as primary keys)*
Consider a web based application that stores the information of users for registration purpose. After successful registration the registration page returns a **user identification number (userID)**. The registration process also requires identifiers to identify the home district and educational qualification. The web application has the facility to create a home district and educational qualifications as per requirement of the user. The transactions made by the web based application will also be identified by another identifier **(TxID)**. A particular identifier will never be duplicate and it is expected that the identifiers are created serially starting from 1. **Demonstrate creation of those identifiers in the back end of your application whenever necessary by the user interface using a suitable design pattern.** *(15 marks)*

---

## 🏗️ 4. BUILDER PATTERN

**1.** (19 Batch | L-3/T-1, 2021-2022 | Date: 07/05/2023 | Q.1a)
Differentiate the use cases of **Factory Method Pattern, Abstract Factory Pattern, Builder Pattern and Bridge Pattern** with necessary examples and/or figures. *(16 marks)*

---

**2.** (20 Batch | L-3/T-1, 2022-2023 | Date: 05/05/2024 | Q.3)
A Director class `HTMLPageDirector` is given a builder class `HTMLPageBuilder`. The director tells the builder what the `pageTitle` & `pageHeading` will be, and gives multiple lines of text for the page. The director then has the builder do a final assembly of the parts, and return the *page*. **Draw a class diagram to present appropriate design pattern and write necessary codes so that your code fulfills all the requirements.** *(15 marks)*

---

**3.** (16 Batch | L-3/T-1, 2018-2019 | Date: 06/11/2019 | Q.3b)
There is a software application that can be used by students of a University to provide them with the list of their grades for their exams. This application needs to run in different ways depending on the users that are using it. For example, the **admin needs to have some buttons enabled** whereas those buttons need to be **disabled for the student**. The Builder provides the interface for building forms depending on the user login information. The ConcreteBuilders are the specific forms for each type of user. The product is the final form that the application will use in the given case and the Director is the application that, based on the login information, needs a specific form. **Draw a class diagram to present Builder design pattern and write necessary codes so that your code fulfills all the requirements.** *(20 marks)*

---

**4.** (17 Batch | L-3/T-1, 2019-2020 | Date: 19/10/2022 | Q.4a-ii)
For each of the situations below, identify the most specific pattern:
You want to build your own version control system named *jit*. Where you want to provide some basic functionalities such as:
- ***kommit*** that saves your current updates locally but doesn't sync with the remote version
- ***pussh*** that syncs all the "kommit"ed codes with the remote version
- ***stashh*** that discards all the un"pussh"ed "kommit"s and retrieves the latest remote version to the local

*(Identify the most specific pattern used — Part of 20 marks)*

---

**5.** (13 Batch | L-3/T-1, 2015-2016 | Date: 08/08/2015 | Q.1d)
Consider a teller of a bank serving clients to deposit examination fees in a queue. Show the **extended version of use case** for depositing examination fees by a student. *(15 marks)*
*(Builder pattern context within the same paper)*

---

## 🎯 5. STRATEGY PATTERN

**1.** (18 Batch | L-3/T-1, 2020-2021 | Date: 19/10/2022 | Q.2b)
There are three sorting routines implementing **selection, insertion and quicksort** algorithm. **Demonstrate the use of strategy pattern** for using these routines for sorting. *(10 marks)*

---

**2.** (17 Batch | L-3/T-1, 2019-2020 | Date: 19/10/2022 | Q.2b)
There are three sorting routines implementing **selection, insertion and quicksort** algorithm. **Demonstrate the use of strategy pattern** for using these routines for sorting. *(10 marks)*

---

**3.** (16 Batch | L-3/T-1, 2018-2019 | Date: 06/11/2019 | Q.2a)
An application needs to be developed to simulate and study **robots' interaction**. You have the following classes:
- `IBehaviour` — an interface that defines the behavior of a robot
- `AggressiveBehaviour`, `DefensiveBehaviour`, `NormalBehaviour` — each of them defines a specific behavior
- `Robot` — It keeps or gets information such as position, close obstacles, etc., and passes necessary information to the appropriate class

In the main section several robots are created:
- 'Big Robot' is an aggressive one and attacks any other robot found
- 'George v.2.1' is really scared and runs away in the opposite direction when it encounters another robot
- 'R2' is pretty calm and ignores any other robot
- At some point the **behaviors are changed** for each robot

**Draw a class diagram to present appropriate design pattern and write necessary codes so that your code fulfills all the requirements.** *(20 marks)*

---

**4.** (15 Batch | L-3/T-1, 2017-2018 | Date: 29/09/2018 | Q.7b)
"**Uber**" and "**Pathao**" are the popular car based ride sharing applications. They calculate cost based on number of passengers and distance using the following formula:
- **Uber:** Cost = n×d×18×time_factor (time_factor = 1.8/1.2/0.9 for extremely/moderately/off peak)
- **Pathao:** Cost = n×d×20×time_factor (time_factor = 1.5/1.15/0.9)
- **Uber Moto:** Cost = 25 + d×12
- **Pathao Moto:** Cost = 30 + d×11

The user will input the destination distance, number of passengers and an input t (t=1,2,3 for extremely peak, moderately peak and off peak hour respectively). You need to output the cost for each app. **Draw a class diagram to present appropriate design pattern and write necessary codes so that your code fulfills all the requirements.** *(6+15 marks)*

---

**5.** (14 Batch | L-3/T-1, 2016-2017 | Date: 15/07/2017 | Q.2a)
Consider a web-based system where users will **select a mobile phone talk time scheme** and the cost associated with the scheme will be displayed to the users. New schemes are added frequently. **Demonstrate how you can decouple the programmers of the user interface from the classes implementing the schemes.** *(10 marks)*

---

**6.** (13 Batch | L-3/T-1, 2015-2016 | Date: 08/08/2015 | Q.2c)
There is a list of student IDs with their obtained marks. You are to find the corresponding grades of the students. You must prepare a merit list for the students who get the highest grade. **Provide a suitable solution using a design pattern. Write necessary code to demonstrate the solution. You can assume any grading scheme in this problem.** *(15 marks)*

---

## 👁️ 6. OBSERVER PATTERN

**1.** (21 Batch | L-2/T-2, 2023-2024 | Date: 09/02/2025 | Q.2a)
You are required to build a notification system named *StockMarket*. The system can generate *StockGrabber* objects. Each *StockGrabber* object sends notifications to all of its registered observers, **only when a different price** of a stock item is set. If the price is not changed, setting the same value does not generate any notification. When a *StockObserver* object gets registration under a *StockGrabber*, it gets an **autogenerated observerID** (starting from 1) and knows the prices of all stock items known to the associated *StockGrabber*. Assume for starting the system, when a *StockGrabber* is generated, it gets prices of three stocks items — *aplPrice* ($230), *googPrice* ($200) and *ibmPrice* ($180).

Partial code given:
```java
public interface StockExchange {
    public void register(StockObserver newObserver);
    public void unregister(StockObserver newObserver);
    public void notifyAllObserver(String company, double price);
}
public interface Observer {
    public void update(String company, double price);
}
public class StockMarket {
    public static void main(String[] args) {
        StockGrabber securityCompany = new StockGrabber("Shamol");
        Observer observer1 = new StockObserver(securityCompany, "Arif");
        Observer observer2 = new StockObserver(securityCompany, "Kamal");
        securityCompany.setAplPrice(250.0);
        securityCompany.setGoogPrice(200.0);
    }
}
```
**(i) Draw the appropriate UML diagram for the above descriptions using appropriate design pattern. (6 marks)
(ii) Write down the codes for StockGrabber and StockObserver class so that no changes in the above code is required using appropriate Design Pattern. Ensure that the classes have minimum number of methods with simplified design and avoid any setters and getters which are unnecessary for the above code segment. (8×2=16 marks)**

---

**2.** (20 Batch | L-3/T-1, 2022-2023 | Date: 05/05/2024 | Q.4a)
There is a **blog of former BUET students**. BUET Alumni register to that blog for receiving updates. When a new article is posted in the blog, it will send update to the registered users saying a new article is posted. Then the user will access the blog and read the new article posted. **Draw a class diagram to present appropriate design pattern and write necessary codes so that your code fulfills all the requirements following the pattern.** *(15 marks)*

---

**3.** (19 Batch | L-3/T-1, 2021-2022 | Date: 07/05/2023 | Q.3b)
Consider a **dashboard** that shows the maximum temperature and average temperature of the last one year. The temperature of the day is entered at the end of day. This triggers **updating the temperature in the dashboard**. You have to demonstrate the solution using appropriate software design pattern. *(10 marks)*

---

**4.** (16 Batch | L-3/T-1, 2018-2019 | Date: 06/11/2019 | Q.8b)
Assume that there is a **blog** and users register to that blog for updates. When a new article is posted in the blog, it will send update to the registered users saying a new article is posted. Then the user will access the blog and read the new article posted. **Draw a class diagram to present appropriate design pattern and write necessary codes so that your code fulfills all the requirements.** *(5+12 marks)*

---

**5.** (15 Batch | L-3/T-1, 2017-2018 | Date: 29/09/2018 | Q.8b)
Assume that there is a **blog** and users register to that blog for updates. When a new article is posted in the blog, it will send update to the registered users saying a new article is posted. Then the user will access the blog and read the new article posted. **Draw a class diagram to present appropriate design pattern and write necessary codes so that your code fulfills all the requirements.** *(5+12 marks)*

---

**6.** (17 Batch | L-3/T-1, 2019-2020 | Date: 19/10/2022 | Q.4a-i)
You are building your own video streaming platform named *NuetFlix*. It only provides three types of genres: Horror, Thriller and Comedy. A user can choose any one or more of these as their preferred genre. When a movie releases you must **recommend the movie to the users** who are interested in that particular genre. *(Identify the most specific pattern — Part of 20 marks)*

---

**7.** (09 Batch | L-3/T-1, 2011-2012 | Date: 04/09/2021 | —)
*(No direct Observer standalone in this paper)*

---

## 🔗 7. MEDIATOR PATTERN

**1.** (20 Batch | L-3/T-1, 2022-2023 | Date: 05/05/2024 | Q.2a)
**Air traffic controller (ATC)** helps in communication between flights and coordinates/controls landing, take-off. Two flights need not interact directly and there is no dependency between them. This dependency is solved by the ATC. **Draw a class diagram to present appropriate design pattern and write necessary codes so that your code fulfills all the requirements.** *(15 marks)*

---

**2.** (09 Batch | L-3/T-1, 2011-2012 | Date: 04/09/2021 | Q.1b)
There are three servers serving sorting requests using **selection, insertion and quicksort** algorithms. There is a **central broker** that receives request of sorting by an algorithm with the data to be sorted. The central broker forwards the request to the appropriate server and returns the result to the class requesting for sorting service after getting the sorted array from the server. The central broker maintains a **queue** if more than one request arrives at a time. **Demonstrate the use of mediator pattern for this system.** *(20 marks)*

---

**3.** (17 Batch | L-3/T-1, 2019-2020 | Date: 19/10/2022 | Q.4a-iv)
You work on a software development team of a peer-reviewed journal named *R2-D2*. Authors submit articles, a team of experts receives them and expresses opinions (reviews). These reviews are acknowledged by the authors. Authors try to update their articles and re-submit. Finally, those experts receive the modified version and decide to accept or reject. **In all of these communications no author could know the identity of the reviewers and vice-versa.** These communications occur via an internal team formed by the journal committee. You need to build an automated system to facilitate this situation. *(Identify the most specific pattern — Part of 20 marks)*

---

**4.** (10 Batch | L-3/T-1, 2012-2013 | Date: 19/03/2012 | Q.1b — Section A)
There are three servers serving sorting requests using selection, insertion and quicksort algorithms. There is a **central broker** that receives request of sorting by an algorithm with the data to be sorted. The central broker forwards the request to the appropriate server and returns the result. The central broker maintains a queue if more than one request arrives at a time. **Demonstrate the use of mediator pattern for this system.** *(20 marks)*

---

## 📋 8. TEMPLATE METHOD PATTERN

**1.** (21 Batch | L-2/T-2, 2023-2024 | Date: 09/02/2025 | Q.2b — continuation)
Read the following program descriptions carefully and **draw the appropriate UML diagram using appropriate design pattern** to represent them.

The *HelpHandler* class defines the interface for handling help requests. It maintains a help topic (which is empty by default) and keeps a reference to its **successor** on the chain of help handlers. The key operation is *HandleHelp*, which subclasses override. *HasHelp* is a convenience operation for checking whether there is an associated help topic. All widgets (like *Dialog, Button*) are subclasses of the *Widget* abstract class. *Widget* is a subclass of *HelpHandler*, since all user interface elements can have help associated with them. *Button's* version of *HandleHelp* first tests to see if there is a help topic for buttons. If the developer hasn't defined one, then the request gets forwarded to the successor using the operation *HandleHelp* in *HelpHandler*. If there is a help topic, then the button displays it and the search ends. *Dialog* implements a similar scheme, except that its successor is not a widget but any help handler. This successor is an instance of *Application*. The Application is not a widget, so *Application* is subclassed directly from *HelpHandler*. When a help request propagates to this level, the application can supply information in general or it can offer a list of different help topics. *(8 marks)*

---

## 🔄 9. STATE PATTERN

**1.** (17 Batch | L-3/T-1, 2019-2020 | Date: 19/10/2022 | Q.4a-iii)
For each of the situations below, identify the most specific pattern:
You work in a telecommunication company named *BanglaPhone*. BanglaPhone has **two different implementations** for their mobile communication. One of the implementation is more stable, can support a lot of users but it incurs more cost and tends to be slower. The other implementation is fast, cheaper but less stable if user count surpasses a threshold. Your company wants to **switch between the implementations without hampering any other code segments** based on the **current number of users** under a specific cell tower. *(Part of 20 marks)*

---

## 🎨 10. DECORATOR PATTERN

**1.** (18 Batch | L-3/T-1, 2020-2021 | Date: 19/10/2022 | Q.1a)
*(Same burger shop question as Abstract Factory — Q.1b specifically asks):*
Discuss the **relative advantages and disadvantages of using different patterns** in constructing the class in the problem 1(a). *(7 marks)*

---

**2.** (16 Batch | L-3/T-1, 2018-2019 | Date: 06/11/2019 | Q.6a)
In the food shop at **Lalbagh** many BUET students visit to have dinners. There, they have option to choose different types of set-meals. Each has a main item like rice or bread. Along with rice, gravy curries are added. For bread, chicken or beef kebabs are there. Drinks/juices need to be ordered additionally out of the set-meal if the customer desires to have. Along with the meal, the bill is served and need to be paid before the start of consumption. **Draw a class diagram to present appropriate design pattern and write necessary codes so that your code fulfills all the requirements.** *(7+15 marks)*

---

**3.** (17 Batch | L-3/T-1, 2019-2020 | Date: 19/10/2022 | Q.1a)
Consider a burger shop selling burger, appetizer and drinks *(same full question as 18 Batch Q.1a above — Decorator is one of the three patterns expected)*. *(28 marks)*

---

**4.** (19 Batch | L-3/T-1, 2021-2022 | Date: 07/05/2023 | Q.2a)
Let's assume you are building your own **computer networking model** with five layers: Physical, Data-link, Network, Transport and Application Layer. When a user wants to send a message (e.g. "hello"):
- First user creates a Packet Object with Message and Length
- Application Layer adds APPHEADER → message: APPHEADER_hello, length: 15
- Transport Layer adds TRHEADER → message: TRHEADER_APPHEADER_hello, length: 24
- Network Layer adds NETHEADER → length: 34
- Data-link Layer adds DHEADER and DTRAILER → length: 51
- Physical Layer adds PHEADER → length: 59

**Identify the design pattern that can best capture the scenario above and implement it using your preferred language (you can use pseudo syntax). You must provide the UML class diagram of your implementation.** *(20 marks)*

---

**5.** (10 Batch | L-3/T-1, 2012-2013 | Date: 19/03/2012 | Q.4d)
Now let's suppose that you would like to extend the functionality of Facebook group by adding the possibility that besides normal users **a group page can also be a member of another group**. As an example it should be possible that the group page of "CSE BUET 08" joins the "BUETIANS" group. As a consequence all the members of "CSE BUET 08" group become automatically members of "BUETIANS" group. Which design pattern is most appropriate to accommodate this change? **Show a complete class diagram(s) and enough code fragments to illustrate your use of the pattern.** *(12⅔ marks)*

---

## 🌲 11. COMPOSITE PATTERN

**1.** (18 Batch | L-3/T-1, 2020-2021 | Date: 19/10/2022 | Q.3a)
You are to implement the **hierarchy of the employees** of the company. An employee may be under a boss and he or she might have one or more subordinates. The level of hierarchy is not fixed, and it varies any time. You can add a subordinate employee under an employee or you can remove an already included subordinate employee in the hierarchy. The employees listed in the subordinate list is considered as **direct subordinate**. The subordinate of subordinates is called **indirect subordinate**. The list of all subordinates (direct or indirect up to leaf) with detailed information will be available through a method of the class representing an employee. **Show necessary implementation of the classes using appropriate design patterns.** *(15 marks)*

---

**2.** (09 Batch | L-3/T-1, 2011-2012 | Date: 04/09/2021 | Q.2a)
A company is headed by a Managing Director. There are three divisions: **Technical, Administration and Finance**. Each of these divisions is headed by a Manager. The Technical Division consists of **five Developers** under the supervision of the Technical manager. The Administration is run by **three executives** under the supervision of the Admin Manager. There are **two officers** under Finance Manager. **You are to implement the hierarchy of the employees using composite pattern.** The composite class must have the provision to show all the employees under any employee. Write all the classes for demonstrating this hierarchy of employees. *(20 marks)*

---

**3.** (20 Batch | L-3/T-1, 2022-2023 | Date: 05/05/2024 | Q.4b)
Suppose we are designing an **Accounting Software**. We have a class named `Account` to represent the accounting heads in the chart of accounts. In each transaction one account is debited and at the same time another account is credited. The transaction is made from a user account authenticated using **two-step authentication process (password, OTP)**. There are classes called `Debtor` and `Creditor` which stores the information which account is debited and which account is credited. **An account may have children. The account that does not have any child is called leaf account. An account that has any transaction associated with it cannot be deleted. Also an account which has child cannot be deleted. Design a class diagram to implement the scenario.** *(12 marks)*

---

**4.** (11 Batch | L-3/T-1, 2013-2014 | Date: 23/09/2013 | Q.1a)
Discuss the different **implementation issues and consequences of Composite Pattern**. *(14 marks)*

---

**5.** (10 Batch | L-3/T-1, 2012-2013 | Date: 19/03/2012 | Q.4c-d)
In principle a social network service focuses on building online communities. Facebook support groups that people can join. Each group has a title, administrative members, a group type (open/closed), and a list of related groups. If somebody writes on the wall page of the group, the information is broadcasted to all the members and it is visualized in the news feeds of the members. *(Observer portion — Q.4c)*

Now let's suppose that you would like to extend the functionality by adding the possibility that **a group page can also be a member of another group**. As an example it should be possible that the group page of "CSE BUET 08" joins the "BUETIANS" group. As a consequence all the members of "CSE BUET 08" group become automatically members of "BUETIANS" group. Which design pattern is most appropriate? **Show a complete class diagram(s) and enough code fragments.** *(12⅔ marks)*

---

## 🔌 12. ADAPTER PATTERN

**1.** (20 Batch | L-3/T-1, 2022-2023 | Date: 05/05/2024 | Q.1a)
You have a service which returns the **temperature (in celsius)** by passing **city name** as an input value. Now, assume that your client wants to pass **zipcode** as input and expecting the temperature of the city in return. **Develop a class diagram to present appropriate design pattern and write necessary codes so that your code fulfills all the requirements.** *(15 marks)*

---

**2.** (21 Batch | L-2/T-2, 2023-2024 | Date: 09/02/2025 | Q.5b)
Illustrate how a **single class can serve as both an Adapter and a Facade** with an example scenario. Design a class diagram to represent the scenario and analyze the functionality of the class in fulfilling the dual role. *(12 marks)*

---

**3.** (16 Batch | L-3/T-1, 2018-2019 | Date: 06/11/2019 | Q.4b)
Suppose you have a `Bird` class with `fly()` and `makeSound()` methods. And also a `ToyDuck` class with `squeak()` method. Let's assume that you are **short on ToyDuck objects** and you would like to **use Bird objects in their place**. Birds have some similar functionality but implement a different interface, so we can't use them directly. **Draw a class diagram to present Adapter design pattern for the scenario above and write necessary codes so that your code fulfills all the requirements.** *(18 marks)*

---

**4.** (10 Batch | L-3/T-1, 2012-2013 | Date: 19/03/2012 | Q.4e)
Suppose Alice told you the following story:
*"At the company for which I work we are facing this problem: We have a large amount of application software written using a particular library. Let's call this library **LibX**. The provider of this library was XIndustries AB. We wanted to extend the functionality of our application and for this reason we tried to contact XIndustries AB to implement the necessary library functionality. To our surprise we found out that XIndustries AB has gone out of business. Fortunately we found out that there is another company called YEnterprise AB is producing **LibY** that provides the same functionality as LibX but many of the classes have **different interfaces**. We don't have access to the source code of the old library LibX and neither to the source code of LibY. What should we do?"*
**Which design pattern is most appropriate to accommodate this change? In particular, show an appropriate class diagram to solve the problem.** *(7 marks)*

---

**5.** (17 Batch | L-3/T-1, 2019-2020 | Date: 19/10/2022 | Q.5d)
Draw the **UML class diagram of "Class Adapter Pattern"**. Write down the **pros and cons of Object Adapter Pattern and Class Adapter Pattern.** *(3+3⅔ = 6⅔ marks)*

---

**6.** (19 Batch | L-3/T-1, 2021-2022 | Date: 07/05/2023 | Q.2a)
Let's assume you are building your own **computer networking model** with five layers. When user wants to send message "hello", it passes through all layers with each layer adding headers/trailers (same Decorator/Adapter question listed above). **Identify the design pattern that can best capture the scenario above and implement it.** *(20 marks)*

---

## 🌉 13. BRIDGE PATTERN

**1.** (19 Batch | L-3/T-1, 2021-2022 | Date: 07/05/2023 | Q.1a)
Differentiate the use cases of **Factory Method Pattern, Abstract Factory Pattern, Builder Pattern and Bridge Pattern** with necessary examples and/or figures. *(16 marks)*

---

**2.** (17 Batch | L-3/T-1, 2019-2020 | Date: 19/10/2022 | Q.4a-iii)
*(Same BanglaPhone question — Bridge Pattern is the expected answer)*
You work in a telecommunication company named *BanglaPhone*. BanglaPhone has **two different implementations** for their mobile communication. Your company wants to switch between the implementations without hampering any other code segments based on the current number of users under a specific cell tower. *(Identify the most specific pattern — Part of 20 marks)*

---

**3.** (14 Batch | L-3/T-1, 2016-2017 | Date: 15/07/2017 | Q.8d)
Which class design principle does the following code violate? *(GraphicEditor with Shape, Rectangle, Circle classes using m_type integer flag instead of polymorphism)*. **Re-write the code to remove the violation of the principle.** *(6⅔ marks)*
*(Bridge/OCP principle question)*

---

> ✅ **That's every question extracted from every page of every paper — organized pattern by pattern.**
>
> **Most repeated patterns (study these first):**
> 1. **Observer** — appears in almost every exam (blog, dashboard, stock market)
> 2. **Composite** — employee hierarchy appears repeatedly
> 3. **Strategy** — sorting routines / ride sharing appear repeatedly
> 4. **Adapter** — temperature/zipcode, Bird/ToyDuck appear repeatedly
> 5. **Builder** — HTMLPageBuilder, student form appear repeatedly
> 6. **Singleton** — lazy vs eager initialization asked almost every year
