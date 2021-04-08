/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:21:05 by vicmarti          #+#    #+#             */
/*   Updated: 2021/04/06 13:45:21 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker.h"

#include <stdio.h>

static void	apply_instruction(char *instr, t_psh_swp *game)
{
	if (*instr == 's')
		swap(*game, instr + 1);
	else if (*instr == 'p')
		push(game, instr + 1);
	else if (*instr == 'r')
		rot(*game, instr + 1);
	else
		exit_handler(ERROR, game->stack);
	print_sts(*game);
}

int	main(int argc, const char **args)
{
	t_psh_swp	game;
	char		*instructions;
	int			gnl_out;

	ft_bzero(&game, sizeof(t_psh_swp));
	if (argc == 1)
		exit_handler(SUCCS, game.stack);
	load_stack(&game, args[1]);
	print_sts(game);
	gnl_out = get_next_line(&instructions);
	while (gnl_out > 0)
	{
		apply_instruction(instructions, &game);
		free(instructions);
		gnl_out = get_next_line(&instructions);
	}
	if (is_ordered(game))
		printf("OK\n");
	else
		printf("KO\n");
	free(instructions);
	exit_handler(SUCCS, game.stack);
}
