#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*list_ptr;

	if (!lst)
		return ;
	list_ptr = lst;
	while (list_ptr != NULL)
	{
		(*f)(list_ptr->content);
		list_ptr = list_ptr->next;
	}
}

void print_content(void *content) {
    printf("%s\n", (char *)content);
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
    node3->content = "hghg";

    // Link the nodes together
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    // Set the list to the first node
    list = node1;

    // Iterate over the list and print the content of each node
    printf("Iterating over the list:\n");
    ft_lstiter(list, print_content);
    return 0;
}