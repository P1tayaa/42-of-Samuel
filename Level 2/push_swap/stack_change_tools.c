/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_change_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:42:07 by sboulain          #+#    #+#             */
/*   Updated: 2023/02/09 17:11:57 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack_date_pointer(t_stack *stack_1, t_stack *stack_2)
{
	int		temp_int;
	bool	temp_bool;

	temp_int = stack_1 -> data;
	stack_1 -> data = stack_2 -> data;
	stack_2 -> data = temp_int;
	temp_int = stack_1 -> index_data;
	stack_1 -> index_data = stack_2 -> index_data;
	stack_2 -> index_data = temp_int;
	temp_bool = stack_1 -> has_data;
	stack_1 -> has_data = stack_2 -> has_data;
	stack_2 -> has_data = temp_bool;
}

t_stack	*get_stack_of_index(t_stack *first_stack, int index)
{
	int		i;
	t_stack	*stack_temp;

	i = 0;
	stack_temp = first_stack;
	while (i < index)
	{
		stack_temp = stack_temp -> next;
		i++;
	}
	return (stack_temp);
}