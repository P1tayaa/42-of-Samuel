/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_making.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:25:53 by sboulain          #+#    #+#             */
/*   Updated: 2023/02/13 12:25:40 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*make_single_stack(int val, bool as_data)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack ->data = val;
	if (as_data == true)
		stack ->has_data = true;
	else
		stack ->has_data = false;
	stack -> index_data = -1;
	stack -> next = NULL;
	return (stack);
}

t_stack	*make_emty_stack_with_len(int len_of_stack)
{
	t_stack	*stack_emty;
	t_stack	*temp_stack;
	int		i;

	stack_emty = make_single_stack(0, false);
	temp_stack = stack_emty;
	i = 0;
	// ft_printf("i: %d, argc: %d\n", i, len_of_stack);
	i++;
	while (i < len_of_stack)
	{
		temp_stack -> next = make_single_stack(0, false);
		temp_stack = temp_stack -> next;
		i++;
	}
	return (stack_emty);
}

t_two_stacks	*make_stacks(int argc, char **argv)
{
	t_two_stacks	*stacks;
	t_stack			*temp_stack;
	int				i;

	i = 1;
	temp_stack = NULL;
	stacks = (t_two_stacks *)malloc(sizeof(t_two_stacks));
	if (stacks == NULL)
		exit(-1);
	stacks -> stack_a = make_single_stack(ft_atoi(argv[i]), true);
	temp_stack = stacks -> stack_a;
	// ft_printf("i: %d, argc: %d\n", i, argc);
	while (i < argc - 1)
	{
		i++;
		temp_stack -> next = make_single_stack(ft_atoi(argv[i]), true);
		temp_stack = temp_stack -> next;
	}
	stacks -> stack_b = make_emty_stack_with_len(argc - 1);
	stacks -> index_of_stacks = argc - 2;
	return (stacks);
}
