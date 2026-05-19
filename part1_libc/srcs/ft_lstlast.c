#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
    if(!lst)
        return NULL;
    while(lst->next != NULL)
        lst = lst->next;
    return (lst);
}
/*
int main() {
    t_list *lst = NULL;
    t_list *node1 = ft_lstnew("Hello");
    t_list *node2 = ft_lstnew("World!");
    ft_lstadd_front(&lst, node1);
    ft_lstadd_front(&lst, node2);

    t_list *last_node = ft_lstlast(lst);
    printf("%s",(char *)last_node->content);
    return 0;
}
*/

