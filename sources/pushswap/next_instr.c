/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:21:28 by vicmarti          #+#    #+#             */
/*   Updated: 2021/05/21 19:27:34 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static char	next_instr(char instr, char prev_instr)
{
	if (instr < SA && prev_instr != SA)
		return (SA);
	else if (instr < RA && prev_instr != RRA)
		return (RA);
	else if (instr < RRA && prev_instr != RA)
		return (RRA);
	return (LAST_INSTR + 1);
}

void	inc_instr(t_stacks *game, t_list *last_instr)
{
	char	last_instr_id;
	char	prev_instr_id;

	//last_instr_id = NULL;
	last_instr_id = (char)(last_instr->content);
	prev_instr_id = NOP;
	if (last_instr && last_instr->next)
		prev_instr_id = (char)(last_instr->next->content);
	undo_instr(game, last_instr_id);
	last_instr->content = (void *)(size_t)next_instr(last_instr_id, prev_instr_id);
	do_instr(game, (char)(last_instr->content));
}
