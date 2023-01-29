/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:38:55 by sboulain          #+#    #+#             */
/*   Updated: 2022/10/14 18:01:23 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	if (lst == NULL)
		return (NULL);
	new_lst = (*f)(lst -> content);
	if (!new_lst)
		return (NULL);
	if (lst -> next != NULL && new_lst != NULL)
		new_lst -> next = ft_lstmap(lst -> next, (*f), (*del));
	return (new_lst);
}
