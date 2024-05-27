#include <stdio.h>

char *ft_strnstr(const char *str1, const char *str2, size_t len)
{
    size_t i;
    size_t j;
    i = 0;
    if (str2[i] == '\0')
    {
        return ((char *)&str1[i]);
    }
    while (str1[i] != '\0' && i < len)
    {

        j = 0;
        while (str2[j] != '\0')
        {
            if (str1[i + j] != str2[j])
            {
                break;
            }
            j++;
        }
        if (str2[j] == '\0')
        {
            return ((char *)&str1[i]);
        }
        i++;
    }
    return (NULL);
}

int main()
{
    char *str1 = "hello world";
    char *str2 = "";
    size_t n = 2;
    printf("%s\n", ft_strnstr(str1, str2, n));
}