/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:35:31 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/05 19:00:37 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

void test_itoa(void)
{
	printf("TEST itoa\n");
	int i = 42;
	printf("%s", ft_itoa(i));
}

void test_bzero(void)
{
	printf("\n\nTEST bzero\n");
	char s[] = "test truc";
	ft_bzero(s, 3);
	write(1, s, 9);
	write(1, "\n", 1);
}

void test_strdup(void)
{
	printf("\nTEST strdup\n");
	char *str = "test if works";
	char *dupstr;

	dupstr = ft_strdup(str);
	write(1, dupstr, ft_strlen(dupstr));
	free(dupstr);
}

void test_strcpy(void)
{
	printf("\n\nTEST strcpy\n");
	char src[] = "je copy";
	char dest[50];

	ft_strcpy(dest, src);
	write(1, dest, ft_strlen(dest));
}

void test_strcat(void)
{
	printf("\n\nTEST strcat\n");
	char	src[] = "test";
	char	dest[50] = "this is a ";

	write(1, dest, ft_strlen(dest));
	write(1, "\n", 1);
	ft_strcat(dest, src);
	write(1, dest, ft_strlen(dest));
}

void test_puts_string(void)
{
	ft_putendl("\n\nTEST putstr, putnbr, putendl");

	ft_putstr("it shoud works since we are students of \0");
	ft_putnbr(42);
	ft_putendl("");
}

void test_strnew(void)
{
	char	*str;
	ft_putendl("\n\nTEST strnew");
	str = ft_strnew(6);
	str = "12345";
	ft_putstr(str);
}

void test_strjoin(void)
{
	char	*str;
	ft_putendl("\n\nTEST strjoin");
	str = ft_strjoin("2 + 2 =", " 4");
	ft_putstr(str);
}

void test_isall(void)
{
	ft_putendl("\n\nTEST isall");
	ft_putendl("(isdigit) should be true");
	ft_putnbr(ft_isdigit('6'));
	ft_putendl("");
	ft_putendl("(isdigit) should be false");
	ft_putnbr(ft_isdigit('a'));

	ft_putendl("\n");
	ft_putendl("(isupper) should be true");
	ft_putnbr(ft_isupper('A'));
	ft_putendl("");
	ft_putendl("(isupper) should be false");
	ft_putnbr(ft_isupper('a'));

	ft_putendl("\n");
	ft_putendl("(islower) should be true");
	ft_putnbr(ft_islower('a'));
	ft_putendl("");
	ft_putendl("(islower) should be false");
	ft_putnbr(ft_islower('A'));

	ft_putendl("\n");
	ft_putendl("(isalpha) should be true");
	ft_putnbr(ft_isalpha('f'));
	ft_putendl("");
	ft_putendl("(isalpha) should be false");
	ft_putnbr(ft_isalpha('5'));

	ft_putendl("\n");
	ft_putendl("(isalnum) should be true");
	ft_putnbr(ft_isalnum('a'));
	ft_putendl("");
	ft_putendl("(isalnum) should be false");
	ft_putnbr(ft_isalnum(' '));

	ft_putendl("\n");
	ft_putendl("(isascii) should be true");
	ft_putnbr(ft_isascii(65));
	ft_putendl("");
	ft_putendl("(isascii) should be false");
	ft_putnbr(ft_isascii(458));

	ft_putendl("\n");
	ft_putendl("(isprint) should be true");
	ft_putnbr(ft_isprint(65));
	ft_putendl("");
	ft_putendl("(isprint) should be false");
	ft_putnbr(ft_isprint(458));
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

	// test_itoa();

	// test_bzero();

	// test_strdup();

	// test_strcpy();
	
	// test_strcat();

	// test_puts_string();

	// test_strnew();

	// test_strjoin();

	// test_isall();

	int array [] = { 54, 85, 20, 63, 21 };
    int * copy = NULL;
    int length = sizeof( int ) * 5;
       
    /* Memory allocation and copy */
    copy = (int *) malloc( length );
    ft_memcpy( copy, array, length );
        
    /* Display the copied values */
    for( length=0; length<5; length++ ) {
        printf( "%d ", copy[ length ] );
    }
    printf( "\n" );
        
    free( copy );
    
    return EXIT_SUCCESS;

	return (0);
}
