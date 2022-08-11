int ft_strlen(char *str)
{
    int i;
    i = 0;
    while(str[i] != '\0')
        i++;
    return (i);
}

// #include <stddef.h>

// char *strncpy(char *dest, const char *src, size_t n)
// {
//     int i;

//     i = 0;
//     while (src[i] != '\0' && i < n)
//     {
//         dest[i] = src[i];
//         i++;
//     }
//     dest[i] = '\0';
//     return (dest);
// }

// #include <unistd.h>

// int main(void)
// {
//     char src[] = "je copy";
//     char dest[50];

//     strncpy(dest, src, 1);
//     write(1, dest, ft_strlen(dest));
// }