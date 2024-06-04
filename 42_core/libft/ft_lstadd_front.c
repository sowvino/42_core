#include <stdlib.h>
#include <stdio.h>

// Define the t_list structure
typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

// Function to create a new list node
t_list *ft_lstnew(void *content)
{
    t_list *new_node;
    new_node = (t_list *)malloc(sizeof(t_list));
    if (new_node == NULL)
        return NULL;
    new_node->content = content;
    new_node->next = NULL;
    return new_node;
}

// Function to add a new node at the beginning of the list
void ft_lstadd_front(t_list **lst, t_list *new)
{
    if (!lst || !new)
        return;
    new->next = *lst;
    *lst = new;
}

// Function to print the list
void print_list(t_list *lst)
{
    while (lst != NULL)
    {
        printf("%s\n", (char *)lst->content);
        lst = lst->next;
    }
}

int main()
{
    // Create content for the nodes
    char *content1 = "Node 1";
    char *content2 = "Node 2";
    char *content3 = "Node 3";

    // Create the first node
    t_list *node1 = ft_lstnew(content1);
    if (node1 == NULL)
    {
        printf("Failed to create node 1.\n");
        return 1;
    }

    // Create the second node
    t_list *node2 = ft_lstnew(content2);
    if (node2 == NULL)
    {
        printf("Failed to create node 2.\n");
        free(node1); // Free previously allocated node
        return 1;
    }

    // Create the third node
    t_list *node3 = ft_lstnew(content3);
    if (node3 == NULL)
    {
        printf("Failed to create node 3.\n");
        free(node1); // Free previously allocated nodes
        free(node2);
        return 1;
    }

    // Initialize the list with the first node
    t_list *list = NULL;

    // Add nodes to the front of the list
    ft_lstadd_front(&list, node1);
    ft_lstadd_front(&list, node2);
    ft_lstadd_front(&list, node3);

    // Print the list
    printf("List content:\n");
    print_list(list);

    // Free the list nodes
    t_list *temp;
    while (list != NULL)
    {
        temp = list;
        list = list->next;
        free(temp);
    }

    return 0;
}
