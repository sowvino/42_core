#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
    if(!lst)
        return;
    (*del)(lst->content);
    free(lst);
}
void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list	*node;
    while(*lst)
    {
        node = (*lst)->next;
        ft_lstdelone(*lst,del);
        *lst = node;
    }
}

void delete_content(void *content) {
    free(content);
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

    // Print the content of each node in the list
    t_list *current_node = list;
    printf("Before clearing the list:\n");
    while (current_node != NULL) {
        printf("%s\n", (char *)current_node->content);
        current_node = current_node->next;
    }

    // Clear the list
    

    // Print the content of each node in the list
    printf("After clearing the list:\n");
    ft_lstclear(&list, delete_content);
    current_node = list;
    while (current_node != NULL) {
        printf("%s\n", (char *)current_node->content);
        current_node = current_node->next;
    }

    return 0;
}