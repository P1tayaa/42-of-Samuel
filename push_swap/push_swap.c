/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:18:54 by sboulain          #+#    #+#             */
/*   Updated: 2023/01/29 14:04:03 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack_pointer(t_stack *stack_1, t_stack *stack_2)
{
	int		temp_int;

	temp_int = stack_1 -> data;
	stack_1 -> data = stack_2 ->data;
	stack_2 ->data = temp_int;
	temp_int = stack_1 -> index_data;
	stack_1 -> index_data = stack_2 ->index_data;
	stack_2 ->index_data = temp_int;
}

t_stack	*get_stack_of_index(t_stack *first_stack, int index)
{
	int	i;
	t_stack	*stack_temp;

	i = 0;
	stack_temp = first_stack;
	while (i != index)
	{
		stack_temp = stack_temp -> next;
		i++;
	}
	return (stack_temp);
}

t_stack	*make_single_stack(int val)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack ->data = val;
	stack -> next = NULL;
	return (stack);
}

void print_stack(t_stack *stack)
{
	// ft_printf("pointer: %p\n", stack);
	while (stack != NULL)
	{
		ft_printf("data: %d, index %d\n", stack -> data, stack -> index_data);
		stack = stack -> next;
	}
}

void print_stacks(t_two_stacks *stacks)
{
	ft_printf("stack a:\n");
	print_stack(stacks -> stack_a);
	ft_printf("stack b:\n");
	print_stack(stacks -> stack_b);
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
	stacks -> stack_a = make_single_stack(ft_atoi(argv[i]));
	stacks -> stack_a -> index_data = -1;
	temp_stack = stacks -> stack_a;
	ft_printf("i: %d, argc: %d\n", i, argc);
	while (i < argc - 1)
	{
		i++;
		temp_stack -> next = make_single_stack(ft_atoi(argv[i]));
		temp_stack = temp_stack -> next;
		temp_stack -> index_data = -1;
	}
	stacks -> stack_b = NULL;
	return (stacks);
}

int			is_input_good(int argc, char **argv)
{
	long	number;
	int		isneg;
	int		i;
	int		j;

	i = 1;
	isneg = 0;
	number = 0;
	while (i < argc)
	{
		j = 0;
		if (i == 1 && argv[i][j] == '-')
		{
			j++;
			isneg = 1;
		}
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			number = number * 10 + argv[i][j] - '0';
			if (number > 2147483647 || (number > 2147483648 && isneg))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void		idex_stack_a(t_stack *stack, int size_stack)
{
	int		i;
	int		j;
	int		curent_index;
	int		last_small_data;
	t_stack	*temp_stack;

	i = 0;
	curent_index = 0;
	while (i < size_stack)
	{
		j = 0;
		temp_stack = stack;
		while (j < size_stack)
		{
			
			temp_stack = temp_stack -> n;
			j++;
		}
		i++;
	}
	
}

int			main(int argc, char **argv)
{
	t_two_stacks *stacks;
	//error handeling
	if (argc < 2)
		return (ft_printf("not enought args\nError\n"));
	if (!is_input_good(argc, argv))
		return (ft_printf("args not int\nError\n"));
	stacks = make_stacks(argc, argv);
	print_stacks(stacks);
	// print_stack(get_stack_of_index(stacks -> stack_a, 1));
	swap_stack_pointer(get_stack_of_index(stacks -> stack_a, 0),get_stack_of_index(stacks -> stack_a, 1));
	// stacks = make_stacks(argc, argv);
	print_stacks(stacks);

	// ft_printf("%d", ft_atoi(argv[1]));
}
