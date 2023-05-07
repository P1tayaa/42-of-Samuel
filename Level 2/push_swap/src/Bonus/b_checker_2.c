/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_checker_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:25:40 by sboulain          #+#    #+#             */
/*   Updated: 2023/05/07 11:24:13 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

bool	checker_part_2(char	*line, t_two_stacks *stacks)
{
	if (ft_strncmp(line, "ra\n", 3) == 0)
		ra_rotate_a(stacks, false);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb_rotate_b(stacks, false);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr_rotate_both(stacks, false);
	else if (ft_strncmp(line, "rra\n", 3) == 0)
		rra_reverse_rotate_a(stacks, false);
	else if (ft_strncmp(line, "rrb\n", 3) == 0)
		rrb_reverse_rotate_b(stacks, false);
	else if (ft_strncmp(line, "rrr\n", 3) == 0)
		rrr_reverse_rotate_both(stacks, false);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa_push_a(stacks, false);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb_push_b(stacks, false);
	else
	{
		return (false);
	}
	return (true);
}

void	checker(t_two_stacks *stacks)
{
	char	*line;

	if (is_stack_sorted(stacks -> stack_a))
		return ;
	line = get_next_line(1);
	while (line != NULL)
	{
		if (is_stack_sorted(stacks -> stack_a))
			return ;
		if (ft_strncmp(line, "sa\n", 3) == 0)
			sa_swap_a(stacks, false);
		else if (ft_strncmp(line, "sb\n", 3) == 0)
			sb_swap_b(stacks, false);
		else if (ft_strncmp(line, "ss\n", 3) == 0)
			ss_swap_both(stacks, false);
		else
			if (checker_part_2(line, stacks) == false)
				break ;
		if (is_stack_sorted(stacks -> stack_a))
			return ;
		line = get_next_line(1);
	}
}

bool	is_stack_sorted(t_stack *stack)
{
	int		i;
	t_stack	*temp_stack;

	i = 0;
	temp_stack = stack;
	while (temp_stack -> next != NULL)
	{
		if (temp_stack -> index_data != i)
			return (false);
		temp_stack = temp_stack -> next;
		i++;
	}
	return (true);
}
