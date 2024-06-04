#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

t_list *ft_lstlast(t_list *lst)
{
    t_list *node;
    node = lst;
    if(!node)
        return  node;
    
    while(node->next != NULL)
    {
        node = node->next;
    }
    return (node);
}
int main() {
    // Create a new list
    t_list *list = NULL;

    // Allocate three nodes
    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));

    // Assign some values
    node1->content = "Hello";
    node2->content = "World";
    node3->content = "!";

    // Link the nodes together
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    // Set the list to the first node
    list = node1;

    // Get the last node
    t_list *last_node = ft_lstlast(list);

    // Check if the last node is NULL
    if (last_node == NULL) {
        printf("The list is empty.\n");
    } else {
        // Print the content of the last node
        printf("The content of the last node is: %s\n", (char *)last_node->content);
    }

    // Free the memory
    free(node1);
    free(node2);
    free(node3);

    return 0;
}
