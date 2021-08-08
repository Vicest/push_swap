/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:21:50 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/08 21:22:21 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	init_stack(t_stack **stack, size_t size)
{
	t_stack	*aux;

	aux = *stack;
	aux = malloc(sizeof(t_stack));
	if (!aux)
		exit_handler(ERROR);
	aux->val = ft_calloc(size, sizeof(int));
	if (!aux->val)
		exit_handler(ERROR);
	aux->size = 0;
	aux->max_size = size;
	*stack = aux;
}
