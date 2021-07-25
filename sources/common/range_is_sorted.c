/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 18:33:43 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/25 18:45:18 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	range_is_sorted(t_stacks *game, size_t base, size_t top)
{
	while (base < top && game->stack[base] < game->stack[base + i])
		base++;
	return (base == top);
}
