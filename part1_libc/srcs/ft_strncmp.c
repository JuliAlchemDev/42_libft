/*
 NAME
       strncmp - compare two strings

		int strncmp(const char *s1, const char *s2, size_t n);
 DESCRIPTION


 RETURN VALUES
	   The strcmp() and strncmp() functions return an integer less than, equal
       to, or greater than zero if s1 (or the first n bytes thereof) is found,
       respectively, to be less than, to match, or be greater than s2.
*/

#include "libft.h"

int ft_strncmp(const char *str_1, const char *str_2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && (str_1[i] || str_2[i]))
	{
		if (str_1[i] != str_2[i])
			return ((unsigned char)str_1[i] - (unsigned char)str_2[i]);
		i++;
	}
	return (0);
}

