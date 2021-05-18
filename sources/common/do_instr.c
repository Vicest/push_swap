/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 19:23:49 by vicmarti          #+#    #+#             */
/*   Updated: 2021/05/18 12:38:30 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	do_instr(t_stacks *game, char instr_id)
{
	if (instr_id == SA)
		 swap(game, "a");
	else if (instr_id == RA)
		 rot(game, "a");
	else if (instr_id == RRA)
		 rot(game, "ra");
}

void	undo_instr(t_stacks *game, char instr_id)
{
	if (instr_id == SA)
		 swap(game, "a");
	else if (instr_id == RA)
		rot(game, "ra");
	else if (instr_id == RRA)
		rot(game, "a");
}
