/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_and_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 18:22:53 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/01 19:16:21 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_rotate_with_push(t_stacks *game, t_list **instr)
{
	log_and_do_instr(game, instr, PB);
	log_and_do_instr(game, instr, SA);
	log_and_do_instr(game, instr, RA);
	if (game->top_a[0] > game->top_a[1])
	{
		log_and_do_instr(game, instr, PA);
		log_and_do_instr(game, instr, RA);
	}
	else
	{
		log_and_do_instr(game, instr, RA);
		log_and_do_instr(game, instr, PA);
	}
	log_and_do_instr(game, instr, RA);
}

static void	sort_rotate_2(t_stacks *game, t_list **instr)
{
	if (game->top_a[0] > game->top_a[-1])
		log_and_do_instr(game, instr, SA);
	log_and_do_n(game, instr, RA, 2);
}

void	sort_rotate_3(t_stacks *game, t_list **instr, size_t size)
{
	if (size == 3)
	{
		if (game->top_a[-2] < game->top_a[-1]
			&& game->top_a[-2] < game->top_a[0])
			sort_rotate_with_push(game, instr);
		else if (game->top_a[0] < game->top_a[-1]
			&& game->top_a[0] < game->top_a[-2])
		{
			log_and_do_instr(game, instr, RA);
			sort_rotate_2(game, instr);
		}
		else
		{
			log_and_do_instr(game, instr, SA);
			log_and_do_instr(game, instr, RA);
			sort_rotate_2(game, instr);
		}
	}
	else if (size == 2)
		sort_rotate_2(game, instr);
	else
		log_and_do_instr(game, instr, RA);
}
