/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:39:30 by vicmarti          #+#    #+#             */
/*   Updated: 2021/04/08 15:32:11 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "checker.h"

static void	ft_swap(int *a, int *b)
{
	int	swp;

	swp = *a;
	*a = *b;
	*b = swp;
}

void	bubble_sort(t_psh_swp *game)
{
	int		elems;
	size_t	i;
	size_t	steps;

	elems = (game->max_i - game->stack);
	i = elems;
	while (i > 0)
	{
		if (game->stack[i] < game->stack[i - 1])
		{
			steps = elems - i;
			while (steps-- > 0)
				write(1, "ra\n", 3);
			ft_swap(game->stack + i, game->stack + i - 1);
			write(1, "sa\n", 3);
			steps = elems - i;
			while (steps-- > 0)
				write(1, "rra\n", 4);
			i = elems;
		}
		else
			i--;
	}
	write(1, "\0", 1);
}

int	main(int argc, const char **args)
{
	t_psh_swp	game;

	ft_bzero(&game, sizeof(t_psh_swp));
	if (argc == 1)
		exit_handler(SUCCS, game.stack);
	else if (argc != 2)
		exit_handler(ERROR, game.stack);
	load_stack(&game, args[1]);
	bubble_sort(&game);
	//run_algo(gfg_sort, game);
	exit_handler(SUCCS, game.stack);
	return 0;
}
