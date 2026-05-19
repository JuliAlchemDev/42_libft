void ft_lstadd_back(t_list **lst, t_list *new)
{
    if(!lst || !new)
        return ;
    if(!*lst)
    {
        *lst = new;
        return ;
    }
    ft_lstlast(*lst)->next = new;
}
/*
int main() {
    t_list *lst = NULL;
    t_list *node1 = ft_lstnew("Hello");
    t_list *node2 = ft_lstnew("World!");
    ft_lstadd_front(&lst, node1);
    ft_lstadd_back(&lst, node2);

    t_list *last_node = ft_lstlast(lst);
    printf("%s",(char *)last_node->content);
    return 0;
}
*/
