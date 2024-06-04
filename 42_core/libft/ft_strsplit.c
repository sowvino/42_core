#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

int ft_calcs2(const char *s, const char c)
{
    int i = 0;
    int count = 0;
    while (s[i] != '\0')
    {
        if (c == s[i])
        {
            count ++;
        }
        i++;
    }
    return count;
}

char **ft_split(char const *s, char c)
{
    int i, j, k, word_count, word_length;
    char **result;

    if (!s) return NULL;

    // Count the number of words
    word_count = 1;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == c) word_count++;
    }

    // Allocate memory for the array of strings
    result = (char **)malloc((word_count + 1) * sizeof(char *));
    if (!result) return NULL;

    i = 0;
    k = 0;
    while (i < word_count)
    {
        // Skip delimiter characters
        while (s[k] == c)
            k++;

        // Calculate the length of the current word
        word_length = 0;
        while (s[k + word_length] != '\0' && s[k + word_length] != c)
            word_length++;

        // Allocate memory for the current word
        result[i] = (char *)malloc((word_length + 1) * sizeof(char));
        if (!result[i])
        {
            // Free previously allocated memory in case of failure
            for (j = 0; j < i; j++)
                free(result[j]);
            free(result);
            return NULL;
        }

        // Copy the current word to the result array
        for (j = 0; j < word_length; j++)
            result[i][j] = s[k + j];
        result[i][j] = '\0';

        k += word_length;
        i++;
    }

    result[word_count] = NULL; // Null-terminate the array of strings
    return result;
}

int main()
{
    const char *s = "hello,world,hi,there";
    const char c = ',';
    char **result = ft_split(s, c);
    int i;

    if (result)
    {
        for (i = 0; result[i] != NULL; i++)
        {
            printf("%s\n", result[i]);
            free(result[i]); // Free each word
        }
        free(result); // Free the array of pointers
    }

    return 0;
}
