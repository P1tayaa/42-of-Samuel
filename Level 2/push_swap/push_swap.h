/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:41:22 by sboulain          #+#    #+#             */
/*   Updated: 2023/01/28 22:33:07 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mega_libft/libft.h"

typedef struct s_stack
{
	int	data;
	int	index_data;
	struct s_stack *next;
}	t_stack;

typedef struct
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
}	t_two_stacks;

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }					t_list;

// typedef struct s_list_int
// {
// 	struct
// };
