/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 02:32:30 by marvin            #+#    #+#             */
/*   Updated: 2022/08/11 02:32:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void *ft_memset(void *s, int c, size_t n);

void bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// int main(void)
// {
// 	char s[] = "test truc";
// 	bzero(s, 3);
// 	write(1, s, 9);
// 	write(1, "\n", 1);
// 	return (0);
// }