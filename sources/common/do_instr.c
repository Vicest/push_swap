/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 19:23:49 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/07 18:39:50 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	do_instr(t_ps *ps, char instr_id)
{
	if (instr_id == SS || instr_id == SA || instr_id == SB)
	{
		if (instr_id != SA)
			swap(ps->stack_b);
		if (instr_id != SB)
			swap(ps->stack_a);
	}
	else if (instr_id == RR || instr_d == RA|| instr_id == RB)
	{
		if (instr_id != RA)
			rot(ps->stack_b);
		if (instr_id != RB)
			rot(ps->stack_a);
	}
	else if (instr_id == RRR || instr_id == RRA || instr_id == RRB)
	{
		if (instr_id != RRA)
			rrot(ps->stack_b);
		if (instr_id != RRB)
			rrot(ps->stack_a);
	}
	else if (instr_id == PA)
		push(ps->stack_a, ps->stack_b);
	else if (instr_id == PB)
		push(ps->stack_b, ps->stack_a);
}
