/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:44:34 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/07 21:49:21 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h> //TODO  strtoi
#include <errno.h>
#include "common.h"

static size_t	cnt_words(const char *nums)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (nums[0] && nums[0] != ' ')
		len = 1;
	while (nums[i] && nums[i + 1])
	{
		if (nums[i] == ' ' && nums [i + 1] != ' ')
			len++;
		i++;
	}
	return (len);
}

static char	*join_args(int argn, const char **argv)
{
	char	*joined;
	char	*prev_str;
	int		i;

	joined = ft_strdup(argv[0]);
	if (!joined)
		exit_handler(ERROR, NULL);
	i = 1;
	while (i < argn)
	{
		prev_str = joined;
		joined = ft_strjoin(joined, " ");
		if (!joined)
			exit_handler(ERROR, NULL);
		free(prev_str);
		prev_str = joined;
		joined = ft_strjoin(joined, argv[i]);
		if (!joined)
			exit_handler(ERROR, NULL);
		free(prev_str);
		i++;
	}
	return (joined);
}

void	load_stack(t_ps *ps, int argn, const char **argv)
{
	char	*concatenated_args;
	char	*next_number;
	char	*number_end;
	size_t	numbers;
	int		n;

	//concatenated_args = join_args(argn, argv);
	//numbers = cnt_words(concatenated_args);

	next_number = concatenated_args;
	while (numbers--)
	{
		n = ft_strtol(next_number, &number_end);
		next_number = number_end;
		if (errno == ERANGE && (n & INT_MAX) == INT_MAX)
			exit_handler(ERROR, NULL);
		if (*number_end || has_value(n, stack))
			exit_handler(ERROR, NULL);
		stack->val[numbers] = n;
		stack->size++;
	}
	free(concatenated_args);
}
