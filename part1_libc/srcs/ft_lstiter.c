void print_node(void *content)
{
    printf("%s ", (char *)content);
}

void ft_lstiter(t_list *lst, void (*f)(void *))
{
    if(!lst || !f)
        return ;
    t_list *current;
    current = lst;
    while(current != NULL)
    {
        f(current->content);
        current = current->next;
    }
}

int main(void)
{
    t_list *list;
    list = NULL;
    t_list *node1;
    t_list *node2;
    t_list *node3;
    
    node1= ft_lstnew("Hello");
    node2= ft_lstnew("World");
    node3= ft_lstnew("!");
    
    ft_lstadd_front(&list, node1);
    ft_lstadd_front(&list, node2);
    ft_lstadd_front(&list, node3);
    
    ft_lstiter(list, print_node); // ! World Hello 
        
    return (0);
}