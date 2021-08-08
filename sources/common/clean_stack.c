/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:29:30 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/08 21:31:26 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	clean_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->val)
			free(stack->val);
		free(stack);
	}
}
