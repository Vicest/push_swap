/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:17:25 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/25 18:46:09 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void quick_sort(int *arr, size_t size

void	preprocess_stack(t_stacks *game)
{
	size_t	size = (game->max_i + 1 - game->stack) * sizeof(int)
	int		*stack_cpy;
	int		i

	stack_cpy = malloc(size);
	if (!stack_cpy)
		exit_status(game->stack, ERROR);
	quick_sort(stack_cpy);
	i = -1;
	while (++i < size)
		game->copy[i] = binary_search(stack_copy, game->copy[i]);
	free(stack_cpy);
}
