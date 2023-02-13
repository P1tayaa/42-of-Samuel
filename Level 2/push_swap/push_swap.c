/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:18:54 by sboulain          #+#    #+#             */
/*   Updated: 2023/02/13 16:32:13 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	// ft_printf("pointer: %p\n", stack);
	while (stack != NULL)
	{
		ft_printf("data: %d, index %d, is_val %d\n", stack -> data, stack -> index_data, stack ->has_data);
		stack = stack -> next;
	}
}

void	print_stacks(t_two_stacks *stacks)
{
	ft_printf("stack a:\n");
	print_stack(stacks -> stack_a);
	ft_printf("stack b:\n");
	print_stack(stacks -> stack_b);
}

void	print_stacks_para(t_two_stacks *stacks)
{
	t_stack	*stack_a_temp;
	t_stack	*stack_b_temp;

	

	stack_a_temp = stacks -> stack_a;
	stack_b_temp = stacks -> stack_b;
	while (stack_a_temp != NULL || stack_b_temp != NULL)
	{
		ft_printf("data: %d, index %d, is_val %d          ", stack_a_temp -> data, stack_a_temp -> index_data, stack_a_temp ->has_data);
		ft_printf("data: %d, index %d, is_val %d\n", stack_b_temp -> data, stack_b_temp -> index_data, stack_b_temp ->has_data);
		stack_a_temp = stack_a_temp -> next;
		stack_b_temp = stack_b_temp -> next;
	}
}

bool	is_input_good(int argc, char **argv)
{
	long	number;
	int		isneg;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		number = 0;
		isneg = 0;
		j = 0;
		if (argv[i][j] == '-')
		{
			j++;
			isneg = 1;
		}
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				return (false);
			number = number * 10 + argv[i][j] - '0';
			if (number > 2147483647 || (number > 2147483648 && isneg))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	make_sure_no_dup(t_stack *stack_a_full, int index_of_stack)
{
	int	*array_ints;
	int	i;
	int	j;

	array_ints = (int *)malloc((index_of_stack + 1) * sizeof(int));
	i = 0;
	while (i <= index_of_stack)
	{
		array_ints[i] = get_stack_of_index(stack_a_full, i) -> data;
		j = 0;
		while (j < i)
		{
			if (array_ints[j] == array_ints[i])
				return (free(array_ints), false);
			j++;
		}
		i++;
	}
	free(array_ints);
	return (true);
}

void	free_stacks(t_two_stacks *stacks)
{
	int		i;
	t_stack	*temp_stack;

	i = stacks -> index_of_stacks;
	while (i >= 0)
	{
		temp_stack = get_stack_of_index(stacks->stack_a,i);
		free(temp_stack);
		temp_stack = NULL;
		i--;
	}
	i = stacks -> index_of_stacks;
	while (i >= 0)
	{
		temp_stack = get_stack_of_index(stacks->stack_b,i);
		free(temp_stack);
		temp_stack = NULL;
		i--;
	}
	free(stacks);
	stacks = NULL;
}

void 	leaks_chec(void)
{
	system("leaks -q push_swap");
}

bool	is_stack_sorted(t_stack *stack)
{
	int	i;
	t_stack *temp_stack;

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


int			main(int argc, char **argv)
{
	t_two_stacks *stacks;
	//error handeling
	atexit(leaks_chec);
	if (argc < 2)
		return (ft_printf("not enought args\nError\n"));
	if (is_input_good(argc, argv) == false)
		return (ft_printf("args not int\nError\n"));
	stacks = make_stacks(argc, argv);
	if (make_sure_no_dup(stacks -> stack_a, stacks -> index_of_stacks) == false)
		return (free_stacks(stacks),ft_printf("dup int\nError\n"));
	index_values(stacks -> stack_a, stacks ->index_of_stacks);
	if (is_stack_sorted(stacks -> stack_a))
		return (free_stacks(stacks), ft_printf("already sorted\n"));

	radix_sort(stacks);
	// print_stacks_para(stacks);

	// print_stack(get_stack_of_index(stacks -> stack_a, 1));
	// swap_stack_date_pointer(get_stack_of_index(stacks -> stack_a, 0),get_stack_of_index(stacks -> stack_a, 1));
	// stacks = make_stacks(argc, argv);
	// print_stacks(stacks);
	
	free_stacks(stacks);

	// ft_printf("%d", ft_atoi(argv[1]));
}
