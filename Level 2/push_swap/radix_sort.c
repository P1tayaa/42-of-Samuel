/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:37:32 by sboulain          #+#    #+#             */
/*   Updated: 2023/02/17 18:50:58 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


bool	is_byte_at_index(int num, int index)
{
	if (num >> index & 1)
		return (true);
	else 
		return (false);
}

int		get_largest_byte(int num)
{
	int		temp_max_bite;

	temp_max_bite = 31;
	while (!is_byte_at_index(num, temp_max_bite) && temp_max_bite != -1)
		temp_max_bite--;
	return (temp_max_bite);
}

int	find_largest_bit(t_stack *stack)
{
	int		max_bite;
	int		temp_max_bite;
	t_stack	*temp_stack;

	temp_stack = stack;
	max_bite = 0;
	while (temp_stack != NULL && temp_stack -> index_data != -1)
	{
		temp_max_bite = get_largest_byte(temp_stack -> index_data);
		if (temp_max_bite > max_bite)
		max_bite = temp_max_bite;
		temp_stack = temp_stack -> next;
	}
	// ft_printf("%d\n", max_bite);
	return (max_bite);
}

void	print_int_byte(int	num)
{
	int	i;
	
	i = 31;
	ft_printf("my num is = %d, ", num);
	while (i != -1)
	{
		ft_printf("%d ", num >> i);
		i--;
	}
	ft_printf("\n");
	
}

void	print_stacks_para(t_two_stacks *stacks);

void	put_largest_byte_a_to_b(t_two_stacks *stacks)
{
	int	max_bite;
	int	max_index;
	int	i;

	max_bite = find_largest_bit(stacks ->stack_a);
	i = 0;
	max_index = get_index_of_empty_index(stacks ->stack_a);
	while (i <= max_index)
	{
		// print_int_byte (stacks -> stack_a -> index_data);
		if (stacks -> stack_a -> index_data == -1 ||  max_bite != find_largest_bit(stacks ->stack_a))
			break ;
		if (is_byte_at_index(stacks -> stack_a -> index_data, max_bite))
			pb_push_b(stacks, true);
		else
			ra_rotate_a(stacks, true);		
		i++;
	}
}

void	move_b_to_a_in_right_order(t_two_stacks *stacks)
{
	int	current_byte_size;
	int	number_of_stack_of_byte_size;
	int	index_smallest;
	int	index_biggest;
	
	// print_stacks_para(stacks);
	if (get_stack_of_index(stacks -> stack_a, 0) -> index_data < get_stack_of_index(stacks -> stack_a, 1) -> index_data)
		sa_swap_a(stacks, true);
	current_byte_size = get_largest_byte(stacks -> stack_b -> index_data);
	number_of_stack_of_byte_size = 0;
	index_smallest = 0;
	index_biggest = 0;
	while (current_byte_size == get_largest_byte(get_stack_of_index(stacks -> stack_b, number_of_stack_of_byte_size) -> index_data))
	{
		// if (get_stack_of_index(stacks -> stack_b, number_of_stack_of_byte_size) -> index_data > get_stack_of_index(stacks -> stack_b, index_biggest) -> index_data)
		// 	index_biggest = number_of_stack_of_byte_size;
		if (get_stack_of_index(stacks -> stack_b, number_of_stack_of_byte_size) -> index_data < get_stack_of_index(stacks -> stack_b, index_smallest) -> index_data)
			index_smallest = number_of_stack_of_byte_size;
		number_of_stack_of_byte_size++;
	}
	// ft_printf("%d\n", index_smallest);
	int	i;
	int	j;
	bool	has_pa;

	j = 0;
	// while (j != number_of_stack_of_byte_size / 2)
	// {
		
		i = 0;
		has_pa = false;
		while (i < number_of_stack_of_byte_size)
		{
			// print_stacks_para(stacks);
			if (get_stack_of_index(stacks -> stack_b, 0) -> index_data > get_stack_of_index(stacks -> stack_b, 1) -> index_data && get_stack_of_index(stacks -> stack_b, 1) -> index_data != -1)
			{
				// print_stacks_para(stacks);
				sb_swap_b(stacks, true);
				if (i + 1 == index_smallest && has_pa == false)
				{
					// print_stacks_para(stacks);
					pa_push_a(stacks, true);
					has_pa = true;	
					break ;
				}
			}
			else
				if (i == index_smallest && has_pa == false)
				{
					// print_stacks_para(stacks);
					pa_push_a(stacks, true);
					has_pa = true;
					break ;
				}
			if (stacks -> stack_b -> index_data != -1)
			{
				// print_stacks_para(stacks);
				rb_rotate_b(stacks, true);

			}
			i++;
		}
		while (i > 0)
		{
			// print_stacks_para(stacks);
			rrb_reverse_rotate_b(stacks, true);
			i--;
		}
		j++;
	// }
	i = 0;
	while (get_largest_byte(get_stack_of_index(stacks -> stack_b, i) -> index_data) == current_byte_size)
	{
		// print_stacks_para(stacks);
		pa_push_a(stacks, true);
		i++;
	}
	
	
	
	
	

	// if (get_stack_of_index(stacks -> stack_a, 0) -> index_data < get_stack_of_index(stacks -> stack_a, 1) -> index_data)
	// {
	// 	if (get_stack_of_index(stacks -> stack_b, 0) -> index_data > get_stack_of_index(stacks -> stack_b, 1) -> index_data)
	// 		ss_swap_both(stacks, true);
	// 	else
	// 		sa_swap_a(stacks, true);
	// }
	// if (get_stack_of_index(stacks -> stack_b, 0) -> index_data > get_stack_of_index(stacks -> stack_b, 1) -> index_data)
	// 	sb_swap_b(stacks, true);
	// pa_push_a(stacks, true);
	// pa_push_a(stacks, true);
}

void	radix_sort(t_two_stacks *stacks)
{
	
	// while (find_largest_bit(stacks -> stack_a) != 0)
	// {
	// 	// put_largest_byte_a_to_b(stacks);
	// 	print_stacks_para(stacks);
	// }

	// ft_printf("\n");
	// while (stacks -> stack_b -> index_data != -1)
	// {
	// 	// move_b_to_a_in_right_order(stacks);
	// 	// move_b_to_a_in_right_order(stacks);
	// 	// move_b_to_a_in_right_order(stacks);
	// }
			// print_stacks_para(stacks);
	int	i;
	int j;
	int	num_in_stack_b;

	i = 0;
	num_in_stack_b = 0;
	while (!is_stack_sorted(stacks -> stack_a))
	{
		num_in_stack_b = 0;
		j = 0;
		while ((j <= (stacks -> index_of_stacks)))
		{
				// ft_printf("pb");
			if ((((stacks -> stack_a -> index_data) >> i) & 1) == 0)
			{
				pb_push_b(stacks, true);
				num_in_stack_b++;
			}
			else
				ra_rotate_a(stacks, true);
			j++;
		}
		while (num_in_stack_b >= 0)
		{
			// ft_printf("pa");
			pa_push_a(stacks, true);
			num_in_stack_b--;
		}
		// print_stacks_para(stacks);
		// ft_printf("%d\n", stacks -> index_of_stacks);
		i++;
	}
	


	// print_stacks_para(stacks);
	// ! wong
	// while (stacks ->stack_b -> index_data != -1)
	// {
	// 	move_b_to_a_in_right_order(stacks);
	// 	if (get_stack_of_index(stacks -> stack_b, 4) -> index_data != -1)
	// 	{
	// 		pa_push_a(stacks, true);
	// 		pa_push_a(stacks, true);
	// 	}
	// 	print_stacks_para(stacks);
	// }
}