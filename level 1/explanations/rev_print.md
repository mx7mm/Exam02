# Code Explanation: Reverse a String (String Mirroring)

This C program processes a single string passed as a command-line argument and prints it to the terminal completely **in reverse**. It achieves this by first scanning forward to find the total length of the string and then tracking backward, printing each character from the end to the beginning.

---

## Code Overview

```c
#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;

	if (argc == 2)
	{
		while (argv[1][i])
			i++;
		while (--i >= 0)
			write(1, &argv[1][i], 1);
	}
	write(1, "\n", 1);
	return (0);
}
```

---

## Line-by-Line Breakdown

### 1. Guarding the Input
```c
if (argc == 2)
{
```
This check ensures the program only runs if **exactly one** string argument is passed to it from the terminal. If no argument or too many arguments are provided, it skips the core logic and exits safely.

### 2. First Loop: Counting to the End
```c
while (argv[1][i])
	i++;
```
This loop counts how many characters are inside the input string (`argv[1]`). 
*   `i` starts at 0.
*   The loop checks each character one by one. It increments `i` by 1 (`i++`) as long as it hasn't reached the null-terminator (`'\0'`).
*   When this loop finishes, `i` holds the exact length of the string and points directly to the hidden `'\0'` character at the very end.

### 3. Second Loop: Printing Backwards
```c
while (--i >= 0)
	write(1, &argv[1][i], 1);
```
This loop is responsible for reversing the output. It works by stepping backward through the index positions:
*   `--i`: This prefix decrement instantly lowers the value of `i` by 1 **before** looking at the character. This is crucial because if a string has a length of 4 (indices 0, 1, 2, 3), `i` was 4 after the first loop. Decrementing it first changes `i` to 3, which is the actual index of the very last visible character.
*   `write(1, &argv[1][i], 1);`: Sends the character at the current index position `i` directly to the standard output (`1`), which is the terminal screen.
*   The loop continues backwards (`i` goes down to 2, then 1, then 0) until `i` becomes `-1`. At that point, the condition `i >= 0` becomes false, and the loop stops.

### 4. Newline and Return
```c
}
write(1, "\n", 1);
return (0);
```
*   `write(1, "\n", 1);`: Outputs a single newline character. This ensures that the terminal prompt stays clean and organized after the execution, regardless of whether a string was actually reversed or not.
*   `return (0);`: Informs the operating system that the program executed and finished successfully without any issues.

---

## Step-by-Step Execution Example

Imagine running the program in your terminal with: `./program "C42"`

1.  `argc` is 2. `i` starts at 0.
2.  **First Loop (Counting):**
    *   `argv[1][0]` is `'C'` $\rightarrow$ `i` becomes 1.
    *   `argv[1][1]` is `'4'` $\rightarrow$ `i` becomes 2.
    *   `argv[1][2]` is `'2'` $\rightarrow$ `i` becomes 3.
    *   `argv[1][3]` is `'\0'` $\rightarrow$ Loop stops. `i` remains **3**.
3.  **Second Loop (Printing Backwards):**
    *   `--i` changes `i` from 3 to **2**. `argv[1][2]` is `'2'`. Prints **`2`**.
    *   `--i` changes `i` from 2 to **1**. `argv[1][1]` is `'4'`. Prints **`4`**.
    *   `--i` changes `i` from 1 to **0**. `argv[1][0]` is `'C'`. Prints **`C`**.
    *   `--i` changes `i` from 0 to **-1**. Condition `-1 >= 0` is false. Loop stops.
4.  A newline (`\n`) is printed.
5.  **Final Output:** `24C`
