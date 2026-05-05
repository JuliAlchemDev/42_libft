/*
NAME
       atoi, atol, atoll - convert a string to an integer

			 int atoi(const char *nptr);

DESCRIPTION
       The  atoi() function converts the initial portion of the string pointed
       to by nptr to int.  The behavior is the same as

           strtol(nptr, NULL, 10);

       except that atoi() does not detect errors.

RETURN VALUE
       The converted value or 0 on error.

*/

int ft_atoi(const char *str)
{
	int res;
	int i;
	int sign;
	
	res = 0;
	i = 0;
	sign = 1;
	
	// 	9 → \t tabulación
	// 10 → \n salto de línea
	// 11 → \v tabulación vertical
	// 12 → \f salto de página
	// 13 → \r retorno de carro
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

