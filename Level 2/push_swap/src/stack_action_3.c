/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_action_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:32:22 by sboulain          #+#    #+#             */
/*   Updated: 2023/05/17 21:25:54 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rrr : rra and rrb at the same time.
void	rrr_reverse_rotate_both(t_two_stacks *stacks, bool do_print)
{
	ra_rotate_a(stacks, false);
	rb_rotate_b(stacks, false);
	if (do_print)
		ft_printf("rra\n");
}

// * last thing I added and I didn't to add a file sorry

//short for 3 numbers
void	short_sort_three(t_two_stacks *sta)
{
	const int	index_num_0 = get_stack_of_index(sta->stack_a, 0)-> index_data;
	const int	index_num_1 = get_stack_of_index(sta->stack_a, 1)-> index_data;
	const int	index_num_2 = get_stack_of_index(sta->stack_a, 2)-> index_data;

	if (index_num_0 > index_num_1 && index_num_1 > index_num_2)
	{
		sa_swap_a(sta, true);
		ra_rotate_a(sta, true);
		ra_rotate_a(sta, true);
	}
	else if (index_num_0 > index_num_1 && index_num_1 < index_num_2
		&& index_num_0 < index_num_2)
		sa_swap_a(sta, true);
	else if (index_num_0 > index_num_1 && index_num_1 < index_num_2
		&& index_num_0 > index_num_2)
		ra_rotate_a(sta, true);
	else if (index_num_0 < index_num_1 && index_num_1 > index_num_2)
	{
		sa_swap_a(sta, true);
		ra_rotate_a(sta, true);
	}
}

//for short sort
void	sort_fuse_1(t_two_stacks *sta)
{
	if (get_stack_of_index(sta->stack_b, 0)-> index_data == 0)
	{
		pa_push_a(sta, true);
	}
	else if (get_stack_of_index(sta->stack_b, 0)-> index_data == 1)
	{
		pa_push_a(sta, true);
		sa_swap_a(sta, true);
	}
	else if (get_stack_of_index(sta->stack_b, 0)-> index_data == 2)
	{
		ra_rotate_a(sta, true);
		pa_push_a(sta, true);
		sa_swap_a(sta, true);
		rra_reverse_rotate_a(sta, true);
	}
	else if (get_stack_of_index(sta->stack_b, 0)-> index_data == 3)
	{
		pa_push_a(sta, true);
		ra_rotate_a(sta, true);
	}
}

//for short sort
void	sort_fuse_2(t_two_stacks *sta)
{
	if (get_stack_of_index(sta->stack_b, 0)-> index_data == 1)
	{
		pa_push_a(sta, true);
		sa_swap_a(sta, true);
	}
	else if (get_stack_of_index(sta->stack_b, 0)-> index_data == 2)
	{
		ra_rotate_a(sta, true);
		pa_push_a(sta, true);
		sa_swap_a(sta, true);
		rra_reverse_rotate_a(sta, true);
	}
	else if (get_stack_of_index(sta->stack_b, 0)-> index_data == 3)
	{
		rra_reverse_rotate_a(sta, true);
		pa_push_a(sta, true);
		ra_rotate_a(sta, true);
		ra_rotate_a(sta, true);
	}
	else if (get_stack_of_index(sta->stack_b, 0)-> index_data == 4)
	{
		pa_push_a(sta, true);
		ra_rotate_a(sta, true);
	}
}

void	med_short_sort(t_two_stacks *sta)
{
	pb_push_b(sta, true);
	short_sort_three(sta);
	sort_fuse_1(sta);
}
