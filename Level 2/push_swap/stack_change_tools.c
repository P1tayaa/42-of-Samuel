/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_change_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:42:07 by sboulain          #+#    #+#             */
/*   Updated: 2023/03/09 18:50:50 by sboulain         ###   ########.fr       */
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
// get the index of the end of the stack or empty
int	get_index_of_empty_index(t_stack *stack)
{
	int		index_until_empty;
	t_stack	*temp_stack;

	index_until_empty = 0;
	temp_stack = stack;
	while (temp_stack -> index_data != -1 && temp_stack -> next != NULL)
	{
		temp_stack = temp_stack -> next;
		index_until_empty++;
	}
	return (index_until_empty);
}

void	print_stack(t_stack *stack);


//bring the first empty first on the stack
void	bring_empty_to_first_stack(t_stack *stack)
{
	int	index_until_empty;

	index_until_empty = get_index_of_empty_index(stack);
	while (index_until_empty > 0)
	{
		swap_stack_date_pointer(
			get_stack_of_index(stack, index_until_empty),
			get_stack_of_index(stack, index_until_empty - 1));
		index_until_empty--;
	}
}

// make the first last
// line where def index_until_empty, don't look at first one because empty
void	make_first_element_last_stack(t_stack *stack)
{
	int	index_until_empty;
	int	i;

	index_until_empty = get_index_of_empty_index(stack -> next) + 1;
	i = 0;
	while (i < index_until_empty)
	{
		swap_stack_date_pointer(
			get_stack_of_index(stack, i),
			get_stack_of_index(stack, i + 1));
		i++;
	}
}
