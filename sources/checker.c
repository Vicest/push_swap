/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:21:05 by vicmarti          #+#    #+#             */
/*   Updated: 2021/04/11 19:33:23 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker.h"

#include <stdio.h>

static void	apply_instruction(char *instr, t_psh_swp *game, char sts)
{
	if (sts & VERBOSE)
		print_sts(*game);
	if (*instr == 's')
		swap(*game, instr + 1);
	else if (*instr == 'p')
		push(game, instr + 1);
	else if (*instr == 'r')
		rot(*game, instr + 1);
	else
		exit_handler(ERROR, game->stack);
}

static void	read_input(t_psh_swp *game, char sts)
{
	char		*instructions;
	int			gnl_out;

	gnl_out = get_next_line(&instructions);
	while (gnl_out > 0)
	{
		apply_instruction(instructions, game, sts);
		free(instructions);
		gnl_out = get_next_line(&instructions);
	}
	free(instructions);
}

int	main(int argc, const char **args)
{
	t_psh_swp	game;
	int			last_arg;
	char		sts;

	if (argc == 1)
		exit_handler(SUCCS, NULL);
	sts = 0;
	last_arg = check_opts(argc, args, &sts);
	 if (last_arg != argc - 1)
		exit_handler(ERROR, NULL);
	ft_bzero(&game, sizeof(t_psh_swp));
	load_stack(&game, args[last_arg]);
	if (sts & VERBOSE)
		print_sts(game);
	read_input(&game, sts);
	if (check_ordered(game))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	exit_handler(SUCCS, game.stack);
}
