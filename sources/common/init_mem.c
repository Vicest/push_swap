/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 17:38:37 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/07 17:42:02 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	init_stack(t_stack *stack, size_t size)
{
	stack->val = ft_calloc(size, sizeof(int));
	if (!stack->val)
		exit_handler(ERROR, NULL);
	stack->size = 0;
	stack->max_size = size;
}

void	init_mem(t_ps *ps, size_t size)
{
	init_stack(ps->stack_a, size);
	init_stack(ps->stack_b, size);
}
