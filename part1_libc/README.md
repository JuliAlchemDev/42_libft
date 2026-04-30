# Part 1 - libc functions
## Description
This project consists of recreating a set of standard C library functions
from scratch, grouped by functionality. The goal is to understand how these
functions work internally and build a reusable library for future 42 projects.

Beyond the implementation, the project includes a dedicated test suite in
`main.c` that compares each custom function against its original libc
counterpart — covering both base and edge cases. A Makefile ties everything
together, making compilation and testing a single command.

## Block 1 - Character Classification Functions

### Functions
ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, ft_isprint

### Tricky edge cases
- Values > 127: not ASCII, return 0
- Negative values: same
- EOF (-1): must handle without crashing

### What I learned

- *Why int instead of char?*

- *What is unsigned and when to use it with char?*

- *What is EOF?*

- *What is octal and why does the ASCII table have multiple representations?*

- *Why can't we pass NULL to these functions?*


## Block 2 - Type Conversion
### Functions
ft_toupper, ft_tolower, ft_atoi
### Tricky edge cases
### What I learned

## Block 3 - String Operations
### Functions
ft_strlen, ft_strlcpy, ft_strlcat, ft_strncmp,
ft_strchr, ft_strrchr, ft_strnstr, ft_strdup

## Block 4 - Memory Manipulation
### Functions
ft_memset, ft_bzero, ft_memcpy, ft_memmove,
ft_memchr, ft_memcmp

## Block 5 - Memory Allocation
### Functions
ft_calloc


## Workflow
*28/04 - Planning + Base Architecture + Character Classification Functions*

1. Broke down the project into tasks and set up Jira to track progress.
2. Defined the base project structure and workflow.
3. Implemented Block 1 functions with their description from the man page,
   in order to define the workflow and deepen the understanding of Part 1.

*29/04: Refactor + Architecture + Testing*
1. Defined the structure and workflow for **Part 1 — libc standard functions**:
```
libc/
├── srcs/
│   ├── ft_isalpha.c
│   ├── ft_isdigit.c
│   └── ...
├── objs/
│   ├── ft_isalpha.o
│   ├── ft_isdigit.o
│   └── ...
├── main.c
├── test
└── Makefile
```
2. Wrote a **Makefile** to compile the project and run the custom function tests.
3. Prepared **main.c** to verify that custom functions replicate the behaviour of their libc counterparts — implemented a check() function and wrote tests covering both base and edge cases.
4. Styled the test output using ANSI escape codes for colors and font formatting, making results easier to read at a glance. 
5. Refactored tests for Character Classification Functions by introducing test_base, test_edge, get_random, and an edge_cases array to improve reusability and reduce code duplication.

