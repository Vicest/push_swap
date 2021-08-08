/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:17:25 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/08 16:41:24 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	preprocess(t_stack *stack)
{
	const size_t	len = stack->size;
	size_t			pos_in_stack;
	size_t			i;
	int				*stack_cpy;

	stack_cpy = malloc(len * sizeof(int));
	i = -1;
	while (++i < len)
		stack_cpy[i] = stack->val[i];
	arr_sort(stack_cpy, len);
	i = -1;
	while (++i < len)
	{
		pos_in_stack = index_of(stack_cpy[i], stack);
		stack->val[pos_in_stack] = i;
	}
	free(stack_cpy);
}
