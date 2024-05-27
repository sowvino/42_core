#include <stdio.h>

int ft_tolower(int ch)
{
    if (ch >= 65 && ch <= 90)
    {
        return (ch + 32);
    }
    return ch;
}

int main()
{
    int ch = 65;
    printf("%d\n", ft_tolower(ch));
    return 0;
}