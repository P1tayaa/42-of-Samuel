int ft_strlen(char *str)
{
    int i;
    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

#include <stddef.h>

int strncmp(const char *s1, const char *s2, size_t n)
{
    int i;

    i = 0;
    while (s1 == s2 && i < n)
        i++;
    return (s1 - s2);
}

int main(void)
{
    
}
