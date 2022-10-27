/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:34:27 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/27 23:14:38 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int	get_purcentage_signs(char const *input, va_list arg)
{
	size_t	i;
	int		numer_of_char_print;
	int		is_bad;

	i = 0;
	numer_of_char_print = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '%' && input[i + 1] == '%')
		{
			i++;
			if (ft_putchar('%') == -1 && ++i)
				return (-1);
		}
		else if (input[i] == '%')
		{
			is_bad = manage_print(input, &i, arg);
			if (is_bad == -1)
				return (-1);
			numer_of_char_print = numer_of_char_print + is_bad;
			i++;
			continue ;
		}
		else
			if (ft_putchar(input[i]) == -1)
				return (-1);
		numer_of_char_print++;
		i++;
	}
	return (numer_of_char_print);
}

int	ft_printf(const char *input, ...)
{
	int		numer_of_char_print;
	va_list	arg;

	va_start(arg, input);
	numer_of_char_print = get_purcentage_signs(input, arg);
	va_end(arg);
	return (numer_of_char_print);
}

// int main(void)
// {
// 	int p = 568487;
// 	void *pp = &p;
// 	ft_printf("1234%%__%u\n", p);
// 	printf("1234%%__%u\n", p);
// }