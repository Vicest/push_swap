/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ordered.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:48:17 by vicmarti          #+#    #+#             */
/*   Updated: 2021/04/09 16:05:06 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_ordered(t_psh_swp game)
{
	if (game.top_a != game.max_i)
		return (0);
	while (game.stack < game.top_a)
	{
		if (game.stack[0] > game.stack[1])
			return (0);
		game.stack++;
	}
	return (1);
}
