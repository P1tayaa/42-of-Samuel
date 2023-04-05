/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack_a copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:38:57 by sboulain          #+#    #+#             */
/*   Updated: 2023/04/04 18:25:50 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*make_single_stack(int val, bool as_data);

t_stack	*dup_stack(t_stack *stack, int index_of_stack)
{
	t_stack	*dup_stack;
	t_stack	*temp_stack;
	int		i;

	dup_stack = make_single_stack(stack->data, stack->has_data);
	temp_stack = dup_stack;
	i = 0;
	i++;
	while (i <= index_of_stack)
	{
		temp_stack -> next = make_single_stack
			(get_stack_of_index(stack, i)-> data, true);
		temp_stack = temp_stack -> next;
		i++;
	}
	return (dup_stack);
}

void	free_dup_stack(t_stack *stack, int index_of_stack)
{
	t_stack	*temp_stack;
	int		i;

	temp_stack = stack;
	i = index_of_stack;
	while (i >= 0)
	{
		temp_stack = get_stack_of_index(stack, i);
		free(temp_stack);
		temp_stack = NULL;
		i--;
	}
}

t_stack	*find_shortest_before_index(
		t_stack *stack_a, int index_of_stack, int pivot_data)
{
	int		i;

	i = index_of_stack;
	while (i >= 0)
	{
		if (pivot_data > get_stack_of_index(stack_a, i)-> data)
			return (get_stack_of_index(stack_a, i));
		i--;
	}
	return (NULL);
}

t_stack	*find_highest_before_index(
		t_stack *stack_a, int index_of_stack, int pivot_data)
{
	int		i;

	i = 0;
	while (i <= index_of_stack)
	{
		if (pivot_data < get_stack_of_index(stack_a, i)-> data)
			return (get_stack_of_index(stack_a, i));
		i++;
	}
	return (NULL);
}

void	sort_stack_alone(t_stack *stack_a, int index_of_stack)
{
	int		pivot_data;
	t_stack	*short_left;
	t_stack	*high_right;
	t_stack	*pivot;
	int		pivot_index;

	short_left = NULL;
	high_right = NULL;
	if (index_of_stack < 2)
	{
		if (get_stack_of_index(stack_a, 0)-> data
			> get_stack_of_index(stack_a, 1)-> data)
			swap_stack_date_pointer(stack_a, stack_a -> next);
		return ;
	}
	pivot_index = (index_of_stack) / 2;
	pivot = get_stack_of_index(stack_a, pivot_index);
	if (index_of_stack == 0)
		return ;
	pivot_data = get_stack_of_index(stack_a, pivot_index)-> data;
	short_left = find_shortest_before_index
		(pivot, index_of_stack - pivot_index, pivot_data);
	high_right = find_highest_before_index(stack_a, pivot_index, pivot_data);
	if (short_left == NULL && high_right == NULL)
	{
		sort_stack_alone(stack_a, pivot_index);
		sort_stack_alone(pivot, index_of_stack - pivot_index);
	}
	else if (short_left == NULL && high_right != NULL)
	{
		swap_stack_date_pointer(high_right, pivot);
		sort_stack_alone(stack_a, index_of_stack);
	}
	else if (high_right == NULL && short_left != NULL)
	{
		swap_stack_date_pointer(short_left, pivot);
		sort_stack_alone(stack_a, index_of_stack);
	}
	else
	{
		swap_stack_date_pointer(high_right, short_left);
		sort_stack_alone(stack_a, index_of_stack);
		sort_stack_alone(stack_a, pivot_index);
		sort_stack_alone(pivot, index_of_stack - pivot_index);
	}
}

void	compare_and_index(
		t_stack *stack_og, t_stack *stack_dup_in_order, int index_of_stack)
{
	int	i;
	int	j;

	i = 0;
	while (i <= index_of_stack)
	{
		j = 0;
		while (j <= index_of_stack)
		{
			if (get_stack_of_index(stack_dup_in_order, i)-> data
				== get_stack_of_index(stack_og, j)-> data)
			{
				get_stack_of_index(stack_og, j)-> index_data = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	index_values(t_stack *stack_a, int index_of_stack)
{
	t_stack	*stack_a_dup;

	stack_a_dup = dup_stack(stack_a, index_of_stack);
	sort_stack_alone(stack_a_dup, index_of_stack);
	compare_and_index(stack_a, stack_a_dup, index_of_stack);
	free_dup_stack(stack_a_dup, index_of_stack);
}
