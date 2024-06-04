#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
    
}