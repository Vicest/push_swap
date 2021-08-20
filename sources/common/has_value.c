/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 18:55:11 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/20 19:44:19 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	has_value(int n, t_stack *stack)
{
	size_t	i;

	i = 0;
	while (i < stack->size && stack->val[i] == n)
		i++;
	return (i < stack->size);
}
