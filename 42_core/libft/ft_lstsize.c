#include <stdlib.h>
#include <stdio.h>

// Define the t_list structure
typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;
 
int ft_lstsize(t_list *lst)
{
    int count;
    count = 0;
    t_list *node;
    node = lst;
    
    while(node != NULL)
    {
        count++;
        node = node-> next;
    }
    return (count);
}

int main() {
   
    t_list *list = NULL;

    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));

    node1->content = "Hello";
    node2->content = "World";
    node3->content = "!";

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    list = node1;

    printf("The size of the list is: %d\n", ft_lstsize(list));

}