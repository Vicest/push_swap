/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:17:46 by vicmarti          #+#    #+#             */
/*   Updated: 2021/03/31 14:54:57 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	rot(t_psh_swp game, char *spec)
{
	if (!ft_strcmp(spec, "a"))
		rotate(game.stack, game.top_a);
	else if (!ft_strcmp(spec, "b"))
		rrotate(game.top_a + 1, game.max_i);
	else if (!ft_strcmp(spec, "r"))
	{
		rotate(game.stack, game.top_a);
		rrotate(game.top_a + 1, game.max_i);
	}
	else if (!ft_strcmp(spec, "ra"))
		rrotate(game.stack, game.top_a);
	else if (!ft_strcmp(spec, "rb"))
		rotate(game.top_a + 1, game.max_i);
	else if (!ft_strcmp(spec, "rr"))
	{
		rrotate(game.stack, game.top_a);
		rotate(game.top_a + 1, game.max_i);
	}
	else
		exit_handler(ERROR, game.stack);
}
