# Code Explanation: Extract the Last Word of a String

This C program processes a single string passed as a command-line argument and prints its **very last word**. Instead of starting from the beginning, the program moves a pointer all the way to the end of the string and then backtracks to isolate the final word.

---

## Code Overview

```c
#include <unistd.h>

int main(int argc, char **argv)
{
	char *str;

	if (argc == 2)
	{
		str = argv[1];
		while (*str)
			str++;
		while (str > argv[1] && *(str - 1) != ' ' && *(str - 1) != '\t')
			str--;
		while(*str)
			write(1, str++, 1);
	}
	write(1, "\n", 1);
	return 0;
}
```

---

## Line-by-Line Breakdown

### 1. Including the Library
```c
#include <unistd.h>
```
This header file allows the use of the `write()` system call, which is used here to print the characters directly to the terminal.

### 2. Guarding the Input
```c
if (argc == 2)
{
	str = argv[1];
```
Just like the first program, this condition checks if **exactly one** argument was passed via the terminal (`argc == 2`). If true, the character pointer `str` is initialized to point to the very first character of that input string (`argv[1]`).

### 3. First Loop: Moving to the End
```c
while (*str)
	str++;
```
This loop runs as long as the character `str` points to is not the null-terminator (`'\0'`).
*   `str++`: Advances the memory pointer forward by one character.
*   When this loop finishes, `str` points exactly to the hidden `'\0'` marker at the end of the entire string.

### 4. Second Loop: Backtracking to the Word's Start
```c
while (str > argv[1] && *(str - 1) != ' ' && *(str - 1) != '\t')
	str--;
```
This loop moves the pointer **backward** to find where the last word begins. It checks the character *just before* the current position (`*(str - 1)`). It keeps moving backward (`str--`) as long as two conditions are met:
1.  `str > argv[1]`: The pointer has not backed up all the way to the very beginning of the string.
2.  `*(str - 1) != ' ' && *(str - 1) != '\t'`: The previous character is **not** a space and **not** a tab.

The loop stops the exact moment it hits a space, a tab, or the beginning of the string. This means `str` is now pointing to the first letter of the last word.

### 5. Third Loop: Printing the Last Word
```c
while(*str)
	write(1, str++, 1);
```
Now that `str` is perfectly positioned at the start of the last word, this final loop prints it character by character until it hits the end of the string (`'\0'`). 

### 6. Clean Exit
```c
}
write(1, "\n", 1);
return 0;
```
A newline character (`\n`) is printed to keep the terminal output clean, and the program exits successfully.

---

## Step-by-Step Execution Example

Imagine running the program with: `./program "Hello World"`

1.  `argc` is 2. `str` starts at `'H'`.
2.  **First Loop:** `str` advances all the way through "Hello World" and stops at the `'\0'` right after the `'d'`.
3.  **Second Loop (Backtracking):**
    *   Looks at `*(str - 1)` $\rightarrow$ It is `'d'` (not a space). Pointer moves back before `'d'`.
    *   Looks at `*(str - 1)` $\rightarrow$ It is `'l'` (not a space). Pointer moves back before `'l'`.
    *   *(This repeats for 'r', 'o', 'W')*
    *   Finally, looks at `*(str - 1)` $\rightarrow$ It hits the space `' '` between "Hello" and "World".
    *   The loop stops! `str` is now pointing directly at the **`'W'`**.
4.  **Third Loop:** Prints `'W'`, `'o'`, `'r'`, `'l'`, `'d'` one by one.
5.  **Final Output:** `World`
