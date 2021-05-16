/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:13:25 by vicmarti          #+#    #+#             */
/*   Updated: 2021/05/16 16:00:21 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "push_swap.h"

char	*backtrace(t_stacks *game)
{
	t_backtrace_info	bi;
	
	while (*(char *)(bi.instr1->data) <= LAST_INSTR)
		//TODO if possible just use a char * var
	{
		if (is_ordered(*game))
		{
			bi.max_steps = bi.step;
			bi.sortest = copy_instr(bi.last_instr);
			delete_last_instr(&bi, game);
			inc_instr(game, bi.last_instr);
			continue ;
		}
		if(bi.step == bi.max_steps)
		{
			inc_instr(game, bi.last_instr);
			continue ;
		}
		if (*(char *)(bi.current_instr->data) > LAST_INSTR)
			//TODO if possible use char* var
		{
			delete_last_instr(&bi, game);
			inc_instr(game, bi.last_instr);
			continue ;
		}
		ft_lst_addfront(&(bi.last_instr), NOP);
		bi.step++;
		inc_instr(game, bi.last_instr);
	}
	return (bi->shortest);
}
