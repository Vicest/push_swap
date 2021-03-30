/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:13:24 by vicmarti          #+#    #+#             */
/*   Updated: 2021/03/30 12:25:31 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap(int *a, int *b)
{
	int	swp;

	swp = *a;
	*a = *b;
	*b = swp;
}

void	swap(t_psh_swp game, char *spec)
{
	if (spec[0] == '\0' ||!ft_strchr("abs", spec[0]) || spec[1] != '\0')
		exit_handler(ERROR, game.stack);
	if (spec[0] == 'a' || spec[0] == 's')
	{
		if (game.top_a - game.stack > 0)
			ft_swap(game.top_a, game.top_a - 1);
	}
	if (spec[0] == 'b' || spec[0] == 's')
	{
		if (game.max_i - game.top_a > 1)
			ft_swap(game.top_a + 1, game.top_a + 2);
	}
}
