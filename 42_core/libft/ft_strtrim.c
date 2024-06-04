#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for strlen

// Check if character c is in the set
int is_set(char c, const char *set)
{
    int i = 0;
    while (set[i])
    {
        if (c == set[i])
            return (1);
        i++;
    }
    return (0);
}

// Find the first position not in the set
int first_pos(const char *s, const char *set)
{
    int i = 0;
    while (s[i] && is_set(s[i], set))
    {
        i++;
    }
    return (i);
}

// Find the last position not in the set
int last_pos(const char *s, const char *set)
{
    int i = strlen(s) - 1;
    while (i >= 0 && is_set(s[i], set))
    {
        i--;
    }
    return (i);
}

// Calculate the length of the trimmed string
int trim_len(const char *s, const char *set)
{
    int last = last_pos(s, set);
    int first = first_pos(s, set);
    if (first > last)
        return 0;
    return (last - first + 1);
}

// Trim the string s1 by removing characters from the set at both ends
char *ft_strtrim(const char *s1, const char *set)
{
    char *new_str;
    int newstr_len;
    int i;
    int start;

    if (!s1 || !set)
        return (NULL);

    start = first_pos(s1, set);
    newstr_len = trim_len(s1, set);

    new_str = (char *)malloc((newstr_len + 1) * sizeof(char));
    if (!new_str)
        return (NULL);

    for (i = 0; i < newstr_len; i++)
    {
        new_str[i] = s1[start + i];
    }
    new_str[newstr_len] = '\0'; // Null-terminate the string

    return (new_str);
}

int main()
{
    const char *s = "1234helloworld4";
    const char *set = "1234";
    char *trimmed = ft_strtrim(s, set);
    printf("%s\n", trimmed);
    free(trimmed); // Don't forget to free the allocated memory
    return 0;
}
