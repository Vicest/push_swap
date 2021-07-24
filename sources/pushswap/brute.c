/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 16:26:49 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/24 22:11:09 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	test_combination(t_stacks *game, char *sequence)
{
	do_sequence(game, sequence);
	if (is_sorted(*game))
		return (1);
	reset(game);
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

	sequence = malloc((BRUTEFORCE_DEPTH + 1) * sizeof(char));
	if (!sequence)
		return (NULL);
	i = 0;
	while (i <= BRUTEFORCE_DEPTH)
	{
		sequence[i + 1] = 0;
		if (generate_combination(sequence, i, game))
			return (sequence);
		i++;
	}
	return (NULL);
}
