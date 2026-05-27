

*This project has been created as part of the 42 curriculum by iualkhim*

## Description
This project is the first of many at 42 Barcelona. It consists of recreating a set of standard C library functions from scratch, divided into 3 parts:

- **Part 1** - Libc standard functions, grouped in 5 blocks by functionality.
- **Part 2** - Additional functions not present in libc or with a different approach.
- **Part 3** - Linked list manipulation functions.

The goal is to understand how these functions work internally and build a
reusable library for future 42 projects.

## Instructions

### Compilation
```bash
make          # Compile the library → libft.a
make clean    # Remove object files
make fclean   # Remove object files and libft.a
make re       # Recompile from scratch
```

### Linking in your project
```c
#include "libft.h"
```

## Library Reference

### Part 1 — Libc Standard Functions
- *Character Classification*
---
| Function | Description | Prototype |
|---|---|---|
| [ft_isalpha](./ft_isalpha.c) | Returns non-zero if `c` is alphabetic (a–z, A–Z) | `int ft_isalpha(int c);` |
| [ft_isdigit](./ft_isdigit.c) | Returns non-zero if `c` is a decimal digit (0–9) | `int ft_isdigit(int c);` |
| [ft_isalnum](./ft_isalnum.c) | Returns non-zero if `c` is alphanumeric | `int ft_isalnum(int c);` |
| [ft_isascii](./ft_isascii.c) | Returns non-zero if `c` is a valid ASCII character (0–127) | `int ft_isascii(int c);` |
| [ft_isprint](./ft_isprint.c) | Returns non-zero if `c` is a printable character | `int ft_isprint(int c);` |
---
- *Type Conversion*
---
| Function | Description | Prototype |
|---|---|---|
| [ft_toupper](./ft_toupper.c) | Converts a lowercase letter to uppercase | `int ft_toupper(int c);` |
| [ft_tolower](./ft_tolower.c) | Converts an uppercase letter to lowercase | `int ft_tolower(int c);` |
| [ft_atoi](./ft_atoi.c) | Converts a string to an integer | `int ft_atoi(const char *str);` |
---
- *String Operations*
---
| Function | Description | Prototype |
|---|---|---|
| [ft_strlen](./ft_strlen.c) | Returns the length of a string | `size_t ft_strlen(const char *s);` |
| [ft_strlcpy](./ft_strlcpy.c) | Copies up to `size - 1` chars from `src` to `dst`, NUL-terminating | `size_t ft_strlcpy(char *dst, const char *src, size_t size);` |
| [ft_strlcat](./ft_strlcat.c) | Appends `src` to `dst` up to `size - 1` chars | `size_t ft_strlcat(char *dst, const char *src, size_t size);` |
| [ft_strncmp](./ft_strncmp.c) | Compares up to `n` characters of two strings | `int ft_strncmp(const char *str_1, const char *str_2, size_t n);` |
| [ft_strchr](./ft_strchr.c) | Returns a pointer to the first occurrence of `c` in `str` | `char *ft_strchr(const char *str, int c);` |
| [ft_strrchr](./ft_strrchr.c) | Returns a pointer to the last occurrence of `c` in `str` | `char *ft_strrchr(const char *src, int c);` |
| [ft_strnstr](./ft_strnstr.c) | Locates `needle` in `haystack`, searching at most `len` characters. Returns `haystack` if `needle` is empty. | `char *ft_strnstr(const char *haystack, const char *needle, size_t len);` |
| [ft_strdup](./ft_strdup.c) | Allocates and returns a duplicate of `s` | `char *ft_strdup(const char *s);` |
---
- *Memory Manipulation*
---
| Function | Description | Prototype |
|---|---|---|
| [ft_memset](./ft_memset.c) | Fills `n` bytes of `s` with constant byte `c` | `void *ft_memset(void *s, int c, size_t n);` |
| [ft_bzero](./ft_bzero.c) | Sets `n` bytes of `s` to zero | `void ft_bzero(void *s, size_t n);` |
| [ft_memcpy](./ft_memcpy.c) | Copies `n` bytes from `src` to `dst` (no overlap) | `void *ft_memcpy(void *dest, const void *src, size_t n);` |
| [ft_memmove](./ft_memmove.c) | Copies `n` bytes from `src` to `dst`, handling overlap safely | `void *ft_memmove(void *dest, const void *src, size_t n);` |
| [ft_memchr](./ft_memchr.c) | Searches for byte `c` in the first `n` bytes of `s` | `void *ft_memchr(const void *s, int c, size_t n);` |
| [ft_memcmp](./ft_memcmp.c) | Compares the first `n` bytes of `s1` and `s2` | `int ft_memcmp(const void *s1, const void *s2, size_t n);` |
---
- *Memory Allocation*
---
| Function | Description | Prototype |
|---|---|---|
| [ft_calloc](./ft_calloc.c) | Allocates `count * size` bytes, zero-initialized | `void *ft_calloc(size_t count, size_t size);` |

---

### Part 2 — Additional functions not present in libc or with a different approach.
- *String Manipulation*
---
| Function | Description | Prototype |
|---|---|---|
| [ft_substr](./ft_substr.c) | Allocates a substring of `s` starting at `start` with max length `len` | `char *ft_substr(char const *s, unsigned int start, size_t len);` |
| [ft_strjoin](./ft_strjoin.c) | Allocates a new string concatenating `s1` and `s2` | `char *ft_strjoin(char const *s1, char const *s2);` |
| [ft_strtrim](./ft_strtrim.c) | Allocates a copy of `s1` with `set` characters removed from both ends | `char *ft_strtrim(char const *s1, char const *set);` |
| [ft_split](./ft_split.c) | Splits `s` by delimiter `c`, returns a NULL-terminated array of strings | `char **ft_split(char const *s, char c);` |
| [ft_strmapi](./ft_strmapi.c) | Applies `f` to each character of `s`, returns a new string | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));` |
| [ft_striteri](./ft_striteri.c) | Applies `f` to each character of `s` in place, passing its index | `void ft_striteri(char *s, void (*f)(unsigned int, char*));` |
---
- *Type Conversion*
---
| Function | Description | Prototype |
|---|---|---|
| [ft_itoa](./ft_itoa.c) | Converts an integer to a newly allocated string | `char *ft_itoa(int n);` |
---
- *File Descriptor Output*
---
| Function | Description | Prototype |
|---|---|---|
| [ft_putchar_fd](./ft_putchar_fd.c) | Writes character `c` to file descriptor `fd` | `void ft_putchar_fd(char c, int fd);` |
| [ft_putstr_fd](./ft_putstr_fd.c) | Writes string `s` to file descriptor `fd` | `void ft_putstr_fd(char *s, int fd);` |
| [ft_putendl_fd](./ft_putendl_fd.c) | Writes string `s` followed by a newline to `fd` | `void ft_putendl_fd(char *s, int fd);` |
| [ft_putnbr_fd](./ft_putnbr_fd.c) | Writes integer `n` to file descriptor `fd` | `void ft_putnbr_fd(int n, int fd);` |

---

### Part 3 — Linked list 
- *List Definition*
---
```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}                   t_list;
```
---
- *Node Management*
---
| Function | Description | Prototype |
|---|---|---|
| [ft_lstnew](./ft_lstnew.c) | Creates a new node with `content` and `next` set to NULL | `t_list *ft_lstnew(void *content);` |
| [ft_lstadd_front](./ft_lstadd_front.c) | Adds `new` at the beginning of `lst` | `void ft_lstadd_front(t_list **lst, t_list *new);` |
| [ft_lstsize](./ft_lstsize.c) | Returns the number of nodes in the list | `int ft_lstsize(t_list *lst);` |
| [ft_lstlast](./ft_lstlast.c) | Returns the last node of the list | `t_list *ft_lstlast(t_list *lst);` |
| [ft_lstadd_back](./ft_lstadd_back.c) | Adds `new` at the end of `lst` | `void ft_lstadd_back(t_list **lst, t_list *new);` |
| [ft_lstdelone](./ft_lstdelone.c) | Frees a single node using `del` on its content | `void ft_lstdelone(t_list *lst, void (*del)(void *));` |
| [ft_lstclear](./ft_lstclear.c) | Deletes and frees all nodes using `del`, sets `*lst` to NULL | `void ft_lstclear(t_list **lst, void (*del)(void *));` |
---
- *List Traversal*
---
| Function | Description | Prototype |
|---|---|---|
| [ft_lstiter](./ft_lstiter.c) | Applies `f` to the content of every node | `void ft_lstiter(t_list *lst, void (*f)(void *));` |
| [ft_lstmap](./ft_lstmap.c) | Creates a new list by applying `f` to each node; uses `del` on error | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));` |

---

