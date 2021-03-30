/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:17:46 by vicmarti          #+#    #+#             */
/*   Updated: 2021/03/30 15:16:51 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rrotate(int *start, int *end)
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

static void rotate(int *start, int *end)
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
	if (ft_strcmp(spec, "ra"))
		rotate(game.stack, game.top_a);
	else if (ft_strcmp(spec, "rb"))
		rrotate(game.top_a, game.max_i);
	else if (ft_strcmp(spec, "rr"))
	{
		rotate(game.stack, game.top_a);
		rrotate(game.top_a, game.max_i);
	}
	else if (ft_strcmp(spec, "rra"))
		rrotate(game.stack, game.top_a);
	else if (ft_strcmp(spec, "rrb"))
		rotate(game.top_a, game.max_i);
	else if (ft_strcmp(spec, "rrr"))
	{
		rrotate(game.stack, game.top_a);
		rotate(game.top_a, game.max_i);
	}
	else
		exit_handler(ERROR, game.stack);
}

