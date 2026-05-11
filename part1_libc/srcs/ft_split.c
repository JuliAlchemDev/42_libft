


char **ft_split(char const *s, char c);

int	ft_count_words(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i]) // recorremos el el stiring hasta el final 
	{
		if (s[i] != c) // si el valor de s[i] es difrente al c, contamos 1 palabra 
		{
			words++;
	        while (s[i] && s[i] != c) // entiendo que aqui sigue recorriendo dentro del substring hasta que no se de con el c y entoces sale del bucle interno y vuelve a entrar en el bucle extreno porque aaun no he recorrido tyodo el string
	            i++;
		} 	
		else // si el valor de s[i] es igual al c, contamos saltamos al siguente indice (como que haciendo skip)
			i++;
	}
	return (words);
}

int main() {
    char *str = "Hello  Wolrd !";
    char separator = ' ';
    ft_count_words(str, separator);
    return 0;
}

// https://github.com/waltergcc/42-libft/blob/main/libft/ft_split.c