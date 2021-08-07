/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 20:37:33 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/07 18:21:11 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	rot(t_stack *stack)
{
	const int	top = stack->val[stack->size - 1];
	size_t		i;

	i = stack->size;
	while (--i > 0)
		stack->val[i] = stack->val[i - 1];
	stack->val[0] = base;
}

void	rrot(t_stack *stack)
{
	const int	base = stack->val[0];
	size_t		i;

	i = 0;
	while (++i < stack->size)
		stack->val[i - 1] = stack->val[i];
	stack->val[i - 1] = base;
}
