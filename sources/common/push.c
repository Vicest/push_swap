/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 20:56:05 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/07 17:54:24 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	push(t_stack *dst, t_stack *src)
{
	if (src->size > 0)
	{
		ft_swap(dst->val[dst->size], src->val[src->size - 1]);
		dst->size++;
		src->size--;
	}
}
