/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 20:21:35 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/24 18:27:53 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset(t_stacks *game)
{
	game->top_a = game->max_i;
	ft_memcpy(game->stack, game->copy,
		sizeof(int) * (game->max_i - game->stack + 1));
}
