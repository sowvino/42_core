#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
    int i;
    i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

char *ft_strjoin(char const *s1, char const *s2)
{
    int len1 = ft_strlen((char *)s1);
    int len2 = ft_strlen((char *)s2);
    int totlen = len1 + len2;
    
    char *newstr;
    newstr = (char *)malloc((totlen + 1) * sizeof(char));

    if (newstr == NULL)
        return NULL;

    int i;
    i = 0;
    int j;

    while (s1[i] != '\0')
    {

        newstr[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j] != '\0')
    {
        newstr[i + j] = s2[j];
        j++;
    }
    newstr[i + j] = '\0';
    return (newstr);
}

int main()
{
    const char *s1 = "Hello";
    const char *s2 = "worldghh";
    printf("%s\n", ft_strjoin(s1, s2));
}