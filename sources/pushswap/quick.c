/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:50:07 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/30 16:15:52 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "push_swap.h"

static void	push_back_into_a(t_stacks *game, t_list **instr,
		int top, unsigned int rotations)
{
	int	*a_base;
	int	*b_top;

	a_base = peek_base(game, A);
	b_top = peek_top(game, B);
	while (b_top)
	{
		if (*b_top > *a_base)
		{
			log_and_do(game, instr, PA);
			b_top = peek_top(game, B);
		}
		else
		{
			rotations--;
			log_and_do(gamee, instr, RRA);
			a_base = peek_base(game, A);
		}
	}
	if (rotations > 0)
		log_and_do_n(game, instr, RRA, rotations);
}

static void	push_to_base(t_stacks *game, t_list **instr)
{
	log_and_do(game, instr, PB);
	if (stack_size(game, B) > 1)
		log_and_do(game, instr, RB);
}

//TODO Can make it 1 loop right?
static unsigned int	push_from_a(t_stacks *game, t_list **instr,
		int pivot, int base)
{
	bool			base_is_checked;
	unsigned int	rotations;

	rotations = 0;
	while (game->top_a[0] != pivot)
	{
		if (game->top_a[0] > pivot)
			push_to_base(game, instr);
		else
		{
			log_and_do(game, instr, RA);
			rotations++;
		}
	}
	base_is_checked = false;
	while (!base_is_checked)
	{
		if (game->top_a[0] == base)
			base_is_checked = true;
		if (game->top_a[0] < pivot)
			push_to_base(game, instr);
		else
		{
			log_and_do(game, instr, RA);
			rotations++;
		}
	}
}

/*
**	Quicksort adaptation, the substack section being ordered is at the top.
*/

void	quick(t_stacks *game, t_list **instr, int base_val, int top_val)
{
	const int		pivot = game->stack[(top_val - base_val + 1) / 2];
	unsigned int	rotations;

	if (get_position(top_val, game) - get_position(base_val, game) + 1 <= 3)
		sort_3_and_rotate(game, instr, base_val, top_val);
	else
	{
		rotations = push_from_a(game, instr, pivot, base_val);
		push_back_into_a(game, instr, top_val, rotations);
		if (pivot != top)
			quick(game, instr, pivot, top_val);
		rotate_over_pivot();
		if (base_val != top
		quick(game, base_val, pivot - 1); //TODO Can pivot == 0?
	}
}
