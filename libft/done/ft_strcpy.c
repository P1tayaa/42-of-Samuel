int ft_strlen(char *str)
{
    int i;
    i = 0;
    while(str[i] != '\0')
        i++;
    return (i);
}

char *strcpy(char *dest, const char *src)
{
    int i;

    i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

// #include <unistd.h>

// int main(void)
// {
//     char src[] = "je copy";
//     char dest[50];

//     strcpy(dest, src);
//     write(1, dest, ft_strlen(dest));
// }