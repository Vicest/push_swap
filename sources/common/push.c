/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 20:56:05 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/13 20:01:43 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push(t_stacks *game, char which)
{
	if (which & A && game->max_i > game->top_a)
		game->top_a++;
	else if (which & B && game->top_a >= game->stack)
		game->top_a--;
}
