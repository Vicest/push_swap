/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:02:44 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/15 16:03:44 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_instr(char *str)
{
	while (*(str++))
	{
		if (*(str - 1) == SA)
			ft_putstr_fd("sa\n", 1);
		else if (*(str - 1) == RA)
			ft_putstr_fd("ra\n", 1);
		else if (*(str - 1) == RRA)
			ft_putstr_fd("rra\n", 1);
		else if (*(str - 1) == SB)
			ft_putstr_fd("sb\n", 1);
		else if (*(str - 1) == RB)
			ft_putstr_fd("rb\n", 1);
		else if (*(str - 1) == RRB)
			ft_putstr_fd("rrb\n", 1);
		else if (*(str - 1) == SS)
			ft_putstr_fd("ss\n", 1);
		else if (*(str - 1) == RR)
			ft_putstr_fd("rr\n", 1);
		else if (*(str - 1) == RRR)
			ft_putstr_fd("rrr\n", 1);
		else if (*(str - 1) == PA)
			ft_putstr_fd("pa\n", 1);
		else if (*(str - 1) == PB)
			ft_putstr_fd("pb\n", 1);
	}
}
