/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:13:25 by vicmarti          #+#    #+#             */
/*   Updated: 2021/05/14 19:02:13 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>
#include <stdio.h>

void	recursive_backtrace(t_list **inst, t_stacks *game, int steps, char *f)
{
	//int i = 0;
	//printf("steps %d\n", steps);
	/*
	while (game->stack + i <= game->max_i)
		printf("|%i", game->stack[i++]);
		*/
	//printf("|\nsteps %d\n", steps);
	if (steps > 1000)
		return ;
	if (is_sorted(*game))
	{
		(*f) = 1;
		return ;
	}

	if (*f == 0)
	{
		rot(game, "a");
		ft_lstadd_front(inst, ft_lstnew(ft_strdup("ra\n")));
		recursive_backtrace(&((*inst)->next), game, steps + 1, f);
		if (*f == 0)
		{
			ft_lstclear(inst, free);
			rot(game, "ra");
		}
	}
	//------
	if (*f == 0)
	{
		swap(game, "a");
		ft_lstadd_front(inst, ft_lstnew(ft_strdup("sa\n")));
		recursive_backtrace(&((*inst)->next), game, steps + 1, f);
		if (*f == 0)
		{
			ft_lstclear(inst, free);
			swap(game, "a");
		}
	}
}
