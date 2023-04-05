/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_action_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:32:22 by sboulain          #+#    #+#             */
/*   Updated: 2023/04/04 18:12:53 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// rrr : rra and rrb at the same time.
void	rrr_reverse_rotate_both(t_two_stacks *stacks, bool do_print)
{
	ra_rotate_a(stacks, false);
	rb_rotate_b(stacks, false);
	if (do_print)
		ft_printf("rra\n");
}
