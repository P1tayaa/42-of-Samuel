/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 02:29:31 by marvin            #+#    #+#             */
/*   Updated: 2022/10/06 12:09:42 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// #include <string.h>

void *ft_memset(void *b, int c, size_t n)
{
	size_t i;
	unsigned char *ptr;

	ptr = b;
	i = 0;
	while (n != 0)
	{
		(ptr)[i] = c;
		n--;
		i++;
	}
	return (b);
}

// int main(void)
// {
// 	int c = 66;
// 	int b = 6;
// 	ft_memset(&b, 66, 4);
// 	printf("%d\n", b);
// 	b = 6;
// 	memset(&b, 66, sizeof(int));
// 	printf("%d", b);
// }
