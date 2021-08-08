/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:17:25 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/08 21:42:02 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	preprocess(t_stack *stack)
{
	t_stack			*stack_cpy;
	t_stack			*sorted_cpy;
	size_t			pos_in_stack;
	size_t			i;

	copy(&stack_cpy, stack);
	copy(&sorted_cpy, stack);
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
