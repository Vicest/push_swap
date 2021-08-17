/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:17:25 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/17 20:41:39 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	preprocess(t_stack *stack)
{
	t_stack			*stack_cpy;
	t_stack			*sorted_cpy;
	size_t			pos_in_stack;
	size_t			i;

	init_stack(&stack_cpy, stack->size);
	copy(stack_cpy, stack);
	init_stack(&sorted_cpy, stack->size);
	copy(sorted_cpy, stack);
	arr_sort(sorted_cpy->val, stack->size);
	i = -1;
	while (++i < stack->size)
	{
		pos_in_stack = index_of(sorted_cpy->val[i], stack_cpy);
		stack->val[pos_in_stack] = i;
	}
	clean_stack(sorted_cpy);
	clean_stack(stack_cpy);
}
