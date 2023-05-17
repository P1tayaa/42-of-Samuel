/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:18:54 by sboulain          #+#    #+#             */
/*   Updated: 2023/05/17 18:58:06 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// // ! need to be commentated
// void	leaks_chec(void)
// {
// 	system("leaks -q push_swap");
// }

// //print one stack and it contants
// void	print_stack(t_stack *stack)
// {
// 	while (stack != NULL)
// 	{
// 		ft_printf("data: %d, index %d, is_val %d\n",
// 			stack -> data, stack -> index_data, stack ->has_data);
// 		stack = stack -> next;
// 	}
// }

// //print both stacks and it contants
// void	print_stacks(t_two_stacks *stacks)
// {
// 	ft_printf("stack a:\n");
// 	print_stack(stacks -> stack_a);
// 	ft_printf("stack b:\n");
// 	print_stack(stacks -> stack_b);
// }

// //print both stacks and it contants next to each others on the terminal
void	print_stacks_para(t_two_stacks *stacks);
// {
// 	t_stack	*stack_a_temp;
// 	t_stack	*stack_b_temp;

// 	stack_a_temp = stacks -> stack_a;
// 	stack_b_temp = stacks -> stack_b;
// 	while (stack_a_temp != NULL || stack_b_temp != NULL)
// 	{
// 		ft_printf("data: %d, index %d, is_val %d          ",
// 			stack_a_temp -> data,
// 			stack_a_temp -> index_data, stack_a_temp ->has_data);
// 		ft_printf("data: %d, index %d, is_val %d\n",
// 			stack_b_temp -> data,
// 			stack_b_temp -> index_data, stack_b_temp ->has_data);
// 		stack_a_temp = stack_a_temp -> next;
// 		stack_b_temp = stack_b_temp -> next;
// 	}
// }

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
		if (argv[i][0] == '\0' || (argv[i][0] == '-' && argv[i][1] == '\0'))
			return (false);
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
	if (!array_ints)
		exit(1);
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

//check if the stack is sorted by make sure 
// index are in incrementing by 1 and starting with 0
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
//don't want to do it cleanly for these two,
// you can find the code in stack_action_3.c
void	short_sort_three(t_two_stacks *sta);

//don't want to do it cleanly for these two,
// you can find the code in stack_action_3.c
void	med_short_sort(t_two_stacks *sta);

int	main(int argc, char **argv)
{
	t_two_stacks	*stacks;

	if (is_input_good(argc, argv) == false)
		return (ft_printf("args not int\nError\n"));
	if (argc < 3)
		return (ft_printf("\n"));
	stacks = make_stacks(argc, argv);
	if (make_sure_no_dup(stacks -> stack_a, stacks -> index_of_stacks) == false)
		return (free_stacks(stacks), ft_printf("dup int\nError\n"));
	index_values(stacks -> stack_a, stacks ->index_of_stacks);
	if (is_stack_sorted(stacks -> stack_a))
		return (free_stacks(stacks), ft_printf("\n"));
	if (argc == 5)
	{
		med_short_sort(stacks);
	}
	if (argc == 4)
	{
		short_sort_three(stacks);
		return (free_stacks(stacks), 1);
	}
	if (short_sort(stacks))
		return (free_stacks(stacks), 1);
	radix_sort(stacks);
	free_stacks(stacks);
}

// * better main for debuging and understanding
// int		main(int argc, char **argv)
// {
// 	t_two_stacks	*stacks;
// 	// ! need to be commanted
// 	atexit(leaks_chec);
// 	// !
// 	if (argc < 2)
// 		return (ft_printf("not enought args\nError\n"));
// 	if (is_input_good(argc, argv) == false)
// 		return (ft_printf("args not int\nError\n"));
// 	stacks = make_stacks(argc, argv);
// 	if (make_sure_no_dup(stacks -> stack_a, stacks -> index_of_stacks) == false)
// 		return (free_stacks(stacks),ft_printf("dup int\nError\n"));
// 	index_values(stacks -> stack_a, stacks ->index_of_stacks);
// 	if (is_stack_sorted(stacks -> stack_a))
// 		return (free_stacks(stacks), ft_printf("already sorted\n"));
// 	if (short_sort(stacks))
// 		return (free_stacks(stacks), ft_printf("did short sort\n"));
// 	radix_sort(stacks);
// 	print_stacks_para(stacks);
// 	free_stacks(stacks);
// }
