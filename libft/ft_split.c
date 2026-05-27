/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iualkhim <iualkhim@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 13:36:04 by iualkhim          #+#    #+#             */
/*   Updated: 2026/05/27 18:01:39 by iualkhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*extract_word(const char *s, size_t len)
{
	char	*word;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, s, len);
	word[len] = '\0';
	return (word);
}

static void	free_words(char **words, int j)
{
	while (j > 0)
		free(words[--j]);
	free(words);
}

static int	fill_words(char const *s, char c, char **words)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len = 0;
			while (s[i + len] && s[i + len] != c)
				len++;
			words[j] = extract_word(&s[i], len);
			if (!words[j])
				return (free_words(words, j), -1);
			i += len;
			j++;
		}
		else
			i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**words;

	if (!s)
		return (NULL);
	words = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!words)
		return (NULL);
	if (fill_words(s, c, words) == -1)
	{
		free(words);
		return (NULL);
	}
	return (words);
}
/*
int main() {
     char **words;
     int i = 0;
     words = ft_split("Hello World, C is awsome!", ' ');
    
     while(words[i])
     {
         printf("%s\n", words[i]);
         free(words[i]);
         i++;
     }
 
     free(words);
     return (0);
}
*/
