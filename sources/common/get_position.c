/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 20:08:17 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/31 16:19:55 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	*get_position(int value, t_stacks *game)
{
	int	*i;

	i = game->max_i;
	while (i >= game->stack)
	{
		if (*i == value)
			return (i);
		i--;
	}
	return (0);
}