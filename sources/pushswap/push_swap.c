/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:39:30 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/02 13:32:57 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h> //REMOVE
#include "push_swap.h"

static void	print_instr(char *str)
{
	while (*str)
	{
		if (*str == SA)
			ft_putstr_fd("sa\n", 1);
		else if (*str == RA)
			ft_putstr_fd("ra\n", 1);
		else if (*str == RRA)
			ft_putstr_fd("rra\n", 1);
		else
			exit_handler(ERROR, NULL);// game.stack);
		str++;
	}
}

int	main(int argc, const char **args)
{
	t_stacks	game;
	char		*iset;

	ft_bzero(&game, sizeof(t_stacks));
	if (argc == 1)
		exit_handler(SUCCS, game.stack);
	else if (argc != 2)
		exit_handler(ERROR, game.stack);
	load_stack(&game, args[1]);
	insertion_sort(game);
	iset = start_backtrace(&game);
	print_instr(iset);
	system("leaks -q push_swap");
	exit_handler(SUCCS, game.stack);
}
