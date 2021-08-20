/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_algorithms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:34:20 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/20 20:01:46 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*run_algorithms(t_ps *ps)
{
	size_t	blocks;
	char	*tmp;
	char	*shortest;

	if (ps->stack_a->size <= BRUTEFORCE_DEPTH)
		return (bruteforce(ps));
	else
	{
		blocks = 2;
		shortest = block_sort(ps, blocks);
		while (++blocks < ps->stack_a->size / 10)
		{
			reset(ps);
			tmp = block_sort(ps, blocks);
			if (ft_strlen(shortest) > ft_strlen(tmp))
			{
				free(shortest);
				shortest = tmp;
			}
			else
				free(tmp);
		}
	}
	return (shortest);
}
