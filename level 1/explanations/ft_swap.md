# Code Explanation: Custom Value Swapping Function (ft_swap)

This C function defines a custom utility called `ft_swap`. Its purpose is to take two memory addresses pointing to integer variables and swap their values. Because it uses pointers, the values of the original variables are modified directly outside the function's local scope.

---

## Code Overview

```c
void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
```

---

## Line-by-Line Breakdown

### 1. Function Declaration
```c
void	ft_swap(int *a, int *b)
{
```
*   `void`: The return type. This function directly alters memory and does not return any value back to the caller.
*   `ft_swap`: The custom name of the function.
*   `int *a`: The first parameter. It is a pointer to an integer, meaning it holds the memory address of the first number.
*   `int *b`: The second parameter. It is a pointer to an integer, holding the memory address of the second number.

### 2. Declaring a Temporary Variable
```c
int temp;
```
An integer variable named `temp` is declared. This acts as a temporary storage space. Just like swapping liquids between two cups, you need a third empty cup to hold one liquid temporarily so you don't overwrite it.

### 3. Storing the First Value
```c
temp = *a;
```
The `*` symbol before `a` is the dereference operator. It means "look inside the memory address `a` and get the actual value stored there". This line copies that value into our safe storage variable `temp`.

### 4. Overwriting the First Value
```c
*a = *b;
```
This line reads the value stored at the memory address `b` and writes it directly into the memory address `a`. Now, both addresses hold the second value, but the first value is still safely saved inside `temp`.

### 5. Finalizing the Swap
```c
*b = temp;
```
Finally, the program takes the original first value saved in `temp` and writes it into the memory address `b`. The swap is now complete.

---

## Step-by-Step Execution Example

Imagine you have two variables in your main program: `int x = 42;` and `int y = 21;`.  
You call the function using their memory addresses: `ft_swap(&x, &y);`

1.  Inside the function, `a` points to `x` and `b` points to `y`.
2.  `temp = *a;` $\rightarrow$ `temp` becomes **`42`**.
3.  `*a = *b;` $\rightarrow$ The value at address `a` (`x`) changes from 42 to **`21`**.
4.  `*b = temp;` $\rightarrow$ The value at address `b` (`y`) changes from 21 to **`42`**.
5.  The function ends. Back in your main program, `x` is now `21` and `y` is now `42`.
