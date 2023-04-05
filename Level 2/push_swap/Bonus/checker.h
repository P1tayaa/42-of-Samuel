/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:47:04 by sboulain          #+#    #+#             */
/*   Updated: 2023/04/04 17:59:50 by sboulain         ###   ########.fr       */
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

// * push_swap.c
bool			is_stack_sorted(t_stack *stack);

// * stack_making.c
t_two_stacks	*make_stacks(int argc, char **argv);

// * index_stacks.c
void			index_values(t_stack *stack_a, int index_of_stack);

// * stack_change_tools.c
void			swap_stack_date_pointer(t_stack *stack_1, t_stack *stack_2);

t_stack			*get_stack_of_index(t_stack *first_stack, int index);

int				get_index_of_empty_index(t_stack *stack);


// * stack_action_1.c
// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void			sa_swap_a(t_two_stacks *stacks, bool do_print);

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void			sb_swap_b(t_two_stacks *stacks, bool do_print);

// ss : sa and sb at the same time.
void			ss_swap_both(t_two_stacks *stacks, bool do_print);

// pa (push a): Take the first element at the top of b 
//and put it at the top of a.
void			pa_push_a(t_two_stacks *stacks, bool do_printf);

// pb (push b): Take the first element at the top of a 
//and put it at the top of b.
void			pb_push_b(t_two_stacks *stacks, bool do_printf);

// * stack_action_2.c

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
void			ra_rotate_a(t_two_stacks *stacks, bool do_print);

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void			rb_rotate_b(t_two_stacks *stacks, bool do_print);

// rr : ra and rb at the same time.
void			rr_rotate_both(t_two_stacks *stacks, bool do_print);

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
void			rra_reverse_rotate_a(t_two_stacks *stacks, bool do_print);

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
void			rrb_reverse_rotate_b(t_two_stacks *stacks, bool do_print);

// * stack_action_3.c

// rrr : rra and rrb at the same time.
void			rrr_reverse_rotate_both(t_two_stacks *stacks, bool do_print);

#endif
