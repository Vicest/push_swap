/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:01:19 by vicmarti          #+#    #+#             */
/*   Updated: 2021/03/29 14:48:59 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

void	print_sts(t_psh_swp game)
{
	int i;

	i = ft_max(game.top_a, game.size - game.top_a);
	while (i >= 0)
	{
		if (i <= (int)game.top_a)
			printf("|%d|", game.stack[i]);
		else
			printf("| |");
		printf("\n");
		i--;
	}
}
