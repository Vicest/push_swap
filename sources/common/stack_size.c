/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:45:33 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/31 15:29:57 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

size_t	stack_size(t_stacks *game, char which)
{
	if (which == (A | B))
		return (game->max_i + 1 - game->stack);
	else if (which == A)
		return (game->top_a + 1 - game->stack);
	else if (which == B)
		return (game->max_i - game->top_a);
	return (0);
}
