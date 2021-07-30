/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peek.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:24:44 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/30 15:39:09 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	*peek_base(t_stacks *game, char which)
{
	if (stack_size(game, which) == 0)
		return (NULL);
	if (which == A)
		return (game->stacks);
	else
		return (game->max_i);
}

int	*peek_top(t_stacks *game, char which)
{
	if (stack_size(game, which) == 0)
		return (NULL);
	if (which == A)
		return (game->top_a);
	else
		return (game->top_a + 1);
}
