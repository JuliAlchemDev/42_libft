void ft_lstclear(t_list **lst, void (*del)(void
*))
{
    t_list *current;
    if(!del || !lst)
        return ;
    while(*lst)
    {
        current = (*lst)->next;
        ft_lstdelone(*lst, del);
        *lst = current;
    }
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// typedef struct s_list {
//     void *content;
//     struct s_list *next;
// } t_list;
// int ft_lstsize(t_list *lst)
// {
//     int count;
//     t_list *current;
//     count = 0;
//     current = lst;
//     while(current)
//     {
//         current = current->next;
//         count++;
//     }
//     return (count);
// }
// t_list *ft_lstnew(void *content)
// {
//     t_list *node;
//     node = malloc(sizeof(t_list));
//     if(!node)
//         return NULL;
//     node->content = content;
//     node->next = NULL;
//     return node;
// };
// t_list *ft_lstlast(t_list *lst)
// {
//     if(!lst)
//         return NULL;
//     while(lst->next != NULL)
//         lst = lst->next;
//     return (lst);
// }
// void ft_lstadd_back(t_list **lst, t_list *new)
// {
//     if(!lst || !new)
//         return ;
//     if(!*lst)
//     {
//         *lst = new;
//         return ;
//     }
//     ft_lstlast(*lst)->next = new;
// }
// void del(void *content)
// {
//     free(content);
// }
// void ft_lstdelone(t_list *lst, void (*del)(void
// *))
// {
//     if(!lst || !del) 
//         return ;
//     del(lst->content); 
//     free(lst); 
// }
// void ft_lstclear(t_list **lst, void (*del)(void
// *))
// {
//     t_list *current;
//     if(!del || !lst)
//         return ;
//     while(*lst)
//     {
//         current = (*lst)->next;
//         ft_lstdelone(*lst, del);
//         *lst = current;
//     }
// }
// int main() {
//     t_list *lst = NULL;
//     t_list *node_1 = ft_lstnew(strdup("Hello"));
//     t_list *node_2 = ft_lstnew(strdup("World"));
//     t_list *node_3 = ft_lstnew(strdup("!"));
//     ft_lstadd_back(&lst, node_1);
//     ft_lstadd_back(&lst, node_2);
//     ft_lstadd_back(&lst, node_3);
//     node_1->next = node_3;
//     ft_lstdelone(node_2, del);
//     t_list *current = lst; 
    
//     while(current != NULL)
//     {
//         printf("Content: %s\n", (char *)current->content);
//         current = current->next;
//     }
//     ft_lstclear(&lst, del);
//     return 0;
// }