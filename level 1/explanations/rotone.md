# Code Explanation: Caesar Cipher Variant (1-Place Alphabet Rotation)

This C program processes a single string passed as a command-line argument and shifts every letter forward by exactly **one position** in the alphabet. It uses a mathematical wrap-around format, so a 'Z' wraps around to become an 'A', and a 'z' becomes an 'a'. Non-alphabetic characters (like spaces, digits, or symbols) are printed exactly as they are.

---

## Code Overview

```c
#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;

	if (argc == 2)
	{
		while (argv[i])
		{
			if (argv[i] >= 'A' && argv[i] <= 'Z')
				argv[i] = (argv[i] - 'A' + 1) % 26 + 'A';
			else if (argv[i] >= 'a' && argv[i] <= 'z')
				argv[i] = (argv[i] - 'a' + 1) % 26 + 'a';
			
			write(1, &argv[i++], 1);
		}
	}
	return (write(1, "\n", 1), 0);
}
```

---

## Line-by-Line Breakdown

### 1. Loop Setup
```c
if (argc == 2)
{
	while (argv[i])
	{
```
If exactly one string argument is passed (`argc == 2`), the `while` loop begins reading the string `argv` starting from index `i = 0`. The loop continues character by character until it encounters the terminating null character (`'\0'`).

### 2. Shifting Uppercase Letters
```c
if (argv[i] >= 'A' && argv[i] <= 'Z')
    argv[i] = (argv[i] - 'A' + 1) % 26 + 'A';
```
If the current character is an uppercase letter, the program applies ASCII math to advance it safely:
*   `argv[i] - 'A'`: Converts the character into a number between `0` and `25` (e.g., `'A'` becomes `0`, `'Z'` becomes `25`).
*   `+ 1`: Shifts the position forward by 1 step.
*   `% 26`: The modulo operator creates a safe loop. If the calculation reaches 26 (which happens when shifting `'Z'`: `25 + 1 = 26`), `26 % 26` results in `0`. This wraps the character back to the beginning of the alphabet.
*   `+ 'A'`: Converts the resulting 0-25 integer back into its valid ASCII code.
*   `argv[i] = ...`: Modifies the character directly inside the original argument string.

### 3. Shifting Lowercase Letters
```c
else if (argv[i] >= 'a' && argv[i] <= 'z')
    argv[i] = (argv[i] - 'a' + 1) % 26 + 'a';
```
This performs the exact same mechanical shift but establishes `'a'` as the baseline, ensuring that lowercase letters between 'a' and 'z' are processed independently.

### 4. Direct Printing and Index Increment
```c
write(1, &argv[i++], 1);
```
This line handles the output stream and progress counter together:
*   `write(1, &argv[i], 1)` pushes the character byte to Standard Output (`1`), showing it on the terminal screen. If the character was a number or space, it skipped the modification blocks and is printed instantly without changes.
*   `i++`: The post-increment adds 1 to the counter `i` *after* the current character address is read, seamlessly preparing the loop for the next character.

### 5. Line Break and Clean Exit
```c
return (write(1, "\n", 1), 0);
```
Using the C comma operator, the program performs two consecutive tasks as it ends:
*   First, it executes `write(1, "\n", 1)` to print a final newline character, keeping the terminal line alignment clean.
*   Then, it passes the value `0` out of the statement, returning a standard success exit code to the operating system.

---

## Step-by-Step Execution Example

Imagine running the program with the input word `"Z5a"`: `./program "Z5a"`

1.  `i` starts at 0.
2.  **Character 1: `'Z'` (index 0)**
    *   `'Z'` is an uppercase letter $\rightarrow$ `('Z' - 'A' + 1) % 26 + 'A'` $\rightarrow$ `(25 + 1) % 26 + 'A'` $\rightarrow$ `26 % 26 + 'A'` $\rightarrow$ `0 + 'A'` $\rightarrow$ Becomes **`'A'`**.
    *   Prints `'A'`, and `i` increments to 1.
3.  **Character 2: `'5'` (index 1)**
    *   It is a number, so it skips the character transformations completely.
    *   Prints **`'5'`**, and `i` increments to 2.
4.  **Character 3: `'a'` (index 2)**
    *   `'a'` is a lowercase letter $\rightarrow$ `('a' - 'a' + 1) % 26 + 'a'` $\rightarrow$ `(0 + 1) % 26 + 'a'` $\rightarrow$ `1 % 26 + 'a'` $\rightarrow$ `1 + 'a'` $\rightarrow$ Becomes **`'b'`**.
    *   Prints `'b'`, and `i` increments to 3.
5.  Index 3 is `'\0'`. The loop terminates.
6.  **Final Output:** `A5b`
