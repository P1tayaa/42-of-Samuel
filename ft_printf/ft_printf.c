/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:34:27 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/27 13:21:16 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

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