/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:18:33 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/08 21:41:32 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	copy(t_stack **dst, t_stack *src)
{
	t_stack	*aux;
	size_t	i;

	init_stack(dst, src->size);
	aux = *dst;
	i = -1;
	while (++i < src->size)
		aux->val[i] = src->val[i];
}
