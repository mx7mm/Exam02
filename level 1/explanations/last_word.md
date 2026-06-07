# Code Explanation: Extract the First Word of a String

This C program filters and prints the **first word** from a given string. It automatically skips any leading spaces or tabs and outputs just the first continuous sequence of characters.

---

## Code Overview

```c
#include <unistd.h>

int main(int argc, char **argv)
{
	int i;

	i = 0;

	if (argc == 2)
	{
		while (argv[1][i] == ' ' || argv[1][i] == '\t') 			
			i++;
		while (argv[1][i] != '\0' && argv[1][i] != ' ' && argv[1][i] != '\t')
			write(1, &argv[1][i++], 1);
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
This header gives access to the POSIX operating system API. In this specific program, it is required solely to use the system call `write()`.

### 2. The Main Function Entry Point
```c
int main(int argc, char **argv)
```
*   `argc` (Argument Count): An integer representing the number of arguments passed via the terminal (including the program name itself).
*   `argv` (Argument Vector): An array of strings containing the arguments.
    *   `argv[0]` is the program name (e.g., `./program`).
    *   `argv[1]` is the first actual text string you pass to the program.

### 3. Initializing the Counter
```c
int i;
i = 0;
```
An integer variable `i` is declared and initialized to `0`. It acts as an index pointer to move through the string character by character.

### 4. Input Validation
```c
if (argc == 2)
{
```
This checks if **exactly one** argument was passed to the program. Since the program name counts as the first argument, `argc` must equal `2`. If you pass no arguments or too many arguments, the program skips the logic entirely and safely exits.

### 5. First Loop: Skipping Spaces and Tabs
```c
while (argv[1][i] == ' ' || argv[1][i] == '\t') 			
    i++;
```
This `while` loop checks the character at the current index `i`. If it is a regular space (`' '`) or a horizontal tab (`'\t'`), the index `i` increments by 1 (`i++`). This effectively "jumps over" all leading whitespace until it hits the first actual letter.

### 6. Second Loop: Printing the Word
```c
while (argv[1][i] != '\0' && argv[1][i] != ' ' && argv[1][i] != '\t')
    write(1, &argv[1][i++], 1);
```
This loop runs as long as the current character is **not** the end of the string (`'\0'`), **not** a space, and **not** a tab. 

Inside the loop, the `write()` system call outputs the text directly to the screen:
*   `1`: Specifies the file descriptor for **Standard Output** (the terminal screen).
*   `&argv[1][i++]`: Passes the memory address of the current character to print, and *then* increments `i` by 1 to move to the next position.
*   `1`: Instructs the system to print exactly `1` byte (one character).

The loop terminates the moment it hits a space, tab, or the null-terminator.

### 7. Newline and Clean Exit
```c
}
write(1, "\n", 1);
return 0;
```
*   `write(1, "\n", 1);`: Prints a newline character. This executes regardless of whether the `if` block ran, ensuring your terminal prompt starts on a clean new line when the program finishes.
*   `return 0;`: Returns an exit status of 0 to the operating system, signaling that the program executed successfully.

---

## Step-by-Step Execution Example

If you run the program in your terminal using: `./program "   Hi"`

1.  `argc` is 2, so the program enters the `if` block.
2.  `i` starts at 0.
3.  **First Loop:**
    *   `argv[1][0]` is `' '` $\rightarrow$ `i` becomes 1.
    *   `argv[1][1]` is `' '` $\rightarrow$ `i` becomes 2.
    *   `argv[1][2]` is `' '` $\rightarrow$ `i` becomes 3.
    *   `argv[1][3]` is `'H'` $\rightarrow$ Loop stops.
4.  **Second Loop:**
    *   `argv[1][3]` is `'H'` $\rightarrow$ Prints `'H'`, `i` becomes 4.
    *   `argv[1][4]` is `'i'` $\rightarrow$ Prints `'i'`, `i` becomes 5.
    *   `argv[1][5]` is `'\0'` $\rightarrow$ Loop stops.
5.  A newline (`\n`) is printed, and the program exits.
6.  **Final Output:** `Hi`
