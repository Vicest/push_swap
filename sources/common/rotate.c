/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 20:37:33 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/24 21:35:24 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	rotate(int *start, int *end)
{
	int	aux;

	aux = *end;
	while (start < end)
	{
		end--;
		end[1] = end[0];
	}
	end[0] = aux;
}

static void	rrotate(int *start, int *end)
{
	int	aux;

	aux = *start;
	while (start < end)
	{
		start[0] = start[1];
		start++;
	}
	start[0] = aux;
}

void	rot(t_stacks *game, char which)
{
	if (which & A)
		rotate(game->stack, game->top_a);
	if (which & B)
		rrotate(game->top_a + 1, game->max_i);
}

void	rrot(t_stacks *game, char which)
{
	if (which & A)
		rrotate(game->stack, game->top_a);
	if (which & B)
		rotate(game->top_a + 1, game->max_i);
}
