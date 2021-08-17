/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 16:26:49 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/17 20:57:34 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	test_combination(t_ps *ps, char *sequence)
{
	do_sequence(ps, sequence);
	if (ps->stack_b->size == 0 && is_sorted(ps->stack_a))
		return (1);
	reset(ps);
	return (0);
}

static int	generate_combination(char *sequence, int i, t_ps *ps)
{
	char	instruction;

	if (i == -1)
		return (test_combination(ps, sequence));
	instruction = FIRST_INSTR;
	while (instruction <= LAST_INSTR)
	{
		sequence[i] = instruction;
		if (generate_combination(sequence, i - 1, ps))
			return (1);
		instruction++;
	}
	return (0);
}

char	*bruteforce(t_ps *ps)
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
		if (generate_combination(sequence, i, ps))
			return (sequence);
		i++;
	}
	return (NULL);
}
