#include <stdlib.h>
#include <stdio.h>

void *ft_calloc(size_t nelem, size_t elsize)
{
    void *array;
    array = (void *)malloc(nelem * elsize);
    if (array == NULL)
        return NULL;
    // ft_bzero(array,(nelem * elsize));
    size_t i;
    i = 0;
    char *str;
    str = array;
    while (i < (nelem * elsize))
    {
        str[i] = 0;
        i++;
    }
    return (array);
}

int main()
{
    size_t nelem = 2;
    size_t elsize = 4;
    char *ret = ft_calloc(nelem, elsize);
    printf("%d\n", ret);
}