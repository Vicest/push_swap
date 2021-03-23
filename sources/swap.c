/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:13:24 by vicmarti          #+#    #+#             */
/*   Updated: 2021/03/22 15:51:40 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void ft_swap(int *a, int *b)
{
	int	swp;

	swp = *a;
	*a = *b;
	*b = swp;
}

void	swap(t_psh_swp stack, char spec)
{
	int	swp;

	if ((spec == 'a' || spec == 's') && stack.top.a  )
		ft_swap(&stack.a[stack.top_a],&stack.a[(stack.top_a - 1) ]);
}

		
