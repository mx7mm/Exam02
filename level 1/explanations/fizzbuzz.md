# Code Explanation: Custom FizzBuzz Implementation

This C program is a custom implementation of the classic **FizzBuzz** problem. It counts from 1 to 100 and applies specific rules for numbers divisible by 3 and 5. Instead of using standard heavy functions like `printf`, it uses the low-level `write` function to print characters and numbers directly.

---

## Code Overview

```c
#include <unistd.h>

int main(void)
{
	int i;

	i = 0;
	while(++i <= 100)
	{
		if(i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if(i % 3 == 0)
			write(1, "fizz", 4);
		else if(i % 5 == 0)
			write(1, "buzz", 4);
		else
		{
			if(i >= 10)
				write(1, &"0123456789"[i / 10], 1);
			write(1, &"0123456789"[i % 10], 1);
		}
		write(1, "\n", 1);
	}
	return 0;
}
```

---

## Line-by-Line Breakdown

### 1. Including the Library
```c
#include <unistd.h>
```
This header is required to use the system call `write()`. It bypasses the standard C library buffer and sends text directly to the terminal.

### 2. The Main Function Entry Point
```c
int main(void)
```
The program starts here. The word `void` inside the parentheses explicitly states that this program does not accept any command-line arguments.

### 3. Initializing the Counter
```c
int i;
i = 0;
```
An integer variable `i` is created to keep track of the count. It is initialized to `0`.

### 4. The Loop Condition
```c
while(++i <= 100)
```
This loop runs until the counter reaches 100. 
*   `++i`: The prefix increment adds 1 to `i` **before** the condition is checked. On the very first run, `i` becomes `1`.
*   `<= 100`: The loop body will execute for every value of `i` from 1 up to and including 100.

### 5. Rule 1: Divisible by Both 3 and 5 (FizzBuzz)
```c
if(i % 3 == 0 && i % 5 == 0)
    write(1, "fizzbuzz", 8);
```
*   The `%` (modulo) operator calculates the remainder of a division. If `i % 3 == 0`, the number is perfectly divisible by 3.
*   If a number is divisible by both 3 and 5 (like 15, 30, or 45), the program writes the 8-byte string `"fizzbuzz"` to Standard Output (`1`).

### 6. Rule 2: Divisible Only by 3 (Fizz)
```c
else if(i % 3 == 0)
    write(1, "fizz", 4);
```
If the first condition is false, but the number is divisible by 3 (like 3, 6, or 9), it writes the 4-byte string `"fizz"`.

### 7. Rule 3: Divisible Only by 5 (Buzz)
```c
else if(i % 5 == 0)
    write(1, "buzz", 4);
```
If the previous conditions are false, but the number is divisible by 5 (like 5, 10, or 20), it writes the 4-byte string `"buzz"`.

### 8. Rule 4: Handling Regular Numbers (The Clever Part)
```c
else
{
    if(i >= 10)
        write(1, &"0123456789"[i / 10], 1);
    write(1, &"0123456789"[i % 10], 1);
}
```
If the number is not divisible by 3 or 5, the program must print the number itself. Since `write()` can only print characters (text), the code uses a clever trick with a string literal lookup `"0123456789"`:

*   **Tens Digit:** `if(i >= 10)` checks if the number has two digits. If it does, `i / 10` extracts the tens place (e.g., `42 / 10 = 4`). `"0123456789"[4]` points to the character `'4'`, and `write()` prints it.
*   **Ones Digit:** `i % 10` extracts the remainder, which is the ones place (e.g., `42 % 10 = 2`). `"0123456789"[2]` points to the character `'2'`, and `write()` prints it.

### 9. Newline and Return
```c
    write(1, "\n", 1);
}
return 0;
```
*   `write(1, "\n", 1);`: At the end of every loop iteration, a newline character is printed to move to the next line.
*   `return 0;`: Signalizes to the operating system that the program ran successfully from 1 to 100.

---

## Step-by-Step Execution Example

Here is how the program handles three different specific numbers during its execution:

### Case 1: `i = 3`
*   `3 % 3 == 0` is true, but `3 % 5 == 0` is false.
*   Moving to the first `else if`: `3 % 3 == 0` is true.
*   **Output:** `fizz`

### Case 2: `i = 15`
*   `15 % 3 == 0` is true AND `15 % 5 == 0` is true.
*   The first `if` statement triggers immediately.
*   **Output:** `fizzbuzz`

### Case 3: `i = 42`
*   Not divisible by 3 and 5 simultaneously (`42 % 5 != 0`).
*   Not divisible by 3 alone or 5 alone in the rules (Note: 42 is divisible by 3, so it would actually print `fizz`. Let's look at **`i = 41`** instead for a clean number example).

### Case 4: `i = 41`
*   All `if` and `else if` checks fail. The program enters the final `else` block.
*   `41 >= 10` is true $\rightarrow$ Tens digit: `41 / 10 = 4` $\rightarrow$ Prints `'4'`.
*   Ones digit: `41 % 10 = 1` $\rightarrow$ Prints `'1'`.
*   **Output:** `41`
