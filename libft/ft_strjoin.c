/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 22:27:38 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/13 15:57:05 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*str;

	size = ft_strlen(s1) + ft_strlen(s2);
	if (size == 0)
		return (ft_strdup(""));
	str = ft_strnew(size);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, ft_strlen(s1));
	ft_memcpy(&str[ft_strlen(s1)], s2, ft_strlen(s2));
	return (str);
}

// int main(void)
// {
// 	char *s1 = "my favorite animal is";
// 	char *s2 = " ";
// 	char *s3 = "the nyancat";
// 	char *res = ft_strjoin(ft_strjoin(s1, s2), s3);

// 	ft_putstr( res );
// 	ft_putstr("\n");
// 	ft_putstr("my favorite animal is the nyancat");
// }