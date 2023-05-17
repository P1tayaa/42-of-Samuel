/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_for_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:18:21 by sboulain          #+#    #+#             */
/*   Updated: 2023/05/15 16:18:17 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_shortest_before_index(
		t_stack *stack_a, int i_stack, int pivo_data)
{
	int		i;

	i = i_stack;
	while (i >= 0)
	{
		if (pivo_data > get_stack_of_index(stack_a, i)-> data)
			return (get_stack_of_index(stack_a, i));
		i--;
	}
	return (NULL);
}

t_stack	*find_highest_before_index(
			t_stack *stack_a, int i_stack, int pivo_data);

void	sort_stack_alone(t_stack *stack_a, int i_stack);

void	swap_data_then_sort(
		t_stack *stack_a, t_stack *pivot, int i_stack, t_stack *data)
{
	swap_stack_date_pointer(data, pivot);
	sort_stack_alone(stack_a, i_stack);
}

void	sort_l_and_r_of_pivot(
		t_stack *stack_a, t_stack *pivot, int pivot_index, int i_stack)
{
	sort_stack_alone(stack_a, pivot_index);
	sort_stack_alone(pivot, i_stack - pivot_index);
}

void	when_both_null(
	t_stack *stack_a, int i_stack, t_stack *short_left, t_stack *high_right)
{
	t_stack	*pivot;

	pivot = get_stack_of_index(stack_a, i_stack / 2);
	swap_data_then_sort(stack_a, short_left, i_stack, high_right);
	sort_l_and_r_of_pivot(stack_a, pivot, i_stack / 2, i_stack);
}

void	sort_stack_alone(t_stack *stack_a, int i_stack)
{
	int		pivo_data;
	t_stack	*short_left;
	t_stack	*high_right;
	t_stack	*pivot;

	if (i_stack >= 2)
	{
		pivot = get_stack_of_index(stack_a, i_stack / 2);
		pivo_data = get_stack_of_index(stack_a, i_stack / 2)-> data;
		short_left = find_shortest_before_index(pivot,
				(i_stack + 1) / 2, pivo_data);
		high_right = find_highest_before_index(stack_a, i_stack / 2, pivo_data);
		if (short_left == NULL && high_right == NULL)
			sort_l_and_r_of_pivot(stack_a, pivot, i_stack / 2, i_stack);
		if (short_left == NULL && high_right != NULL)
			swap_data_then_sort(stack_a, pivot, i_stack, high_right);
		if (high_right == NULL && short_left != NULL)
			swap_data_then_sort(stack_a, pivot, i_stack, short_left);
		if (high_right != NULL && short_left != NULL)
			when_both_null(stack_a, i_stack, short_left, high_right);
	}
	if (i_stack < 2)
		if (get_stack_of_index(stack_a, 0)-> data
			> get_stack_of_index(stack_a, 1)-> data)
			swap_stack_date_pointer(stack_a -> next, stack_a);
}
