/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:44:34 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/08 16:35:55 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h> //TODO  strtoi
#include <errno.h>
#include "common.h"

void	load_stack(t_ps *ps, char *numbers_str, size_t numbers_cnt)
{
	char	*next_number; //TODO
	char	*number_end;
	int		n;

	//numbers_str = join_args(argn, argv);
	//numbers = cnt_words(numbers_str);

	next_number = numbers_str;
	while (numbers_cnt--)
	{
		n = ft_strtol(next_number, &number_end);
		next_number = number_end;
		if (errno == ERANGE && (n & INT_MAX) == INT_MAX)
			exit_handler(ERROR);
		if (*number_end || has_value(n, ps->stack_a))
			exit_handler(ERROR);
		ps->stack_a->val[numbers_cnt] = n;
		ps->stack_a->size++;
	}
	free(numbers_str);
}
