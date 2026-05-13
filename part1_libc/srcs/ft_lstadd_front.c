void ft_lstadd_front(t_list **lst, t_list *new)
{
    if(lst != NULL && new != NULL) 
    {
        new->next = *lst; 
        *lst = new;
    }
}
/*
int main() {
    t_list *lst = NULL;
    t_list *node1 = ft_lstnew("Hello");
    t_list *node2 = ft_lstnew("World!");
    
    ft_lstadd_front(&lst, node1);
    ft_lstadd_front(&lst, node2);
    t_list *current = lst;
    size_t count_nodes;
    count_nodes = 0;
    
    while(current)
    {
        printf("content: %s\n", (char*) current->content);
        current = current->next; 
        count_nodes++;
    }
    printf("Count: %d\n",count_nodes);
    return 0;
}
*/
