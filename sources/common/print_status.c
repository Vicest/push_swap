/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:38:14 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/05 15:28:04 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_status(t_stacks *s)
{
	size_t	i;

	i = 0;
	while (s->stack[i] != *(s->max_i))
	{
		printf(" %d", s->stack[i]);
		if (s->stack[i] == *(s->top_a))
			printf(" |");
		i++;
	}
	printf(" %d\n", s->stack[i]);
}
