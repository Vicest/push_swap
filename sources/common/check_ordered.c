/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:48:17 by vicmarti          #+#    #+#             */
/*   Updated: 2021/05/13 12:48:09 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	is_sorted(t_stacks *game)
{
	if (game->top_a != game->max_i)
		return (0);
	while (game->stack < game->top_a)
	{
		if (game->stack[0] > game->stack[1])
			return (0);
		game->stack++;
	}
	return (1);
}
