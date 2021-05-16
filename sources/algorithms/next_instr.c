/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:21:28 by vicmarti          #+#    #+#             */
/*   Updated: 2021/05/16 15:58:19 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char	*last_instr_id;
	char	prev_instr_id;

	last_instr_id = (char *)(last_instr->data);
	prev_instr_id = *(char *)(last_instr->next->data);
	undo_instr(game, *instr_id);
	instr_id = next_instr(*instr_id, prev_instr_id);
	do_instr(game, *instr_id);
}
