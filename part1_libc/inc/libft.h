#ifndef LIBFT_H
# define LIBFT_H

#include <stdlib.h> // malloc, free, size_t 
#include <unistd.h>
#include <stdio.h>

// Part 1 - libc functions

// Block 1 - Character 

int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);

// Block 2 - Type Conversion

int ft_toupper(int c);
int ft_tolower(int c);
int ft_atoi(const char *str);

// Block 3 - String Operations
size_t ft_strlen(const char *s);
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
char *ft_strchr(const char *str, int c);
char *ft_strrchr(const char *str, int c);
int ft_strncmp(const char *str_1, const char *str_2, size_t n);
// ft_strdup

// ## Block 4 - Memory Manipulation
void *ft_memset(void *str, int value, size_t len);
void ft_bzero(void *str, size_t n);
void *ft_memcpy(void *dst, const void *src, size_t n);
// void *memmove(void *dst, const void *src, size_t len);
// ft_memchr 
// ft_memcmp

// ## Block 5 - Memory Allocation
// ft_calloc

typedef struct s_list
{
    void *content;
    struct s_list *next;
}   t_list;

#endif
