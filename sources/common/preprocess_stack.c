/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:17:25 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/06 16:28:28 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	preprocess_stack(t_stacks *game)
{
	const size_t	len = (game->max_i + 1 - game->stack);
	size_t			pos_in_stack;
	size_t			i;
	int				*stack_cpy;

	stack_cpy = malloc(len * sizeof(int));
	if (!stack_cpy)
		exit_handler(ERROR, game->stack);
	i = -1;
	while (++i < len)
		stack_cpy[i] = game->copy[i];
	arr_sort(stack_cpy, len);
	i = -1;
	while (++i < len)
	{
		pos_in_stack = index_of(stack_cpy[i], game);
		game->copy[pos_in_stack] = i;
	}
	free(stack_cpy);
	reset(game);
}
