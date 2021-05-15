/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_last_instr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 17:56:12 by vicmarti          #+#    #+#             */
/*   Updated: 2021/05/15 19:51:17 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "push_swap.h"

void	delete_last_instr(t_backtrace_info *bi, t_stacks game)
{
	char	last_instr_id;
	t_list	prev_instr;

	last_instr = *(char *)(bi->last_instr->data);
	if (last_instr_id == SA)
		swap(game);
	else if (last_instr_id == RA)
		rrotate(game);
	else if (last_instr_id == RRA)
		rotate(game);
	bi->steps--;
	prev_instr = bi->last_instr->next;
	ft_lstdelone(bi->last_instr, NULL);
	bi->last_instr = prev_instr;
}
