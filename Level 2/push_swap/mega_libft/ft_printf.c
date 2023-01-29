/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:34:27 by sboulain          #+#    #+#             */
/*   Updated: 2023/01/28 16:09:56 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stddef.h>
#include <unistd.h>

int	ft_putstr_int(char const *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (write(1, s, i));
}

int	ft_putchar_int(char c)
{
	return (write(1, &c, 1));
}

int	ft_atoi_base(int number, int base, int isfirst, char lettle);

int	ft_atoui_base(unsigned int number, unsigned int base,
		int isfirst, char lettle);

int	ft_atoull_base(unsigned long long number, unsigned long long base,
		int isfirst, char lettle);

int	manage_print(char const *input, size_t *i, va_list arg);

int	get_purcentage_signs(char const *input, va_list arg,
		int numer_of_char_print, size_t i);

int	get_purcentage_signs(char const *input, va_list arg,
	int numer_of_char_print, size_t i)
{
	int		is_bad;

	while (input[i] != '\0')
	{
		if (input[i] == '%' && input[i + 1] == '%')
		{
			i++;
			if (ft_putchar_int('%') == -1 && ++i)
				return (-1);
		}
		else if (input[i] == '%')
		{
			is_bad = manage_print(input, &i, arg);
			if (is_bad == -1)
				return (-1);
			numer_of_char_print = numer_of_char_print + is_bad;
			continue ;
		}
		else if (ft_putchar_int(input[i]) == -1)
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
	numer_of_char_print = get_purcentage_signs(input, arg, 0, 0);
	va_end(arg);
	return (numer_of_char_print);
}

// int main(void)
// {
// 	int p = 11355162;
// 	void *pp = &p;
// 	ft_printf("1234%%__%X\n", p);
// 	printf("1234%%__%X\n", p);
// }