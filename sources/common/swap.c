/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:13:24 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/24 18:46:18 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	swap(t_stacks *game, char which)
{
	if (which & A && (game->top_a - game->stack > 1))
		ft_swap(game->top_a, game->top_a - 1);
	if (which & B && (game->max_i - game->top_a > 2))
		ft_swap(game->top_a + 1, game->top_a + 2);
}
