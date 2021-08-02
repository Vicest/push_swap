/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_of.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 21:43:49 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/01 17:38:23 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

size_t	index_of(int value, t_stacks *game)
{
	size_t	index;

	index = 0;
	while (game->stack[index] != value)
		index++;
	return (index);
}
