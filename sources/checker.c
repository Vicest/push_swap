/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:21:05 by vicmarti          #+#    #+#             */
/*   Updated: 2021/03/28 21:56:15 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h> //TODO  strtoi
#include <errno.h>
#include "checker.h"

	static void	load_stack(t_psh_swp game, int cnt, char **nums)
{
	char	*end;

	game.size = cnt;
	game.stack = malloc(cnt * sizeof(int));
	while(--cnt >= 0)
	{
		game.stack[cnt] = ft_strtol(nums[cnt], &end);
		if (*end || (game.stack[cnt] == 0 && errno == EINVAL) ||
			game.stack[cnt] > INT_MAX || game.stack[cnt] < INT_MIN)
			exit_handler(ERROR, game.stack);
	}
}

static void	apply_instruction(char *instr, t_psh_swp game)
{
	if (*instr == 's')
		swap(game, instr + 1);
	/* //TODO Not right.
	else if (*instr == 'p')
		push(game, instr + 1);
	else if (*instr == 'r')
		rot(game, instr + 1);
	else if (*instr == '\0')
		();
		*/
	else
		exit_handler(ERROR, game.stack);
}

int	main(int argc, char **args)
{
	t_psh_swp	game;
	char		*instructions;
	int			gnl_out;

	ft_bzero(&game, sizeof(t_psh_swp));
	load_stack(game, argc - 1, args + 1);
	gnl_out = get_next_line(&instructions);
	while (gnl_out > 0)
	{
		apply_instruction(instructions, game);
		free(instructions);
		gnl_out = get_next_line(&instructions);
	}
	free(instructions);
	exit_handler(SUCCS, game.stack);
}

	/*
	int	*stacks;

	stacks = malloc
	check_args();
	while (argc *
	*/
