# Code Explanation: Case Inversion Utility (swap_case Variant)

This C program processes a single string passed as a command-line argument and inverts the case of every letter. It converts lowercase letters into uppercase letters and uppercase letters into lowercase letters. Non-alphabetic characters, such as numbers, spaces, or symbols, are completely ignored and printed exactly as they are.

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
			if (argv[i] >= 'a' && argv[i] <= 'z')
				argv[i] -= 32;
			else if (argv[i] >= 'A' && argv[i] <= 'Z')
				argv[i] += 32;
			write(1, &argv[i++], 1);
		}
	}
	return (write(1, "\n", 1), 0);
}
```

---

## Line-by-Line Breakdown

### 1. The Core Loop
```c
if (argc == 2)
{
	while (argv[i])
	{
```
If exactly one text argument is provided (`argc == 2`), the program enters the `while` loop, checking characters one by one starting from index `i = 0`. The loop continues until it reaches the hidden null-terminator character (`'\0'`).

### 2. Converting Lowercase to Uppercase
```c
if (argv[i] >= 'a' && argv[i] <= 'z')
    argv[i] -= 32;
```
If the current character is a lowercase letter between 'a' and 'z', the program subtracts `32` from its numerical value. 
*   **The ASCII Trick:** In the ASCII table, the difference between any lowercase letter and its uppercase equivalent is exactly 32. For example, `'a'` has a value of 97, and `'A'` has a value of 65 ($97 - 32 = 65$). Subtracting 32 instantly shifts the character to uppercase.

### 3. Converting Uppercase to Lowercase
```c
else if (argv[i] >= 'A' && argv[i] <= 'Z')
    argv[i] += 32;
```
If the current character is an uppercase letter between 'A' and 'Z', the program does the exact opposite: it adds `32` to the value. This shifts an uppercase letter down into its lowercase version (e.g., `'B'` is 66, $66 + 32 = 98$, which is `'b'`).

### 4. Output and Iteration Step
```c
write(1, &argv[i++], 1);
```
*   `write(1, &argv[i], 1)` sends the modified character (or the untouched character if it was a space or digit) straight to Standard Output (`1`), printing it to the terminal.
*   `i++`: The post-increment adds 1 to the index `i` immediately after sending the character's memory address, ensuring the loop advances to the next position.

### 5. Final Line Break and Compact Return
```c
return (write(1, "\n", 1), 0);
```
Just like the previous encryption scripts, this line uses C's comma operator:
*   First, it prints a clean newline (`\n`).
*   Then, it delivers the value `0` as the return code for the `main` function, signaling to the operating system that the execution was successful.

---

## Step-by-Step Execution Example

Imagine running the program with the input string `"42 Cb!"`: `./program "42 Cb!"`

1.  `i` starts at 0.
2.  **Indices 0 & 1 (`'4'`, `'2'`):** Skipped by all `if` blocks. Printed exactly as **`42`**.
3.  **Index 2 (`' '`):** A space character. Skipped by all `if` blocks. Printed as **` `**.
4.  **Index 3 (`'C'`):** It is an uppercase letter $\rightarrow$ `66 + 32 = 98` $\rightarrow$ Overwritten with **`'b'`**. Printed.
5.  **Index 4 (`'b'`):** It is a lowercase letter $\rightarrow$ `98 - 32 = 66` $\rightarrow$ Overwritten with **`'C'`**. Printed.
6.  **Index 5 (`'!'`):** Skipped by all `if` blocks. Printed as **`!`**.
7.  Index 6 is `'\0'`. The loop terminates.
8.  **Final Output:** `42 bC!`
