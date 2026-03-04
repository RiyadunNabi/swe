Based on the problem description in `Online_A.pdf`, you need to multiply two large numbers by treating their digits as coefficients of polynomials. The multiplication of two polynomials is equivalent to their **linear convolution**.

By the Convolution Theorem, linear convolution can be computed efficiently by taking the Discrete Fourier Transform (via FFT), multiplying the spectra pointwise, and then taking the Inverse Fast Fourier Transform (IFFT).

To do this properly without circular wrap-around artifacts, we must **zero-pad** the digit arrays to a length of at least $N + M - 1$ (and ideally to the next power of 2 for the FFT to run in $\mathcal{O}(N \log N)$ time).

Here is the complete solution building upon your `online.py` starter code:

```python
import numpy as np

def fft(x):
    """
    Compute 1D FFT using Radix-2 algorithm.
    """
    x = np.asarray(x, dtype=np.complex128)
    N = len(x)
    if N <= 1:
        return x
    
    # Radix-2 DIT FFT
    even = fft(x[0::2])
    odd = fft(x[1::2])
    
    factor = np.exp(-2j * np.pi * np.arange(N // 2) / N)
    
    return np.concatenate([even + factor * odd, even - factor * odd])

def ifft(X):
    """
    Compute 1D IFFT using the FFT function.
    IFFT(X) = 1/N * conj(FFT(conj(X)))
    """
    X = np.asarray(X, dtype=np.complex128)
    N = len(X)
    
    X_conj = np.conj(X)
    x = fft(X_conj)
    x = np.conj(x) / N
    
    return x

def multiply_large_numbers(x_val, y_val):
    # 1. Break the alien numbers into "digit pieces"
    x_digits = [int(digit) for digit in str(x_val)]
    y_digits = [int(digit) for digit in str(y_val)]
    
    N = len(x_digits)
    M = len(y_digits)
    
    # The linear convolution length will be N + M - 1
    # We pad to the next power of 2 to utilize Radix-2 FFT efficiently
    conv_length = N + M - 1
    next_pow2 = 1 << (conv_length - 1).bit_length()
    
    # 2. Pad the arrays with zeros
    x_padded = np.pad(x_digits, (0, next_pow2 - N), 'constant')
    y_padded = np.pad(y_digits, (0, next_pow2 - M), 'constant')
    
    # 3. Apply FFT to transform to frequency domain
    X_freq = fft(x_padded)
    Y_freq = fft(y_padded)
    
    # 4. Multiply in frequency domain (Convolution Theorem)
    Z_freq = X_freq * Y_freq
    
    # 5. Apply IFFT to return to time domain
    z_time = ifft(Z_freq)
    
    # Round to nearest integer to eliminate floating point inaccuracies
    convolution_result = np.round(np.real(z_time)).astype(int)
    
    # 6. Process Carry-Overs
    result_digits = []
    carry = 0
    
    # We iterate from the rightmost part of our relevant convolution length (conv_length - 1) down to 0
    for i in range(conv_length - 1, -1, -1):
        total = convolution_result[i] + carry
        result_digits.append(total % 10)  # Keep the last digit
        carry = total // 10               # Carry over the rest
        
    # If there's any remaining carry, prepend it
    while carry > 0:
        result_digits.append(carry % 10)
        carry //= 10
        
    # Because we processed from right to left, the list is backwards. Reverse it.
    result_digits.reverse()
    
    # Handle leading zeros if input was 0
    while len(result_digits) > 1 and result_digits[0] == 0:
        result_digits.pop(0)
        
    final_result_str = ''.join(map(str, result_digits))
    return int(final_result_str)

if __name__ == "__main__":
    # Example usage from problem description
    x = 123
    y = 456
    
    print(f"Multiplying:\n  {x}\n* {y}")
    print("-" * 20)
    
    alien_answer = multiply_large_numbers(x, y)
    print(f"Result using FFT : {alien_answer}")
    print(f"Standard Python  : {x * y}")
    
    print("\n" + "="*30 + "\n")
    
    # Test case from online.py
    x2 = 33
    y2 = 444
    print(f"Multiplying:\n  {x2}\n* {y2}")
    print("-" * 20)
    
    alien_answer2 = multiply_large_numbers(x2, y2)
    print(f"Result using FFT : {alien_answer2}")
    print(f"Standard Python  : {x2 * y2}")

```


---
Based on the problem description in `Online_B.pdf` (The BUET Logo Heist), we need to reverse the circular convolution applied by the "alien".

According to the Circular Convolution property of the Discrete Fourier Transform:


$$DFT(x[n] \circledast h[n]) = X(k) \cdot H(k)$$

Therefore, to decrypt the image, we must perform **Deconvolution** in the frequency domain. We do this by taking the FFT of an encrypted row, dividing it by the FFT of the "key row", and then taking the Inverse FFT (IFFT) to get the original pixels back.

Here is the complete solution using an $O(N \log N)$ custom Radix-2 FFT algorithm, built upon your `online.py` starter code.

Save this as `2105XXX.py` (replacing with your student ID).

```python
import numpy as np
import matplotlib.pyplot as plt
from PIL import Image

# =====================================================
# 1. Custom FFT and IFFT Implementation
# =====================================================
def fft(x):
    """
    Compute 1D FFT using Radix-2 Decimation-in-Time (DIT) algorithm.
    Pads to the next power of 2 if necessary to ensure O(N log N) performance.
    """
    x = np.asarray(x, dtype=np.complex128)
    N = len(x)
    
    if N <= 1:
        return x
    
    # Pad to next power of 2 if N is not a power of 2
    if (N & (N - 1)) != 0:
        next_pow2 = 1 << (N - 1).bit_length()
        x = np.pad(x, (0, next_pow2 - N), 'constant')
        N = next_pow2
        
    even = fft(x[0::2])
    odd = fft(x[1::2])
    
    # Twiddle factors
    factor = np.exp(-2j * np.pi * np.arange(N // 2) / N)
    
    return np.concatenate([even + factor * odd, even - factor * odd])

def ifft(X):
    """
    Compute 1D inverse FFT using the FFT function based on the property:
    IFFT(X) = 1/N * conj(FFT(conj(X)))
    """
    X = np.asarray(X, dtype=np.complex128)
    N = len(X)
    
    X_conj = np.conj(X)
    x = fft(X_conj)
    x = np.conj(x) / N
    
    return x

# =====================================================
# 2. Main Execution and Decryption
# =====================================================
if __name__ == "__main__":
    # Load the encrypted image
    try:
        image = Image.open("encrypted_image.tiff")
        encrypted_image = np.array(image)
    except FileNotFoundError:
        print("Error: 'encrypted_image.tiff' not found in the current directory.")
        exit()

    rows, cols = encrypted_image.shape
    print(f"Image loaded. Size: {rows}x{cols}")

    # 1. Identify the key row
    # The clue says: "find the index of the smallest value of any column of the image."
    # We look at the first column (index 0) and find the row with the minimum value.
    key_row_idx = np.argmin(encrypted_image[:, 0])
    print(f"Detected Key Row Index: {key_row_idx}")

    # Extract the key row
    key_row = encrypted_image[key_row_idx, :]

    # 2. Compute the FFT of the Key Row
    Key_freq = fft(key_row)
    
    # Add a tiny epsilon to avoid division by zero during deconvolution
    epsilon = 1e-12 
    Key_freq_safe = Key_freq + epsilon 

    # Prepare an empty array for the decrypted image
    decrypted_image = np.zeros_like(encrypted_image, dtype=np.float64)

    print("Decrypting image rows...")
    # 3. Decrypt the BUET logo row by row
    for i in range(rows):
        if i == key_row_idx:
            # The key row itself was left unencrypted
            decrypted_image[i, :] = key_row
        else:
            # Get the encrypted row
            enc_row = encrypted_image[i, :]
            
            # Transform to frequency domain
            Enc_freq = fft(enc_row)
            
            # Deconvolution: Division in the frequency domain
            Dec_freq = Enc_freq / Key_freq_safe
            
            # Inverse FFT to get back to the spatial/time domain
            dec_row = np.real(ifft(Dec_freq))
            
            # If FFT padded the array, we slice it back to original column size
            decrypted_image[i, :] = dec_row[:cols]

    # 4. Post-process the image
    # Pixel values should be integers between 0 and 255
    decrypted_image = np.clip(np.round(decrypted_image), 0, 255).astype(np.uint8)
    print("Decryption complete!")

    # =====================================================
    # 3. Visualization
    # =====================================================
    plt.figure(figsize=(10, 5))

    # Encrypted image
    plt.subplot(1, 2, 1)
    plt.imshow(encrypted_image, cmap='gray')
    plt.title("Encrypted Image\n(Maximus's Work)")
    plt.axis('off')

    # Decrypted image
    plt.subplot(1, 2, 2)
    plt.imshow(decrypted_image, cmap='gray')
    plt.title("Decrypted Image\n(Restored BUET Logo)")
    plt.axis('off')

    plt.tight_layout()
    plt.show()

```

---
Based on the scenario and hints provided in `Online_C.pdf`, here is the complete solution to solve "The Mystery of the Shifting Coordinates."

### How to "Select the Row and Column Wisely"

When an image is shifted both horizontally and vertically, comparing an arbitrary row in the original image to the *same* row index in the shifted image might fail because they represent different parts of the scene.

To solve this, we can **programmatically test every row** and find the one that yields the highest cross-correlation peak. A strong peak indicates that the visual features in that row span vertically (like a straight edge), allowing it to match well despite the vertical offset. We apply the same logic to the columns to find the vertical shift!

Here is the complete implementation for your `2105XXX.py` file:

```python
import numpy as np
import matplotlib.pyplot as plt

# =====================================================
# 1. Custom FFT and IFFT Implementation
# =====================================================
def fft(x):
    """
    Compute 1D FFT using Radix-2 Decimation-in-Time algorithm.
    Pads to the next power of 2 if necessary to ensure O(N log N) performance.
    """
    x = np.asarray(x, dtype=np.complex128)
    N = len(x)
    
    if N <= 1:
        return x
    
    # Pad to next power of 2 if N is not a power of 2
    if (N & (N - 1)) != 0:
        next_pow2 = 1 << (N - 1).bit_length()
        x = np.pad(x, (0, next_pow2 - N), 'constant')
        N = next_pow2
        
    even = fft(x[0::2])
    odd = fft(x[1::2])
    
    # Twiddle factors
    factor = np.exp(-2j * np.pi * np.arange(N // 2) / N)
    
    return np.concatenate([even + factor * odd, even - factor * odd])

def ifft(X):
    """
    Compute 1D inverse FFT using the FFT function based on the property:
    IFFT(X) = 1/N * conj(FFT(conj(X)))
    """
    X = np.asarray(X, dtype=np.complex128)
    N = len(X)
    
    X_conj = np.conj(X)
    x = fft(X_conj)
    x = np.conj(x) / N
    
    return x

# =====================================================
# 2. Shift Detection using Cross-Correlation
# =====================================================
def compute_1d_shift(x, y):
    """
    Calculates the shift between two 1D signals using DFT-based cross-correlation.
    Returns the estimated shift amount and the peak correlation value.
    """
    X_freq = fft(x)
    Y_freq = fft(y)
    
    # Cross-power spectrum: conj(X) * Y
    cross_spec = np.conj(X_freq) * Y_freq
    
    # Inverse FFT to get cross-correlation
    cross_corr = ifft(cross_spec)
    cross_corr_real = np.real(cross_corr)
    
    N = len(cross_corr_real)
    peak_idx = np.argmax(cross_corr_real)
    peak_val = cross_corr_real[peak_idx]
    
    # Resolve circular shift direction
    if peak_idx > N // 2:
        shift = peak_idx - N
    else:
        shift = peak_idx
        
    return shift, peak_val

# =====================================================
# 3. Main Execution
# =====================================================
if __name__ == "__main__":
    # Load images (Change filenames if necessary)
    try:
        image = plt.imread("image.png")
        shifted_image = plt.imread("shifted_image.png")
    except FileNotFoundError:
        print("Error: Could not find 'image.png' or 'shifted_image.png'.")
        exit()

    # Convert to grayscale for correlation analysis if they are RGB/RGBA
    def to_grayscale(img):
        if len(img.shape) == 3:
            return np.mean(img[..., :3], axis=2)
        return img

    orig_gray = to_grayscale(image)
    shift_gray = to_grayscale(shifted_image)

    rows, cols = orig_gray.shape
    print(f"Image loaded. Size: {rows}x{cols}")

    # --- Step 1: Find Horizontal Shift (Select Row Wisely) ---
    max_h_corr = -1
    best_h_shift = 0
    best_row_idx = 0
    
    for r in range(rows):
        shift, peak_val = compute_1d_shift(orig_gray[r, :], shift_gray[r, :])
        # We select the row that gives the absolute maximum correlation peak
        if peak_val > max_h_corr:
            max_h_corr = peak_val
            best_h_shift = shift
            best_row_idx = r

    # --- Step 2: Find Vertical Shift (Select Column Wisely) ---
    max_v_corr = -1
    best_v_shift = 0
    best_col_idx = 0
    
    for c in range(cols):
        shift, peak_val = compute_1d_shift(orig_gray[:, c], shift_gray[:, c])
        # We select the column that gives the absolute maximum correlation peak
        if peak_val > max_v_corr:
            max_v_corr = peak_val
            best_v_shift = shift
            best_col_idx = c

    print(f"\nDetection Results:")
    print(f"-> Horizontal Shift: {best_h_shift} pixels (Detected using best row: {best_row_idx})")
    print(f"-> Vertical Shift:   {best_v_shift} pixels (Detected using best col: {best_col_idx})")

    # --- Step 3: Realign the Image ---
    # Reversing the shifts using numpy.roll (direct shifting without DFT)
    reversed_shifted_image = np.roll(shifted_image, shift=(-best_v_shift, -best_h_shift), axis=(0, 1))

    # --- Step 4: Visualization ---
    plt.figure(figsize=(15, 5))

    plt.subplot(1, 3, 1)
    plt.imshow(image, cmap='gray')
    plt.title("Original Satellite Image")
    plt.axis('off')

    plt.subplot(1, 3, 2)
    plt.imshow(shifted_image, cmap='gray')
    plt.title(f"Shifted Image\n(H: {best_h_shift}, V: {best_v_shift})")
    plt.axis('off')

    plt.subplot(1, 3, 3)
    plt.imshow(reversed_shifted_image, cmap='gray')
    plt.title("Realigned (Reversed) Image")
    plt.axis('off')

    plt.tight_layout()
    plt.show()

```
