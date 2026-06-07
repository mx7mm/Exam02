# Code Explanation: Custom String Printing Function (ft_putstr)

This C program defines a custom function called `ft_putstr`. Its sole purpose is to take a string (a sequence of characters) as an input and print it directly to the terminal screen character by character. It mimics the behavior of standard functions like `printf` or `puts`, but operates at a much lower, more efficient level.

---

## Code Overview

```c
#include "unistd.h"

void ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
```

---

## Line-by-Line Breakdown

### 1. Including the Library
```c
#include "unistd.h"
```
This line includes the header required for the `write()` system call. Using quotation marks (`"unistd.h"`) tells the compiler to search for the header file in the local directory first, before looking into the standard system libraries (unlike using `<unistd.h>`).

### 2. Function Declaration
```c
void ft_putstr(char *str)
{
```
*   `void`: Specifies the return type. This function does its job (printing text) and returns nothing back to the caller.
*   `ft_putstr`: The custom name of the function (commonly used in projects like the 42 School piscine).
*   `char *str`: The parameter. It accepts a pointer to a character, which in C represents the starting memory address of a string.

### 3. The Loop Condition (The Pointer Trick)
```c
while (*str)
```
In C, strings always end with a special hidden character called the null-terminator (`'\0'`), which has a numerical value of `0`. 
*   `*str` means "look at the actual character inside the memory address that `str` is currently pointing to".
*   In C, any value that is **not zero** is considered `true`, and `0` is considered `false`.
*   Therefore, `while (*str)` keeps running as long as the current character is a valid letter, number, or space. The moment it hits the end of the string (`'\0'`), the loop evaluates to `false` and stops.

### 4. Printing and Advancing
```c
write(1, str++, 1);
```
This single line performs three actions simultaneously:
1.  **Print:** It uses `write(1, str, 1)` to send exactly `1` byte from the current memory location to Standard Output (`1`), which is your terminal screen.
2.  **Advance:** The `++` operator is placed *after* the variable (`str++`). This is a post-increment. It means the function uses the current address for `write()` first, and right after that, it shifts the pointer `str` forward by one position to point to the next character in memory.
3.  **Repeat:** The loop jumps back to the condition to check the next character.

---

## Step-by-Step Execution Example

Imagine your main function calls `ft_putstr("Go");`. In memory, this string looks like this: `['G', 'o', '\0']`.

1.  `str` initially points to the address of `'G'`.
2.  **First Iteration:**
    *   Condition check: `*str` is `'G'`. This is not `0` (true), so the loop enters.
    *   `write()` prints `'G'` to the screen.
    *   `str++` moves the pointer to the next character `'o'`.
3.  **Second Iteration:**
    *   Condition check: `*str` is `'o'`. This is not `0` (true), so the loop continues.
    *   `write()` prints `'o'` to the screen.
    *   `str++` moves the pointer to the final character `'\0'`.
4.  **Third Iteration:**
    *   Condition check: `*str` is `'\0'`, which equals `0` (false).
    *   The loop terminates immediately.
5.  **Final Screen Output:** `Go`
