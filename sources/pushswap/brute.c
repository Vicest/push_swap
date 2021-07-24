/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 16:26:49 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/24 21:28:33 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	test_combination(t_stacks *game, char *sequence)
{
//	printf("DEBUG\n");
//	print_status(game);
	do_sequence(game, sequence);
//	print_status(game);
	if (is_sorted(*game))
		return (1);
	reset(game);
//	print_status(game);
//	printf("------\n");
	return (0);
}

static int	generate_combination(char *sequence, int i, t_stacks *game)
{
	char	instruction;

	if (i == -1)
		return (test_combination(game, sequence));
	instruction = FIRST_INSTR;
	while (instruction <= LAST_INSTR)
	{
		sequence[i] = instruction;
		if (generate_combination(sequence, i - 1, game))
			return (1);
		instruction++;
	}
	return (0);
}

char	*bruteforce(t_stacks *game)
{
	char	*sequence;
	int		i;

	sequence =  malloc((BRUTEFORCE_DEPTH + 1) * sizeof(char));
	if (!sequence)
		return (NULL);
	i = 0;
	while (i <= BRUTEFORCE_DEPTH)
	{
		sequence[i + 1] = 0;
		if(generate_combination(sequence, i, game))
			return (sequence);
		i++;
	}
	return (NULL);
}
