/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:39:30 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/17 22:11:46 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>//TODO redundant?
#include <stdio.h> //REMOVE
#include "push_swap.h"

static void	print_instr(char *str)
{
	while (*(str++))
	{
		if (*(str - 1) == SA)
			ft_putstr_fd("sa\n", 1);
		else if (*(str - 1) == RA)
			ft_putstr_fd("ra\n", 1);
		else if (*(str - 1) == RRA)
			ft_putstr_fd("rra\n", 1);
		else if (*(str - 1) == SB)
			ft_putstr_fd("sb\n", 1);
		else if (*(str - 1) == RB)
			ft_putstr_fd("rb\n", 1);
		else if (*(str - 1) == RRB)
			ft_putstr_fd("rrb\n", 1);
		else if (*(str - 1) == SS)
			ft_putstr_fd("ss\n", 1);
		else if (*(str - 1) == RR)
			ft_putstr_fd("rr\n", 1);
		else if (*(str - 1) == RRR)
			ft_putstr_fd("rrr\n", 1);
		else if (*(str - 1) == PA)
			ft_putstr_fd("pa\n", 1);
		else if (*(str - 1) == PB)
			ft_putstr_fd("pb\n", 1);
	}
}

int	main(int argc, const char **args)
{
	t_stacks	game;
	char		*iset;

	ft_bzero(&game, sizeof(t_stacks));
	if (argc == 1)
		exit_handler(SUCCS, game.stack);
	load_stack(&game, argc - 1, &(args[1]));
	if (is_sorted(game))
		exit_handler(SUCCS, game.stack);
	iset = insertion_sort(game);
	print_instr(iset);
	free(iset);
	//iset = start_backtrace(&game);
	//print_instr(iset);
	system("leaks -q push_swap");
	exit_handler(SUCCS, game.stack);
}
