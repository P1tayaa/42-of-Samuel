/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_action_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:32:22 by sboulain          #+#    #+#             */
/*   Updated: 2023/02/17 19:01:05 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	ra_rotate_a(t_two_stacks *stacks, bool do_print)
{
	int	i;
	int	index_until_empty;

	index_until_empty = get_index_of_empty_index(stacks -> stack_a);
	i = 0;
	while (i < index_until_empty)
	{
		if (get_stack_of_index(stacks ->stack_a, i + 1) -> index_data != -1)
			swap_stack_date_pointer(
				get_stack_of_index(stacks ->stack_a, i),
				get_stack_of_index(stacks ->stack_a, i + 1));
		i = i + 1;
	}
	if (do_print)
		ft_printf("ra\n");
}

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rb_rotate_b(t_two_stacks *stacks, bool do_print)
{
	int	i;
	int	index_until_empty;

	index_until_empty = get_index_of_empty_index(stacks -> stack_b);
	i = 0;
	while (i < index_until_empty)
	{
		if (get_stack_of_index(stacks ->stack_b, i + 1) -> index_data != -1)
			swap_stack_date_pointer(
				get_stack_of_index(stacks ->stack_b, i),
				get_stack_of_index(stacks ->stack_b, i + 1));
		i = i + 1;
	}
	if (do_print)
		ft_printf("rb\n");
}

// rr : ra and rb at the same time.
void	rr_rotate_both(t_two_stacks *stacks, bool do_print)
{
	ra_rotate_a(stacks, false);
	rb_rotate_b(stacks, false);
	if (do_print)
		ft_printf("rr\n");
}

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	rra_reverse_rotate_a(t_two_stacks *stacks, bool do_print)
{
	int	index_until_empty;

	index_until_empty = get_index_of_empty_index(stacks -> stack_a);
	while (index_until_empty > 0)
	{
		if (get_stack_of_index(stacks ->stack_b, index_until_empty) -> index_data != -1)
			swap_stack_date_pointer(
				get_stack_of_index(stacks ->stack_a, index_until_empty),
				get_stack_of_index(stacks ->stack_a, index_until_empty - 1));
		index_until_empty--;
	}
	if (do_print)
		ft_printf("rra\n");
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	rrb_reverse_rotate_b(t_two_stacks *stacks, bool do_print)
{
	int	index_until_empty;

	index_until_empty = get_index_of_empty_index(stacks -> stack_b);
	while (index_until_empty > 0)
	{
		if (get_stack_of_index(stacks ->stack_b, index_until_empty) -> index_data != -1)
			swap_stack_date_pointer(
				get_stack_of_index(stacks ->stack_b, index_until_empty),
				get_stack_of_index(stacks ->stack_b, index_until_empty - 1));
		index_until_empty--;
	}
	if (do_print)
		ft_printf("rrb\n");
}
