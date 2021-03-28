/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:21:05 by vicmarti          #+#    #+#             */
/*   Updated: 2021/03/28 16:57:29 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <errno.h>
#include "checker.h"

#include <stdio.h>
void	exit_handler(char status, void *stc_mem)
{
	if (stc_mem)
		free(stc_mem);
	if (status == ERROR)
		write(2, "Error\n", 6);
	system("leaks checker");
	exit(status);
}

static void	load_stack(t_psh_swp game, int cnt, char **nums)
{
	char	*end;

	game.stack = malloc(cnt * sizeof(int));
	while(--cnt >= 0)
	{
		game.stack[cnt] = ft_strtol(nums[cnt], &end);
		if (*end || (game.stack[cnt] == 0 && errno == EINVAL) ||
			game.stack[cnt] > INT_MAX || game.stack[cnt] < INT_MIN)
			exit_handler(ERROR, game.stack);
	}
}
/*
static void	read_instruction

int	main(int argc, char **args)
{
	t_psh_swp	game;

	load_stack(game, argc - 1, args + 1);
	while (read
	read_instruction();
	exit(0);
}
*/



	/*
	int	*stacks;

	stacks = malloc
	check_args();
	while (argc *
	*/
