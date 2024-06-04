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

void ft_lstadd_back(t_list **lst, t_list *new)
{
    if (!lst || !new)
        return NULL;
    ft_lstlast(*lst)->next = new;     
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

    // Allocate a new node
    t_list *new_node = malloc(sizeof(t_list));
    new_node->content = "This is a new node.";
    new_node->next = NULL;

    // Add the new node to the end of the list
    ft_lstadd_back(&list, new_node);

    // Print the content of each node in the list
    t_list *current_node = list;
    while (current_node != NULL) {
        printf("%s\n", (char *)current_node->content);
        current_node = current_node->next;
    }

    return 0;
}