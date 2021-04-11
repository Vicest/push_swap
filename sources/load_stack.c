/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:44:34 by vicmarti          #+#    #+#             */
/*   Updated: 2021/04/11 19:03:15 by vicmarti         ###   ########.fr       */
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

void	load_stack(t_psh_swp *game, const char *nums)
{
	char	*end;
	size_t	len;

	len = cnt_words(nums);
	game->stack = malloc(len * sizeof(int));
	if (!game->stack)
		exit_handler(ERROR, NULL);
	game->max_i = game->stack + len - 1;
	game->top_a = game->max_i;
	while (len-- > 0)
	{
		game->stack[len] = ft_strtol(nums, &end);
		nums = end;
		if (errno == ERANGE && (game->stack[len] & INT_MAX) == INT_MAX)
				exit_handler(ERROR, game->stack);
	}
	if (*end || has_dup(game->stack, game->max_i))
		exit_handler(ERROR, game->stack);
}

