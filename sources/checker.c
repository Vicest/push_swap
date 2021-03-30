/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:21:05 by vicmarti          #+#    #+#             */
/*   Updated: 2021/03/30 13:48:05 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h> //TODO  strtoi
#include <errno.h>
#include "checker.h"
#include <stdio.h>

static int	has_dup(int *start, int *end)
{
	int	i;
	int	j;

	i = 0;
	while (start + i < end)
	{
		j = i + 1;
		while (start + j <= end)
		{
			if (start[i] == start[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	load_stack(t_psh_swp *game, int cnt, char **nums)
{
	char	*end;

	game->stack = malloc(cnt * sizeof(int));
	if (!game->stack)
		exit_handler(ERROR, game->stack);
	game->max_i = game->stack + cnt - 1;
	game->top_a = game->max_i;
	while (cnt > 0)
	{
		cnt--;
		game->stack[cnt] = ft_strtol(nums[cnt], &end);
		if (*end || (game->stack[cnt] == 0 && errno == EINVAL)
			|| game->stack[cnt] > INT_MAX || game->stack[cnt] < INT_MIN)
			exit_handler(ERROR, game->stack);
	}
	if (has_dup(game->stack, game->max_i))
		exit_handler(ERROR, game->stack);
}

static void	apply_instruction(char *instr, t_psh_swp *game)
{
	if (*instr == 's')
		swap(*game, instr + 1);
	else if (*instr == 'p')
		push(game, instr + 1);
	else if (*instr == 'r')
		; //rot(game, instr + 1);
	else
		exit_handler(ERROR, game->stack);
	print_sts(*game);
}

int	main(int argc, char **args)
{
	t_psh_swp	game;
	char		*instructions;
	int			gnl_out;

	ft_bzero(&game, sizeof(t_psh_swp));
	if (argc == 1)
		exit_handler(SUCCS, game.stack);
	load_stack(&game, argc - 1, args + 1);
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
