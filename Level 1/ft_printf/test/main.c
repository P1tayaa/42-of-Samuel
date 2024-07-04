# include "header/ft_printf.h"

int main(int argc, char **argv) {
    ft_printf("I will print with my printf all %d args as strings\n", argc);
    for (int i = 0; i < argc; i++) {
        ft_printf("%s\n", argv[i]);
    }
    return 0;
}