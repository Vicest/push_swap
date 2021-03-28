/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:13:24 by vicmarti          #+#    #+#             */
/*   Updated: 2021/03/28 21:37:27 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void ft_swap(int *a, int *b)
{
	int	swp;

	swp = *a;
	*a = *b;
	*b = swp;
}

void	swap(t_psh_swp game, char *spec)
{
	if (spec[0] == 'a' && spec[1] == '\0' && game.top_a >= 1)
		ft_swap(game.stack + game.top_a, game.stack + game.top_a - 1);
	else if (spec[0] == 'b' && spec[1] == '\0' && game.top_a >= 1)
		ft_swap(game.stack + game.top_a + 1, game.stack + game.top_a + 2);
	else
		exit_handler(ERROR, game.stack);
}
