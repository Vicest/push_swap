/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:44:34 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/14 20:38:11 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include "common.h"

static int	has_repetitions(t_stack *stack)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < stack->size)
	{
		j = i;
		while (++j < stack->size)
		{
			if (stack->val[i] == stack->val[j])
				return (1);
		}
	}
	return (0);
}

void	load_stack(t_ps *ps, char *numbers_str, size_t numbers_cnt)
{
	char	*next_number;
	char	*number_end;

	next_number = numbers_str;
	while (numbers_cnt--)
	{
		ps->stack_a->val[numbers_cnt] = ft_strtoi(next_number, &number_end);
		next_number = number_end;
		if ((ps->stack_a->val[numbers_cnt] == INT_MAX
				|| ps->stack_a->val[numbers_cnt] == INT_MIN) && errno == ERANGE)
			exit_handler(ERROR);
		if (*number_end != '\0' && *number_end != ' ')
			exit_handler(ERROR);
		ps->stack_a->size++;
	}
	if (has_repetitions(ps->stack_a))
		exit_handler(ERROR);
}
