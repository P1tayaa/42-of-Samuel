/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:34:27 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/21 19:37:58 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	printf("%'d", -2147483647);
}

int get_purcentage_signs(char *input, int *which_indext, char *which_type)
{
	size_t	i;
	int		number_of_purcentage;

	i = 0;
	number_of_purcentage = 0;
	while (input[i] != '\0')
	{
		if(input[i] == '%' && input[i + 1] == '%')
		{
			number_of_purcentage++;
		}
		i++;
	}
	which
	
}

//• %c Prints a single character. (putchar)
// • %s Prints a string (as defined by the common C convention). (putstr)
// • %p The void * pointer argument has to be printed in hexadecimal format. • %d Prints a decimal (base 10) number. 
// • %i Prints an integer in base 10. (putanybase)
// • %u Prints an unsigned decimal (base 10) number. (putanybase)
// • %x Prints a number in hexadecimal (base 16) lowercase format. (putanybase)
// • %X Prints a number in hexadecimal (base 16) uppercase format. (putanybase)
// • %% Prints a percent sign.

// int	ft_printf(const char *str, ...)
// {
	
// }
