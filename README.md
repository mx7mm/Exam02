# 42 Exam Rank 02 - Common Core

This repository contains structured solutions, algorithms, and cheat sheets to prepare for the Exam Rank 02 in the Common Core of the 42 school curriculum.

---

## The Exam at a Glance

* **Duration:** 3 or 4 hours (depending on campus guidelines).
* **Goal:** Reach exactly 100/100 points.
* **Passing Requirement:** You must complete all 4 levels flawlessly in consecutive order.
* **The Grading System (Moulinette):** Every submission is automated and tested against hundreds of hidden test cases. A single incorrect character (e.g., an extra trailing space) results in 0 points for that attempt.

### The Fail System
After every failed attempt, the Examshell locks you out for a specific amount of time. Use this penalty time for local debugging instead of rushing into a panic restart.
* **1st Fail:** approx. 5–10 minutes lockout
* **2nd Fail:** approx. 15–20 minutes lockout
* *The waiting time nearly doubles with almost every subsequent failure.*

---

## Tasks Roadmap by Levels

### Level 1: String Basics & Simple Logic
* **fizzbuzz**: Counts from 1 to 100. Replaces multiples of 3 with "fizz", 5 with "buzz", and both with "fizzbuzz".
* **first_word**: Displays the very first word of a given string (ignores leading whitespaces).
* **last_word**: Displays the very last word of a given string (ignores trailing whitespaces).
* **rev_print**: Outputs a given string completely in reverse order.
* **rotone**: Shifts every letter by 1 position forward in alphabetical order ('z' becomes 'a').
* **rot_13**: Shifts every letter by 13 positions forward (rotates half the alphabet).
* **ulstr**: Inverts the casing of all letters in a string.
* **repeat_alpha**: Outputs each letter as many times as its position in the alphabet indicates ('c' = 3 times).
* **search_and_replace**: Replaces all occurrences of a specific character with another one inside a string.
* **ft_strlen / ft_putstr**: Custom implementations for measuring string length and outputting text.
* **ft_strcpy / ft_swap**: Copying strings or swapping the values of two integer pointers.

### Level 2: Pointers, Bits & Mathematical Logic
* **ft_atoi**: Converts a character string into a real integer value.
* **ft_strcmp / ft_strdup**: Comparing strings or duplicating them dynamically in memory.
* **max**: Finds the largest value in an integer array.
* **is_power_of_2**: Checks if a given number is a power of 2.
* **print_bits / reverse_bits / swap_bits**: Data manipulation directly on a bitwise level.
* **inter / union**: Finding intersections or unique characters between two separate strings.

### Level 3: Dynamic Memory & Higher Algorithms
* **ft_range / ft_rrange**: Allocates dynamic memory (malloc) and fills an array with a sequence of numbers.
* **add_prime_sum**: Calculates the sum of all prime numbers up to a given number.
* **pgcd / lcm**: Calculates the greatest common divisor or the least common multiple of two numbers.
* **ft_atoi_base**: Extends atoi to convert numbers from various numeral systems (e.g., Hexadecimal).
* **epur_str / expand_str**: Cleans strings from consecutive or unnecessary spaces and tabs.

### Level 4: Advanced Algorithms & Structures
* **ft_split**: Splits a long string into an array of sub-strings using delimiters (Most important exercise).
* **flood_fill**: Recursive area-checking algorithm (similar to the bucket fill tool in paint programs).
* **fprime**: Decomposes a number into its prime factors and prints them.
* **sort_list / ft_list_remove_if**: Sorts or filters elements within a singly linked list.

---

## Essential Terminal Commands during the Exam

### 1. Strict Compiling (42 Flags)
Every single piece of code must be compiled with the three strict flags locally. Any warning will be treated as an error by the compiler:
```bash
gcc -Wall -Wextra -Werror name_of_the_task.c -o test_program
```

### 2. Checking for Invisible Characters
Always piping your execution into `cat -e` allows you to detect unauthorized trailing spaces or missing newlines ('\n'):
```bash
./test_program "Argument" | cat -e
```

### 3. The Correct Submission Workflow
1. Navigate into the `rendu/` directory.
2. Create a folder with the exact name of the assigned task: `mkdir name_of_the_task`
3. Place your matching `.c` file inside that new folder.
4. Execute the git sequence:
```bash
git add name_of_the_task.c
git commit -m "Submit"
git push
```
5. Only type `grademe` in the Examshell prompt after a successful git push.

---

## Golden Rules for Passing

1. **Test edge cases manually:** Always try running your binary with *no arguments*, *too many arguments*, *empty strings*, or *strings containing only whitespaces* (`"   "`) before submitting.
2. **Understand Program vs. Function:**
   * If the subject states **"Write a program..."**, you must submit a complete file including `int main(int argc, char **argv)`.
   * If it states **"Write a function..."**, submit only the isolated function code. Including a main function here will break the automated compilation step, scoring you 0 points.
3. **Keep it simple:** Do not write overly optimized or complex code. Simple, highly readable code is less prone to careless mistakes under exam stress.
