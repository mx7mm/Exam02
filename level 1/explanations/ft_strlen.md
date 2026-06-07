# Code Explanation: Custom String Length Function (ft_strlen)

This C function defines a custom version of the standard library function (`strlen`). Its sole purpose is to calculate and return the exact number of characters in a given string (`str`), excluding the hidden terminating null character (`'\0'`).

---

## Code Overview

```c
#include <unistd.h>

size_t ft_strlen(char *str)
{
	size_t i;
	i = 0;

	while(str[i])
		i++;
	return i;
}
```

---

## Line-by-Line Breakdown

### 1. Including the Library
```c
#include <unistd.h>
```
This header file is included here, though it is not strictly required for the logic inside this specific function (since no system calls like `write()` are used). However, it is standard practice to keep it if this function is part of a larger file or toolkit that interacts with system operations.

### 2. Function Declaration and Return Type
```c
size_t ft_strlen(char *str)
{
```
*   `size_t`: The return type. This is an unsigned integer type defined by the system. It is specifically designed to represent sizes and counts in memory. Because a string cannot have a negative length, using an unsigned type like `size_t` is the safest and most efficient choice.
*   `ft_strlen`: The custom name of the function.
*   `char *str`: The parameter. It accepts a pointer to the first character of the string we want to measure.

### 3. Initializing the Counter
```c
size_t i;
i = 0;
```
A variable `i` of type `size_t` is declared and initialized to `0`. It serves two purposes simultaneously: it acts as the index to look at each character, and it acts as the counter for the total length.

### 4. The Counting Loop
```c
while(str[i])
    i++;
```
This `while` loop checks the character at the current index `str[i]`. In C, strings always end with a null-terminator (`'\0'`), which has a value of `0`.
*   As long as `str[i]` is any valid character (not `0`), the condition evaluates to `true`.
*   `i++;`: The counter increments by 1, and the loop moves on to check the next index position.
*   The moment the loop hits the null-terminator (`str[i] == '\0'`), the condition becomes `false`, and the loop stops immediately.

### 5. Returning the Result
```c
return i;
```
Once the loop terminates, the variable `i` holds the exact number of characters passed before reaching the end. The function returns this value to the caller.

---

## Step-by-Step Execution Example

Imagine your program passes the string `"42"` to the function: `ft_strlen("42");`

1.  `i` starts at 0.
2.  **First Iteration:**
    *   `str[0]` is `'4'` (true).
    *   `i` increments to 1.
3.  **Second Iteration:**
    *   `str[1]` is `'2'` (true).
    *   `i` increments to 2.
4.  **Loop Termination:**
    *   `str[2]` is `'\0'` (false). The loop exits.
5.  The function returns `i`, which is **`2`**.
