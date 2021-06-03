/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:13:25 by vicmarti          #+#    #+#             */
/*   Updated: 2021/05/21 20:04:02 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*backtrace(t_stacks *game, t_backtrace_info bi)
{
	while ((char)(bi.instr1->content) <= LAST_INSTR)
		//TODO if possible just use a char * var
	{
		if (is_sorted(*game))
		{
			bi.max_steps = bi.step;
			free(bi.shortest);
			bi.shortest = copy_instructions(bi.last_instr);
			if (!bi.shortest)
			{
				ft_lstclear(&bi.last_instr, NULL);
				exit_handler(ERROR, game);
			}
			delete_last_instr(&bi, game);
			if (!bi.last_instr)
				break;
			inc_instr(game, bi.last_instr);
			continue ;
		}
		if ((char)(bi.last_instr->content) > LAST_INSTR)
			//TODO if possible use char* var
		{
			delete_last_instr(&bi, game);
			inc_instr(game, bi.last_instr);
			continue ;
		}
		if(bi.step == bi.max_steps)
		{
			inc_instr(game, bi.last_instr);
			continue ;
		}
		ft_lstadd_front(&(bi.last_instr), ft_lstnew(NULL));
		bi.step++;
		inc_instr(game, bi.last_instr);
	}
	if (bi.last_instr)
		ft_lstclear(&bi.last_instr, NULL);
	return (bi.shortest);
}

char	*start_backtrace(t_stacks *game)
{
	t_backtrace_info	bi;

	if (is_sorted(*game))
		return ("");
	bi.instr1 = NULL;
	ft_lstadd_front(&(bi.instr1), ft_lstnew(NOP));
	bi.last_instr = bi.instr1;
	bi.shortest = NULL;
	bi.max_steps = 200;
	inc_instr(game, bi.last_instr);
	bi.step = 1;
	return (backtrace(game, bi));
}
