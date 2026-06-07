# Code Explanation: Custom String Copy Function (ft_strcpy)

This C function defines a custom version of the standard string copy library function (`strcpy`). Its purpose is to duplicate the contents of a source string (`s2`) into a destination string buffer (`s1`). It performs the copy operation character by character, ensuring that the final copied string is correctly structured in memory.

---

## Code Overview

```c
char *ft_strcpy(char *s1, char *s2)
{
	int i;

	i = 0;

	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
```

---

## Line-by-Line Breakdown

### 1. Function Declaration
```c
char *ft_strcpy(char *s1, char *s2)
{
```
*   `char *`: The function returns a pointer to a character, which is the starting address of the copied string (`s1`).
*   `ft_strcpy`: The custom name of the function.
*   `char *s1`: The first parameter. It points to the destination memory buffer where the text will be copied *into*.
*   `char *s2`: The second parameter. It points to the source string that will be read *from*.

### 2. Initializing the Index Counter
```c
int i;
i = 0;
```
An integer variable `i` is declared and set to `0`. This variable serves as an index pointer to access specific character positions in both strings at the exact same time.

### 3. The Copy Loop
```c
while (s2[i])
{
    s1[i] = s2[i];
    i++;
}
```
This loop runs as long as the character inside the source string at index `i` is not the hidden null-terminator (`'\0'`). In C, `s2[i]` acts as a truth value; when it hits the end of the string (value `0`), the loop stops.
*   `s1[i] = s2[i];`: Copies the character from the source string directly into the destination string at the same position.
*   `i++;`: Increments the index by 1 to move to the next character for the next loop iteration.

### 4. Appending the Null-Terminator
```c
s1[i] = '\0';
```
When the loop finishes, all visible characters have been copied, but the critical ending marker is still missing. This line manually places the null-terminator (`'\0'`) at the very end of the destination string (`s1[i]`). Without this, other functions like `printf` or `ft_putstr` would not know where the string ends, causing memory bugs.

### 5. Returning the Destination Pointer
```c
return (s1);
```
The function returns the original pointer to the destination string (`s1`). This allows for function chaining, meaning you can pass the result of `ft_strcpy` directly into another function (for example: `ft_putstr(ft_strcpy(dest, src));`).

---

## Step-by-Step Execution Example

Imagine `s2` contains `"Hi"` and `s1` is an empty memory buffer large enough to hold it.

1.  `i` starts at 0.
2.  **First Iteration:**
    *   `s2[0]` is `'H'`, which is true.
    *   `s1[0]` becomes `'H'`.
    *   `i` increments to 1.
3.  **Second Iteration:**
    *   `s2[1]` is `'i'`, which is true.
    *   `s1[1]` becomes `'i'`.
    *   `i` increments to 2.
4.  **Loop Termination:**
    *   `s2[2]` is `'\0'`, which evaluates to false. The loop stops.
5.  **Finalizing:**
    *   `s1[2]` is explicitly set to `'\0'`.
6.  The function returns the pointer to `s1`, which now contains the independent string `"Hi"`.
