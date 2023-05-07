/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:07:54 by sboulain          #+#    #+#             */
/*   Updated: 2023/05/07 12:18:26 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks_para(t_two_stacks *stacks)
{
	t_stack	*stack_a_temp;
	t_stack	*stack_b_temp;

	stack_a_temp = stacks -> stack_a;
	stack_b_temp = stacks -> stack_b;
	while (stack_a_temp != NULL || stack_b_temp != NULL)
	{
		ft_printf("data: %d, index %d, is_val %d          ",
			stack_a_temp -> data,
			stack_a_temp -> index_data, stack_a_temp ->has_data);
		ft_printf("data: %d, index %d, is_val %d\n",
			stack_b_temp -> data,
			stack_b_temp -> index_data, stack_b_temp ->has_data);
		stack_a_temp = stack_a_temp -> next;
		stack_b_temp = stack_b_temp -> next;
	}
}

void	sort_first_and_go_b(t_two_stacks *sta)
{
	const int	index_num_0 = get_stack_of_index(sta->stack_a, 0)-> index_data;
	const int	index_num_1 = get_stack_of_index(sta->stack_a, 1)-> index_data;
	const int	index_num_2 = get_stack_of_index(sta->stack_a, 2)-> index_data;

	if (index_num_2 < index_num_0 && index_num_2 < index_num_1)
	{
		if (index_num_0 > index_num_1)
			sa_swap_a(sta, true);
		pb_push_b(sta, true);
		sa_swap_a(sta, true);
		pb_push_b(sta, true);
		sb_swap_b(sta, true);
		return ;
	}
	if (index_num_1 < index_num_0 && index_num_1 < index_num_2)
		sa_swap_a(sta, true);
	pb_push_b(sta, true);
	if (index_num_1 > index_num_2)
		sa_swap_a(sta, true);
	pb_push_b(sta, true);
	pb_push_b(sta, true);
}

void	fuse_and_sort_stacks(t_two_stacks *sta)
{
	const int	b_0 = get_stack_of_index(sta->stack_b, 0)-> index_data;
	const int	b_1 = get_stack_of_index(sta->stack_b, 1)-> index_data;
	const int	b_2 = get_stack_of_index(sta->stack_b, 2)-> index_data;

	if (get_stack_of_index(sta->stack_a, 0)-> index_data
		> get_stack_of_index(sta->stack_a, 1)-> index_data)
		sa_swap_a(sta, true);
	pa_push_a(sta, true);
	if (b_0 > get_stack_of_index(sta->stack_a,
			get_index_of_empty_index(sta->stack_a) - 1)-> index_data)
		ra_rotate_a(sta, true);
	else if (b_0 > get_stack_of_index(sta->stack_a, 1)-> index_data)
		sa_swap_a(sta, true);
	pa_push_a(sta, true);
	if (b_1 > get_stack_of_index(sta->stack_a,
			get_index_of_empty_index(sta->stack_a) - 1)-> index_data)
		ra_rotate_a(sta, true);
	else if (b_1 > get_stack_of_index(sta->stack_a, 1)-> index_data)
		sa_swap_a(sta, true);
	pa_push_a(sta, true);
	if (b_2 > get_stack_of_index(sta->stack_a,
			get_index_of_empty_index(sta->stack_a) - 1)-> index_data)
		ra_rotate_a(sta, true);
	else if (b_2 > get_stack_of_index(sta->stack_a, 1)-> index_data)
		sa_swap_a(sta, true);
}

bool	if_max_at_end(t_two_stacks *sta)
{
	if (get_stack_of_index(sta->stack_a, 0)-> index_data
		> get_stack_of_index(sta->stack_a, 1)-> index_data
		&& get_stack_of_index(sta->stack_a, 1)-> index_data
		> get_stack_of_index(sta->stack_a, 2)-> index_data
		&& get_stack_of_index(sta->stack_a, 2)-> index_data
		> get_stack_of_index(sta->stack_a, 3)-> index_data
		&& get_stack_of_index(sta->stack_a, 3)-> index_data
		> get_stack_of_index(sta->stack_a, 4)-> index_data)
	{
		sa_swap_a(sta, true);
		rra_reverse_rotate_a(sta, true);
		rra_reverse_rotate_a(sta, true);
		sa_swap_a(sta, true);
		rra_reverse_rotate_a(sta, true);
		rra_reverse_rotate_a(sta, true);
		sa_swap_a(sta, true);
		rra_reverse_rotate_a(sta, true);
		sa_swap_a(sta, true);
		ra_rotate_a(sta, true);
		ra_rotate_a(sta, true);
		ra_rotate_a(sta, true);
		return (true);
	}
	return (false);
}

bool	short_sort(t_two_stacks *sta)
{
	if (get_index_of_empty_index(sta->stack_a) > 4)
		return (false);
	if (get_index_of_empty_index(sta->stack_a) < 2)
	{
		if (get_index_of_empty_index(sta->stack_a) == 1)
			if (sta->stack_a->index_data > sta->stack_a->next->index_data)
				sa_swap_a(sta, true);
		return (true);
	}
	if (if_max_at_end(sta) == true)
	{
		print_stacks_para(sta);
		return (true);
	}
	sort_first_and_go_b(sta);
	fuse_and_sort_stacks(sta);
	return (true);
}
