/*
NAME
       toupper, tolower, toupper_l, tolower_l - convert uppercase or lowercase

DESCRIPTION
       These functions convert lowercase letters to uppercase, and vice versa.

       If c is a lowercase letter, toupper() returns its uppercase equivalent,
       if an uppercase representation exists in the  current  locale.   Other‐
       wise,  it  returns c.  The toupper_l() function performs the same task,
       but uses the locale referred to by the locale handle locale.

       If c is an uppercase letter, tolower() returns  its  lowercase  equiva‐
       lent, if a lowercase representation exists in the current locale.  Oth‐
       erwise, it returns c.  The tolower_l() function performs the same task,
       but uses the locale referred to by the locale handle locale.

RETURN VALUE
       The value returned is that of the converted letter, or c if the conver‐
       sion was not possible.
*/

int ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
