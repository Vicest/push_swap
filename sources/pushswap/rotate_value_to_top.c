/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_value_to_top.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 18:02:16 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/14 18:09:12 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_value_to_top(int value, t_stack *stack, t_list **instr)
{
	const size_t	rrot_to_top = index_of(value, stack) + 1;

	if (rrot_to_top == stack->size)
		return ;
	if (rrot_to_top < (stack->size + 1) / 2)
		log_and_do_n(ps, instr, RRB, rrot_to_top);
	else
		log_and_do_n(ps, instr, RB, stack->size - rrot_to_top);
}
