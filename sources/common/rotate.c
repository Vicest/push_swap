/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 20:37:33 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/17 18:28:42 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	rot(t_stack *stack)
{
	size_t	i;
	int		top;

	if (stack->size == 0)
		return ;
	top = stack->val[stack->size - 1];
	i = stack->size;
	while (--i > 0)
		stack->val[i] = stack->val[i - 1];
	stack->val[0] = top;
}

void	rrot(t_stack *stack)
{
	size_t	i;
	int		base;

	if (stack->size == 0)
		return ;
	base = stack->val[0];
	i = 0;
	while (++i < stack->size)
		stack->val[i - 1] = stack->val[i];
	stack->val[i - 1] = base;
}
