/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:42:15 by vicmarti          #+#    #+#             */
/*   Updated: 2021/03/29 14:00:19 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push(t_psh_swp game, char *spec)
{
	if (spec[0] == 'a' && spec[1] == '\0')
	{
		if (game.top_a > 0)
			game.top_a--;
	}
	else if (spec[0] == 'b' && spec[1] == '\0')
	{
		if (game.top_a < game.size)
			game.top_a++;
	}
	else
		exit_handler(ERROR, game.stack);
}