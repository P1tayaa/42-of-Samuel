/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 22:36:55 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/12 21:23:08 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	**ft_split(char const *s, char c)
{
	
	return (array_string);
}

int	main(void)
{
	char	**strs;
	char	*str;
	char	charslip;
	int		i;

	str = "ohaefhoaefaf hoaefioaf   oawiahfoef oaeh ofaw";
	strs = ft_split(str, ' ');
	i = 0;
	ft_putendl("eesgge");
	while (i < 7)
	{
		ft_putstr(strs[i]);
		i++;
	}
	free(strs);
}
