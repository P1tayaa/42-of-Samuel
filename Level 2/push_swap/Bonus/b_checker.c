/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_checker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:43:31 by sboulain          #+#    #+#             */
/*   Updated: 2023/04/29 13:51:19 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//print both stacks and it contants next to each others on the terminal
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

// check weather all inputs are numbers
bool	is_input_good(int argc, char **argv)
{
	long	number;
	int		isneg;
	int		i;
	int		j;

	i = 0;
	while (++i < argc)
	{
		number = 0;
		isneg = 0;
		j = -1;
		if (argv[i][j + 1] == '-')
			isneg = 1;
		while (argv[i][++j + isneg] != '\0')
		{
			if (!ft_isdigit(argv[i][j + isneg]))
				return (false);
			number = number * 10 + argv[i][j + isneg] - '0';
			if (number > 2147483647 || (number > 2147483648 && isneg))
				return (false);
		}
	}
	return (true);
}

//make sure there are no dup number in the stack
bool	make_sure_no_dup(t_stack *stack_a_full, int index_of_stack)
{
	int	*array_ints;
	int	i;
	int	j;

	array_ints = (int *)malloc((index_of_stack + 1) * sizeof(int));
	i = 0;
	while (i <= index_of_stack)
	{
		array_ints[i] = get_stack_of_index(stack_a_full, i)-> data;
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

//free both stack to make sure this is no leaks
void	free_stacks(t_two_stacks *stacks)
{
	int		i;
	t_stack	*temp_stack;

	i = stacks -> index_of_stacks;
	while (i >= 0)
	{
		temp_stack = get_stack_of_index(stacks -> stack_a, i);
		free(temp_stack);
		temp_stack = NULL;
		i--;
	}
	i = stacks -> index_of_stacks;
	while (i >= 0)
	{
		temp_stack = get_stack_of_index(stacks -> stack_b, i);
		free(temp_stack);
		temp_stack = NULL;
		i--;
	}
	free(stacks);
	stacks = NULL;
}

// check if the stack is sorted by make sure
// index are in incrementing by 1 and starting with 0
bool	is_stack_sorted(t_stack *stack);

void	checker(t_two_stacks *stacks);

int	main(int argc, char **argv)
{
	t_two_stacks	*stacks;

	if (argc < 2)
		return (ft_printf("no args\nError\n"));
	if (is_input_good(argc, argv) == false)
		return (ft_printf("args not int\nError\n"));
	stacks = make_stacks(argc, argv);
	if (make_sure_no_dup(stacks -> stack_a, stacks -> index_of_stacks) == false)
		return (free_stacks(stacks), ft_printf("dup int\nError\n"));
	index_values(stacks -> stack_a, stacks ->index_of_stacks);
	checker(stacks);
	if (is_stack_sorted(stacks -> stack_a))
		return (free_stacks(stacks), ft_printf("OK\n"));
	return (free_stacks(stacks), ft_printf("KO\n"));
}
