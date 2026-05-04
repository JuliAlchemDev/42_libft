/*
NAME
     memmove – copy byte string

     void *memmove(void *dst, const void *src, size_t len);

DESCRIPTION
     The memmove() function copies len bytes from
     string src to string dst.  The two strings
     may overlap; the copy is always done in a
     non-destructive manner.

RETURN VALUES
     The memmove() function returns the original
     value of dst.
*/

void *ft_memmove(void *dst, const void *src, size_t len);