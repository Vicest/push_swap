/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:18:33 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/17 20:36:57 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	copy(t_stack *dst, t_stack *src)
{
	size_t	i;

	i = -1;
	while (++i < src->size)
		dst->val[i] = src->val[i];
	dst->max_size = src->max_size;
	dst->size = src->size;
}
