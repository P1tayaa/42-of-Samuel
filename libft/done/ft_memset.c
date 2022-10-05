/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 02:29:31 by marvin            #+#    #+#             */
/*   Updated: 2022/10/05 17:55:54 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// #include <string.h>

void *ft_memset(void *b, int c, size_t n)
{
	while (n != 0)
	{
		*(char *)b = c;
		n--;
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
