// NAME
//     strlen – find length of string

    // size_t strlen(const char *s);

// DESCRIPTION
//     The strlen() function computes the length of the string s.  

// RETURN VALUES
//     The strlen() function returns the number of characters that precede the
//      terminating NUL character.  

#include "libft.h"

size_t ft_strlen(const char *s){
    size_t count;
    count = 0;
    
    while(s[count])
        count++;
    return (count);
}


