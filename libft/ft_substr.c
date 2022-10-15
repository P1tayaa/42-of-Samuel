/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:25:57 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/15 19:22:21 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
	{
		str = ft_calloc(ft_strlen(s + start) + 1, 1);
		len = ft_strlen(s + start);
	}
	else
		str = ft_calloc(len + 1, 1);
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (j < (unsigned int) len)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

// int main(void)
// {
// 	ft_substr("", 0, 1);
// 	system("leaks a.out");
// }
