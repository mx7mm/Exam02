# Code Explanation: ROT13 Cipher (Alphabet Rotation by 13 Places)

This C program processes a single string passed as a command-line argument and encrypts it using the classic **ROT13** algorithm. ROT13 is a simple substitution cipher that rotates every letter by 13 positions forward in the alphabet. Because the Latin alphabet has 26 letters, applying ROT13 twice restores the original text, making it its own inverse. Non-alphabetic characters remain untouched.

---

## Code Overview

```c
#include <unistd.h>

int main(int argc, char **argv)
{
	char *str;

	if (argc == 2)
	{
		str = argv;
		while (*str)
		{
			if ((*str >= 'A' && *str <= 'Z'))
				*str = (*str - 'A' + 13) % 26 + 'A';
			else if (*str >= 'a' && *str <= 'z')
				*str = (*str - 'a' + 13) % 26 + 'a';
			write(1, str++, 1);
		}
	}
	return (write(1, "\n", 1), 0);
}
```

---

## Line-by-Line Breakdown

### 1. Pointer Initialization
```c
if (argc == 2)
{
	str = argv;
```
If exactly one text argument is provided (`argc == 2`), the program points the `str` pointer to the beginning of that input string (`argv`).

### 2. Main Processing Loop
```c
while (*str)
{
```
This loop iterates through the entire string character by character. It evaluates to `true` as long as `*str` points to a valid character, and stops automatically when it hits the terminating null character (`'\0'`).

### 3. Encrypting Uppercase Letters (The Modulo Math Trick)
```c
if ((*str >= 'A' && *str <= 'Z'))
    *str = (*str - 'A' + 13) % 26 + 'A';
```
If the current character is an uppercase letter, the program applies a mathematical wrap-around formula to shift it safely:
*   `*str - 'A'`: Converts the character's ASCII value into a number from `0` to `25` (e.g., `'A'` becomes `0`, `'Z'` becomes `25`).
*   `+ 13`: Adds 13 to shift it forward by 13 steps.
*   `% 26`: The modulo operator handles the overflow. If the value reaches or exceeds 26, it wraps back around to the beginning of the alphabet (e.g., position 25 + 13 = 38. `38 % 26 = 12`).
*   `+ 'A'`: Converts the 0-25 rank back into its actual ASCII uppercase character code.
*   `*str = ...`: The modified character overwrites the original character in memory.

### 4. Encrypting Lowercase Letters
```c
else if (*str >= 'a' && *str <= 'z')
    *str = (*str - 'a' + 13) % 26 + 'a';
```
This line does the exact same calculation, but uses `'a'` as the baseline to handle lowercase characters between 'a' and 'z' flawlessly.

### 5. Printing and Advancing
```c
write(1, str++, 1);
```
This line handles the output and pointer movement:
*   `write(1, str, 1)` prints the freshly calculated character to Standard Output (`1`). If the character wasn't a letter (like a number or space), it skips the `if` blocks and gets printed exactly as it was.
*   `str++` increments the pointer address, shifting focus to the next character for the next iteration.

### 6. The Compact Return (The Comma Operator Trick)
```c
return (write(1, "\n", 1), 0);
```
This is a very condensed, clever way to finish the program using C's comma operator:
*   First, it executes `write(1, "\n", 1)` to output a clean newline.
*   Then, it evaluates the final expression after the comma, which is `0`.
*   The function returns `0` to the operating system, signaling successful execution.

---

## Step-by-Step Execution Example

Imagine running the program with the word `"An3"`: `./program "An3"`

1.  `str` starts pointing at `'A'`.
2.  **Character 1: `'A'`**
    *   `'A'` is uppercase $\rightarrow$ `('A' - 'A' + 13) % 26 + 'A'` $\rightarrow$ `(0 + 13) % 26 + 'A'` $\rightarrow$ `13 + 'A'` $\rightarrow$ Becomes **`'N'`**.
    *   Prints `'N'`, pointer moves to `'n'`.
3.  **Character 2: `'n'`**
    *   `'n'` is lowercase $\rightarrow$ `('n' - 'a' + 13) % 26 + 'a'` $\rightarrow$ `(13 + 13) % 26 + 'a'` $\rightarrow$ `26 % 26 + 'a'` $\rightarrow$ `0 + 'a'` $\rightarrow$ Becomes **`'a'`** (wrapped around!).
    *   Prints `'a'`, pointer moves to `'3'`.
4.  **Character 3: `'3'`**
    *   It is not a letter. It skips all transformations.
    *   Prints **`'3'`**, pointer hits `'\0'` and the loop stops.
5.  **Final Output:** `Na3`
