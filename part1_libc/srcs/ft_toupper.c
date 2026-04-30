// NAME
//     toupper, tolower, toupper_l, tolower_l - convert uppercase or lowercase

// DESCRIPTION
//     These functions convert lowercase letters to uppercase, and vice versa.

//     If c is a lowercase letter, toupper() returns its uppercase equivalent,
//     if an uppercase representation exists in the  current  locale.   Other‐
//     wise,  it  returns c. 


// RETURN VALUE
//     The value returned is that of the converted letter, or c if the conver‐
//     sion was not possible.

int ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32); 
	else 
		return c; 
}
