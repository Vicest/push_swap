/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:13:24 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/08 16:10:09 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	swap(t_stack *stack)
{
	const size_t	top = stack->size - 1;

	if (stack->size > 1)
		ft_swap(&(stack->val[top]), &(stack->val[top - 1]));
}
