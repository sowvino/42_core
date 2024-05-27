#include <stdio.h>

int toupper(int ch)
{
    
    if (ch >= 97 && ch <= 122)
    {
        return (ch - 32);
    }
    return (ch);
}

int main()
{
    int ch = 98;
    printf("%d", toupper(ch));
}