
int ft_strlen(char *str)
{
    int i;
    while (str[i] != '\0')
        i++;
    return (i);
}

char *strcat(char *dest, const char *src)
{
    int i;
    int j;

    j = ft_strlen(dest);
    i = 0;
    while (src[i] != '\0')
    {
        dest[j + i] = src[i];
        i++;
    }
    dest[j + i] = '\0';
    return (dest);
}

// #include <unistd.h>

// int main(void)
// {
//     char    src[] = "test";
//     char    dest[50] = "this is a ";

//     write(1, dest, ft_strlen(dest));
//     write(1, "\n", 1);
//     strcat(dest, src);
//     write(1, dest, ft_strlen(dest));
//     return (0);
// }