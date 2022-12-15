/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:40:38 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/14 17:58:55 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_isdigit(int c)
{
	return (c <= '9' && c >= '0');
}

#include <stdio.h>

int	is_all_digit(char **input, int num_arg)
{
	int	i;
	int	j;

	i = 1;
	while (i < num_arg)
	{
		j = 0;
		while (input[i][j] != '\0')
		{
			// printf ("i = %d, j = %d, input[i][j] = %c\n", i, j, input[i][j]);
			if (!ft_isdigit(input[i][j]))
				return(-1);
			j++;
		}
		i++;
	}
	return (1);
}