/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:41:22 by sboulain          #+#    #+#             */
/*   Updated: 2023/02/09 15:50:43 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// for malloc and free
# include <stdlib.h>
// for bool
# include <stdbool.h>
# include "mega_libft/libft.h"

typedef struct s_stack
{
	int				data;
	int				index_data;
	bool			has_data;
	struct s_stack	*next;

}	t_stack;

typedef struct s_two_stacks
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	int				index_of_stacks;

}	t_two_stacks;

// * stack_making.c
t_two_stacks	*make_stacks(int argc, char **argv);


// * index_stacks.c
void			index_values(t_stack *stack_a, int index_of_stack);


// * stack_change_tools.c
void			swap_stack_date_pointer(t_stack *stack_1, t_stack *stack_2);

t_stack			*get_stack_of_index(t_stack *first_stack, int index);


// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }					t_list;

// typedef struct s_list_int
// {
// 	struct
// };

#endif
