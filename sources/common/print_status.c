/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:38:14 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/09 17:21:22 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdio.h>

static void	print_stack(t_stack *stack)
{
	size_t	i;

	if (stack->size > 0)
	{
		i = 0;
		printf("%d", stack->val[i]);
		while (++i < stack->size)
			printf(" %d", stack->val[i]);
	}
	printf("\n");
}

void	print_status(t_ps *ps)
{
	printf("A|");
	print_stack(ps->stack_a);
	printf("B|");
	print_stack(ps->stack_b);
}
