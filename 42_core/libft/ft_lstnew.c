#include<stdlib.h>
#include <stdio.h>

typedef struct  s_list
{
    void            *content;
    struct s_list   *next;
}                   t_list;

t_list *ft_lstnew(void *content)
{
    t_list *new_node;
    new_node =(t_list *)malloc(sizeof (t_list));
    if(new_node ==  NULL)
        return  NULL;
    new_node->content = content;
    new_node->next = NULL;
    return(new_node);
}


int main()
{
    // Create content for the new node
    char *content = "Hello, world!";

    // Create a new list node with the content
    t_list *node = ft_lstnew(content);

    // Check if the node was created successfully
    if (node == NULL)
    {   
        printf("Failed to create new list node.\n");
        return 1;
    }

    // Print the content of the new node
    printf("Node content: %s\n",  (char *)node->content);

    // Free the allocated memory for the node
    free(node);

    return 0;
}
