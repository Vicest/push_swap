/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:27:06 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/15 16:33:39 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	max_val(t_stack *stack)
{
	size_t	i;
	int		max;

	max = INT_MIN;
	i = -1;
	while (++i < stack->size)
		if (stack->val[i] > max)
			max = stack->val[i];
	return (max);
}
