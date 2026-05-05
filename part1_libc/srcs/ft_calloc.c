
// RETURN VALUES
//      If successful, calloc() functions return a pointer to allocated memory.
//      If there is an error, they return a NULL pointer and set errno to ENOMEM.

#include "libft.h"

void *ft_calloc(size_t count, size_t size)
{
   
    void *memory;
    if(count == 0 || size == 0)
        return (malloc(0));

    memory = malloc(count * size);

    if(!memory)
        return (NULL);

    ft_bzero(memory, count * size);
    return (memory);

}