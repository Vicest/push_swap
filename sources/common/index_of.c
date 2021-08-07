/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_of.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 21:43:49 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/07 18:23:08 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

size_t	index_of(int value, t_stack *stack)
{
	size_t	index;

	index = 0;
	while (stack->val[index] != value)
		index++;
	return (index);
}
