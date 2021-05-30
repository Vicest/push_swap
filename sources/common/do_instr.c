/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 19:23:49 by vicmarti          #+#    #+#             */
/*   Updated: 2021/05/30 20:55:44 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	do_instr(t_stacks *game, char instr_id)
{
	if (instr_id == SA)
		swap(game, A);
	else if (instr_id == SB)
		swap(game, B);
	else if (instr_id == SS)
		swap(game, A | B);
	else if (instr_id == RA)
		rot(game, A);
	else if (instr_id == RB)
		rot(game, B);
	else if (instr_id == RR)
		rot(game, A | B);
	else if (instr_id == RRA)
		rrot(game, A);
	else if (instr_id == RRB)
		rrot(game, B);
	else if (instr_id == RRR)
		rrot(game, A | B);
	else if (instr_id == PA)
		push(game, A)
	else if (instr_id == PB)
		push(game, B);
}

void	undo_instr(t_stacks *game, char instr_id)
{
	if (instr_id == SA)
		 swap(game, A);
	else if (instr_id == RA)
		rrot(game, A);
	else if (instr_id == RRA)
		rot(game, A);
}
