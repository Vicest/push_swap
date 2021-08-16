/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:43:43 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/16 17:49:03 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	min_val(t_stack *stack)
{
	size_t	i;
	int		min;

	min = INT_MAX;
	i = -1;
	while (++i < stack->size)
		if (stack->val[i] < min)
			min = stack->val[i];
	return (min);
}
