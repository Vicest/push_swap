/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_candidates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 18:06:43 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/14 18:35:21 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

void	find_candidates(t_stack *stack, t_moves *sort_info, int max_pick)
{
	const size_t	size = stack->size;
	size_t			i;
	bool			found_one;

	found_one = false;
	i = 0;
	while (i < size)
	{
		if (stack->val[i] <= max_pick)
		{
			sort_info->top_candidate = stack->val[i];
			sort_info->a_top = size - i - 1;
			if (!found_one)
			{
				found_one = true;
				sort_info->base_candidate = sort_info->top_candidate;
				sort_info->a_base = i + 1;
			}
		}
		i++;
	}
}
