/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:38:47 by vicmarti          #+#    #+#             */
/*   Updated: 2021/05/18 12:33:52 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	bubble_sort(t_list **inst, t_stacks *game)
{
	int		elems;
	size_t	i;
	size_t	steps;

	elems = (game->max_i - game->stack);
	i = elems;
	while (i > 0)
	{
		if (game->stack[i] < game->stack[i - 1])
		{
			steps = elems - i;
			while (steps-- > 0)
				ft_lstadd_front(inst, ft_lstnew(ft_strdup("ra\n")));
			ft_swap(game->stack + i, game->stack + i - 1);
			ft_lstadd_front(inst, ft_lstnew(ft_strdup("sa\n")));
			steps = elems - i;
			while (steps-- > 0)
				ft_lstadd_front(inst, ft_lstnew(ft_strdup("rra\n")));
			i = elems;
		}
		else
			i--;
	}
}
