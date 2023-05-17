/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:37:32 by sboulain          #+#    #+#             */
/*   Updated: 2023/05/17 13:14:43 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_largest_byte(int num)
{
	int		temp_max_bite;

	temp_max_bite = 31;
	while (!((num >> temp_max_bite) & 1) && temp_max_bite != -1)
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
	return (max_bite);
}

void	print_int_byte(int num)
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
		if (stacks -> stack_a -> index_data == -1
			|| max_bite != find_largest_bit(stacks ->stack_a))
			break ;
		if ((stacks -> stack_a -> index_data >> max_bite) & 1)
			pb_push_b(stacks, true);
		else
			ra_rotate_a(stacks, true);
		i++;
	}
}

// * So how does it work?
// so because I index everything, the higher the number the higher the 1 
// is the the byte storage
// So 1 is like 00000001
// and 0 is     00000000
// and 2 is     00000010
// so I look at the fist byte, if it is a one I put it in b stack otherwise
// I put it at the bottom of stack a, when I did that for all my stack, 
// I put all of b in a and do it again,
// so in the stack a all the 1 are above the 0,
// then I do that for the next byte, and by the end it 
// will be sorted because the higher values have more 1s
// doing it with base 10 also work for humain
void	radix_sort(t_two_stacks *stacks)
{
	int	i;
	int	j;
	int	num_in_stack_b;

	i = 0;
	num_in_stack_b = 0;
	while (!is_stack_sorted(stacks -> stack_a))
	{
		num_in_stack_b = 0;
		j = -1;
		while ((++j <= (stacks -> index_of_stacks)))
		{
			if ((((stacks -> stack_a -> index_data) >> i) & 1) == 0)
			{
				pb_push_b(stacks, true);
				num_in_stack_b++;
			}
			else
				ra_rotate_a(stacks, true);
		}
		num_in_stack_b++;
		while (--num_in_stack_b >= 0)
			pa_push_a(stacks, true);
		i++;
	}
}
