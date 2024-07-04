/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:35:31 by sboulain          #+#    #+#             */
/*   Updated: 2024/07/04 13:43:05 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../header/libft.h"

void test_itoa(void)
{
	printf("TEST itoa\n");
	// int i = 47483648;
	char	*str = ft_itoa(-2147483648);
	printf("%s", str);
	free(str);
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

	ft_putstr("it shoud works since we are students of ");
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
	str = ft_strjoin("", "");
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

void test_memcpy(void)
{
	int array [] = { 54, 85, 20, 63, 21 };
    int * copy = NULL;
    int length = sizeof( int ) * 5;

	ft_putendl("\n\nTEST memcpy");
    /* Memory allocation and copy */
    copy = (int *) malloc( length );
    ft_memcpy( copy, array, length );

    /* Display the copied values */
    for( length=0; length<5; length++ ) {
        ft_putnbr(copy[ length ] );
		ft_putstr(" ");
    }

    free( copy );

}

void test_atoi(void)
{
	ft_putendl("\n\nTEST atoi");
	ft_putnbr(ft_atoi("\t\v\f\r\n \f-06050"));
}

void test_tolower_and_roupper(void)
{
	ft_putendl("\n\nTEST tolower and roupper");
	ft_putstr("This should be a a: ");
	ft_putchar(ft_tolower('A'));
	ft_putendl("");

	ft_putstr("This should be a A: ");
	ft_putchar(ft_toupper('a'));
	ft_putendl("");
}

void	test_calloc(void)
{
	int	*phrase;
	int	i;

	ft_putendl("\n\nTEST calloc");
	phrase = (int *) ft_calloc(5, sizeof(int));
	i = 0;
	while(i < 5)
	{
		ft_putnbr(phrase[i]);
		if (i != 4)
			ft_putstr(", ");
		i++;
	}
	free(phrase);
}

void test_memmove(void)
{
	ft_putendl("\n\nTEST memmove");
	// On crée une zone de mémoire de 10 entiers et contenant
    // que neuf valeurs. La dixième est non utilisée (0).
    int data[] = { 20, 30, 40, 50, 60, 70, 80, 90, 100, 0 };
	int i;

	i = 0;
    // On affiche le contenu de la collection
    while(i < 10) {
        ft_putnbr(data[i]);
		ft_putstr(", ");
		i++;
    }
	ft_putendl( "" );  // Un retour à la ligne

    // On décale les éléménts dans la collection ...
    void * source = (void *) data;
    void * destination = (void *) ( data + 1 );
    size_t size = 10 * sizeof( int );
    ft_memmove( destination, source, size );

	// ... pour y insérer une nouvelle valeur en tête
    data[0] = 10;
	i = 0;
    // On affiche le contenu de la collection
	while(i < 10) {
        ft_putnbr(data[i]);
		ft_putstr(", ");
		i++;
    }
    ft_putendl( "test" );  // Un retour à la ligne
}

void test_strlcpy_and_strlcat(void)
{
	char	*str1;
	char	*str2;

	ft_putendl("\n\nTEST strlcpy_and_strlcat");
	str2 = malloc(19 * 2);
	str1 = "this is this and_";
	ft_strlcpy(str2, str1, 19);
	ft_strlcat(str2, str1, 38);
	ft_putstr(str2);
	free(str2);
}

void test_strchr_and_strrchr(void)
{
	char	*str;

	ft_putendl("\n\nTEST strchr_and_strrchr");
	str = "lalala_c_papapa_c_dadada_";
	ft_putstr("original str is :");
	ft_putendl(str);
	ft_putstr("strchr str is :");
	ft_putendl(ft_strchr(str, '\0'));
	ft_putstr("strrchr str is :");
	ft_putendl(ft_strrchr(str, 'c'));
}

int main(void)
{
	test_itoa();

	test_bzero();

	test_strdup();

	test_strcpy();

	test_strcat();

	test_puts_string();

	test_strnew();

	test_strjoin();

	test_memcpy();

	test_atoi();

	test_tolower_and_roupper();

	test_calloc();

	test_strlcpy_and_strlcat();

	test_strchr_and_strrchr();

	ft_putendl("");

	return (0);
}
