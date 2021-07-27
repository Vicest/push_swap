/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:50:07 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/27 21:49:33 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_back_into_a(t_stacks *game, t_list **instr, int top)
{
	while (b_
	while (pushed_from_low > 0)
	{
		if (stack_base[0] > b_next)
			log_and_do(RRA);
			rotated--;
		else
		{
			log_and_do(RRB, PA);
			pushed_from_low--;
		}
	}
	while (size(stack_b) > 0)
	{
		same_as_before_noRRB();
	}
}

//TODO Optimize keeping track of the rotations needed in B to make
static void	push_from_a(t_stacks *game, t_list **instr, int pivot, int base)
{
	bool	base_is_checked;

	while (game->top_a[0] != pivot)
	{
		if (game->top_a[0] > pivot)
			log_and_do(game, instr, PB);
		else
			log_and_do(game, instr, RA);
	}
	base_is_checked = false;
	while (!base_is_checked)
	{
		if (game->top_a[0] == base)
			base_is_checked = true;
		if (game->top_a[0] < pivot)
			log_and_do(game, instr, PB);
		else
			log_and_do(game, instr, RA);
	}
}

/*
**	Quicksort adaptation, the substack section being ordered is at the top.
*/

void	quick(t_stacks *game, t_list **instr, int base_val, int top_val)
{
	const int	pivot = game->stack[(substack_top - substack_base + 1) / 2];

	if (get_position(top_val, game) - get_position(base_val, game) + 1 <= 3)
		sort_3_and_rotate(game, instr, base_val, top_val);
	else
	{
		push_from_a(game, instr, pivot, base_val);
		push_back_into_a(game, instr, top_val);
		quick(game, instr, pivot, substack_top);
		quick(game, substack_base, pivot - 1); //TODO Can pivot == 0?
	}
}
