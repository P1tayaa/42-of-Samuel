#include <stdlib.h>

int ft_cstrlen(const char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);   
}

char *strdup(const char *s)
{
    char *dupstr;
    int i;

    dupstr = (char *)malloc(ft_cstrlen(s) * sizeof(char));
    i = 0;
    while(s[i] != '\0')
    {
        dupstr[i] = s[i];
        i++;
    }
    dupstr[i] = '\0';
    return (dupstr);
}

// #include <unistd.h>

// int ft_strlen(char *str)
// {
//     int i;

//     i = 0;
//     while (str[i] != '\0')
//         i++;
//     return (i);   
// }

// int main(void)
// {
//     char *str = "test if works";
//     char *dupstr;

//     dupstr = strdup(str);
//     write(1, dupstr, ft_strlen(dupstr));
//     free(dupstr);
//     return (0);
// }