/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:48:17 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/08 15:56:46 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	is_sorted(t_stack *stack)
{
	size_t	i;

	i = 1;
	while (i < stack->size && stack->val[i - 1] > stack->val[i])
		i++;
	return (1 >= stack->size);
}
