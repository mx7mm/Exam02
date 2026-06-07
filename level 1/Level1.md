# Technical Reference Manual: Exam Rank 02 — Level 1 Core Curriculum

This repository serves as a production-grade academic blueprint and comprehensive technical engineering guide for mastering Level 1 of the 42 School Exam Rank 02 syllabus. It details programmatic strategies, memory protection methodologies, and systemic edge-case patterns required to achieve an absolute 100/100 score under the strict conditions of the automated grading system (Moulinette).

---

## Core Technical Competencies

Successful verification requires flawless execution of fundamental low-level principles, with particular emphasis on preventing memory access violations (`Segmentation Faults`):

* **Multidimensional Pointer Navigation:** Safe parsing of command-line arrays (`argv`) using conditional bounds checking to guarantee isolation from unallocated stack sectors.
* **ASCII Value Engineering:** Optimization of logic architectures based on character byte sequences (e.g., `'A' = 65`, `'a' = 97`), capitalizing on the continuous `32`-byte offset for localized type conversions.
* **Predictable Control Flows:** Strict implementation of explicit `if` / `else if` deterministic paths to entirely eliminate undefined logical execution or overlapping instruction states.
* **Tokenization Mechanics:** Systematic detection and filtering of structural layout elements, such as space blocks (`' '`) and horizontal delimiters (`'\t'`), for character grouping and parsing.

---

## Syllabus & Architectural Matrix



| Module Identifier | Compilation Type | Execution Specification | Core Algorithmic Focus |
| :--- | :--- | :--- | :--- |
| **`fizzbuzz`** | Standalone Binary | Sequential evaluation of integers `1` through `100` mapping specific mathematical conditions to string stream outputs. | Numeric modulo decomposition (`/ 10`, `% 10`) for localized output generation. Enforces strict compliance by using low-level kernel streams (`write`). |
| **`first_word`** | Standalone Binary | Isolation and streaming of the primary word sequence within a continuous character stream. | **Forward-skipping logic:** Pointer advancement bypassing leading whitespace tokens with real-time word boundary termination. |
| **`last_word`** | Standalone Binary | Detection, isolation, and output generation of the terminal word within a string stream. | **Reverse-navigation parsing:** String tail tracking via explicit length calculation, backward whitespace truncation, and base-index anchoring. |
| **`rev_print`** | Standalone Binary | Direct byte-order reversal of a command-line parameter array via standard output. | **String tail evaluation:** Traversal to the null terminator followed by controlled reverse iteration loops utilizing negative pointer offsets (`i--`). |
| **`rotone`** | Standalone Binary | Shift-cipher mutation advancing all alphabetical bytes by exactly `+1` structural position while maintaining structural casing. | **Overflow boundaries:** Implementation of explicit wrapping exceptions to safely loop boundary bytes (`z` / `Z`) back to their origins (`a` / `A`). |
| **`rot_13`** | Standalone Binary | Implementation of the symmetric ROT13 cipher, executing a half-alphabet rotation (`+13` / `-13`). | **Midpoint split-logic:** Bisecting alphabetic boundaries (`m` / `M`) to isolate addition phases from subtraction phases, eliminating byte overflows. |
| **`ulstr`** | Standalone Binary | Universal case inversion across alphabetical characters. All non-alphabetical bytes must remain fully immutable. | **Offset mathematics:** Boundary restriction logic isolating specific ASCII zones to apply deterministic arithmetic adjustments via the `32`-byte constant. |
| **`repeat_alpha`** | Standalone Binary | Dynamic amplification of individual bytes based on their one-indexed alphabetical ranking position. | **Nested sequence loops:** Run-time calculation of internal iterator depth through relative ASCII distance formulas (`character - base_offset + 1`). |
| **`search_and_replace`** | Standalone Binary | Target-byte scanning within a multi-byte array, executing immediate atomic replacements. | **Strict argument constraints:** Mandatory verification layers validating exactly `argc == 4` prior to performing down-stream pointer operations. |
| **`ft_strlen`** | Isolated Function | Run-time evaluation and reporting of string memory dimensions (`int`). | **Null-terminator detection:** Linear sequential scanning loops optimized to halt precisely upon reaching the terminal `\0` marker. |
| **`ft_strcpy`** | Isolated Function | Block memory replication transferring byte sequences from a source origin to a destination array buffer. | **Buffer stabilization:** Explicit terminal assignment appending the vital `\0` null byte directly to the destination array structure post-transfer. |
| **`ft_swap`** | Isolated Function | In-place memory value translation between two independent stack storage regions. | **Pass-by-reference mechanics:** Manipulation of pointer addresses (`*a`, `*b`) paired with a primitive temporary variable to handle resource swapping safely. |
| **`ft_putstr`** | Isolated Function | Character-stream writing targeting standard output via low-level kernel routines. | **System call optimization:** Sequential text routing driven by pointer-based address reads executing `write(1, &str[i], 1)`. |

---

## Evaluation Architecture and Execution Constraints

### The Standalone Program Interface
All standalone binary applications must be written defensively. If the incoming parameter matrix array does not align perfectly with the target specification criteria (invalid `argc`), the application layer must gracefully default to issuing a clean single newline character (`\n`) and terminate execution with exit status code `0`.

### The Pure Function Interface
Source files utilizing the `ft_` namespace function as isolated modular elements within larger frameworks. **Do not embed a local `main` execution routine** within the final submitted artifact. All validation layers must be handled separately or fully stripped prior to compilation tracking.

### Mandatory Compilation Parameters
Local compilation routines must enforce absolute type enforcement and logical validation by incorporating strict diagnostic flags:

```bash
gcc -Wall -Wextra -Werror <source_file>.c -o <binary_output>
```

---

## Technical Verification Framework

To diagnose data pipelines, handle trailing spatial elements, and detect invisible anomalies, execute all local verification routines in conjunction with a visual delimiter extension (`cat -e`):

```bash
# Executing complex structural whitespace evaluation
./last_word "  consecutive string block  " | cat -e

# Expected System Return Structure:
block\$
```
