/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:50:07 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/02 18:33:11 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "push_swap.h"

#include <stdio.h> //TODO

static void	push_back_into_a(t_stacks *game, t_list **instr,
		unsigned int rotations)
{
	int	*a_base;
	int	*b_top;

	a_base = peek_base(game, A);
	b_top = peek_top(game, B);
	while (b_top)
	{
		if (*b_top > *a_base || rotations == 0)
		{
			log_and_do_instr(game, instr, PA);
			b_top = peek_top(game, B);
		}
		else
		{
			rotations--;
			log_and_do_instr(game, instr, RRA);
			a_base = peek_base(game, A);
		}
	}
	if (rotations > 0)
		log_and_do_n(game, instr, RRA, rotations);
}

static void	push_to_base(t_stacks *game, t_list **instr)
{
	log_and_do_instr(game, instr, PB);
	if (stack_size(game, B) > 1)
		log_and_do_instr(game, instr, RB);
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
			log_and_do_instr(game, instr, RA);
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
			log_and_do_instr(game, instr, RA);
			rotations++;
		}
	}
	return (rotations);
}

static void	rotate_over_pivot(t_stacks *game, t_list **instr, int pivot)
{
	int	*a_base;

	a_base = peek_base(game, A);
	while (a_base && *a_base != pivot)
	{
		log_and_do_instr(game, instr, RA);
		a_base = peek_base(game, A);
	}
}


/*
**	Quicksort adaptation, the substack section being ordered is at the top.
*/

//TODO Gezzums, thr pivot logic could be less convoluted... And not wrong...
void	quick(t_stacks *game, t_list **instr, int base_val, int top_val)
{
	const size_t	substack_size =
		get_position(top_val, game) - get_position(base_val, game) + 1;
	const int		pivot = game->stack[index_of(base_val, game) +
		(index_of(top_val, game) - index_of(base_val, game) + 1) / 2];
	int				new_top;
	int				new_base;
	unsigned int	rotations_done;

	if (substack_size <= 3)
		sort_rotate_3(game, instr, substack_size);
	else
	{
		rotations_done = push_from_a(game, instr, pivot, base_val);
		if(stack_size(game, B) == 0)
			new_base = *peek_base(game, A);
		else
			new_base = ft_max(*peek_top(game, B), *peek_base(game, A));
		push_back_into_a(game, instr, rotations_done);
		new_top = *peek_top(game, A);
		if (pivot != new_top)
			quick(game, instr, *(get_position(pivot, game) + 1), new_top);
		rotate_over_pivot(game, instr, pivot);
		if (new_base != pivot)
			quick(game, instr, new_base, game->top_a[0]);
	}
}
