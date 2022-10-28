/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:33:33 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/28 19:35:50 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *curent_list;

	if (lst == NULL)
		return (NULL);
	curent_list = lst;
	while (curent_list -> next != NULL)
		curent_list = curent_list -> next;
	return (curent_list);
}
