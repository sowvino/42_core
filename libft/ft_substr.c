#include <stdlib.h>
#include <stdio.h>

unsigned int ft_strlen(char *s)
{
    unsigned j = 0;
    while (s[j] != '\0')
    {
        j++;
    }
    return (j);
}
char *ft_substr(const char *s, unsigned int start, size_t len)
{
    char *substr;
    unsigned int i;
    i = 0;
    unsigned int strlength;
    strlength = ft_strlen((char *)s);
    substr = (char *)malloc((len + 1) * sizeof(char));

    if (substr == NULL || s[i] == '\0')
        return NULL;

    while (i < len && (len < strlength))
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[i] = '\0';
    return (substr);
}

int main()
{
    const char *s = "hello";
    unsigned int start = 1;
    size_t len = 4;
    printf("%s\n", ft_substr(s, start, len));
}