/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:01:19 by vicmarti          #+#    #+#             */
/*   Updated: 2021/03/30 14:52:02 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

void	print_sts(t_psh_swp game)
{
	int		*a;
	int		*b;
	int		w;

	w = 1;
	a = game.stack;
	b = game.max_i;
	printf("[%1$6ca%1$6c][%1$6cb%1$6c]\n", ' ');
	while (a <= game.top_a || b > game.top_a)
	{
		if (a <= game.top_a)
			printf("|%13d|", *a);
		else
			printf("|             |");
		if (b > game.top_a)
			printf("|%13d|", *b);
		else
			printf("|             |");
		printf("\n");
		a++;
		b--;
	}
}
