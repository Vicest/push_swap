/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:44:34 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/17 22:03:19 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h> //TODO  strtoi
#include <errno.h>
#include "common.h"

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

void	load_stack(t_stacks *game, int argn, const char **argv)
{
	char	*concatenated_args;
	char	*next_number;
	char	*number_end;
	size_t	numbers;

	concatenated_args = join_args(argn, argv);
	numbers = cnt_words(concatenated_args);
	game->stack = malloc(numbers * sizeof(int));
	if (!game->stack)
		exit_handler(ERROR, NULL);
	game->max_i = game->stack + numbers - 1;
	game->top_a = game->max_i;
	next_number = concatenated_args;
	while (numbers--)
	{
		game->stack[numbers] = ft_strtol(next_number, &number_end);
		next_number = number_end;
		if (errno == ERANGE && (game->stack[numbers] & INT_MAX) == INT_MAX)
			exit_handler(ERROR, game->stack);
	}
	if (*number_end || has_dup(game->stack, game->max_i))
		exit_handler(ERROR, game->stack);
	free(concatenated_args);
}
