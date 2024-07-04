#include "../header/get_next_line.h"
#include "stdio.h"

int main(void) {
    char *str = "first";
    puts("stop if first letter is S\n");
    while (str[0] != 'S')
    {
        str = get_next_line(0);
        printf("%s", str);
    }
}