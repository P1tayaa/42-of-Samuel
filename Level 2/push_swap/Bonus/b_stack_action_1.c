/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_action_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:32:22 by sboulain          #+#    #+#             */
/*   Updated: 2023/04/04 18:13:18 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"


// * from stack_change_tools.c
void	make_first_element_last_stack(t_stack *stack);

void	bring_empty_to_first_stack(t_stack *stack);

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	sa_swap_a(t_two_stacks *stacks, bool do_print)
{
	swap_stack_date_pointer(
		get_stack_of_index(stacks -> stack_a, 0),
		get_stack_of_index(stacks -> stack_a, 1));
	if (do_print)
		ft_printf("sa\n");
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	sb_swap_b(t_two_stacks *stacks, bool do_print)
{
	swap_stack_date_pointer(
		get_stack_of_index(stacks -> stack_b, 0),
		get_stack_of_index(stacks -> stack_b, 1));
	if (do_print)
		ft_printf("sb\n");
}

// ss : sa and sb at the same time.
void	ss_swap_both(t_two_stacks *stacks, bool do_print)
{
	sb_swap_b(stacks, false);
	sa_swap_a(stacks, false);
	if (do_print)
		ft_printf("ss\n");
}

// pa (push a): Take the first element at the top of b 
//and put it at the top of a.
void	pa_push_a(t_two_stacks *stacks, bool do_printf)
{
	if (stacks -> stack_b -> index_data == -1)
		return ;
	bring_empty_to_first_stack(stacks -> stack_a);
	if (stacks -> stack_b -> next -> index_data == -1)
		swap_stack_date_pointer(
			get_stack_of_index(stacks -> stack_b, 0),
			get_stack_of_index(stacks -> stack_a, 0));
	else
	{
		swap_stack_date_pointer(
			get_stack_of_index(stacks -> stack_a, 0),
			get_stack_of_index(stacks -> stack_b, 0));
		make_first_element_last_stack(stacks -> stack_b);
	}
	if (do_printf)
		ft_printf("pa\n");
}

// pb (push b): Take the first element at the top of a 
//and put it at the top of b.
void	pb_push_b(t_two_stacks *stacks, bool do_printf)
{
	if (stacks -> stack_a -> index_data == -1)
		return ;
	bring_empty_to_first_stack(stacks -> stack_b);
	if (stacks -> stack_a -> next -> index_data == -1)
		swap_stack_date_pointer(
			get_stack_of_index(stacks -> stack_a, 0),
			get_stack_of_index(stacks -> stack_b, 0));
	else
	{
		swap_stack_date_pointer(
			get_stack_of_index(stacks -> stack_b, 0),
			get_stack_of_index(stacks -> stack_a, 0));
		make_first_element_last_stack(stacks -> stack_a);
	}
	if (do_printf)
		ft_printf("pb\n");
}
