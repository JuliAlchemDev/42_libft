t_list *ft_lstnew(void *content)
{
    t_list *node;
    node = malloc(sizeof(t_list));
    if(!node)
        return NULL;
    node->content = content;
    node->next = NULL;
    return (node);
}

// int main() {
//     t_list *node = ft_lstnew("Hello!");
//     t_list *node1 = ft_lstnew("World!");
//     node->next = node1;
//     t_list *current = node;
//     while(current)
//     {
//         printf("content: %s\n", (char *)current->content);
//         // printf("next: %p\n", current->next);
//         current = current->next;
//     }
    
    
//     return 0;
// }