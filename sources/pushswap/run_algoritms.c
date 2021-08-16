/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_algoritms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 20:01:11 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/16 21:23:51 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Pseudo code warning TODO
char	*run_algorithms(t_ps *ps)
{
	t_list	*instr;
	char	*tmp;
	char	*shortest;

	if (size < 10)
		return brute();
	else
	{
		shortest = block_sorr(2);
		shortest = copy_instructions(instr);
		optimizations(shortest);
		ft_lstclear(&instr);
		block = 3;
		while (block < size / 10)
		{
			reset(ps);
			tmp = block_sort(blocks++);
			tmp = copy_instructions(instr);
			optimizations(tmp);
			ft_lstclear(&instr);
			if (ft_strlen(shortest) > ft_strlen(tmp))
			{
				free(shortest);
				shortest = tmp;
			}
			else
				free(tmp);
		}
	}
	return (shortest);
}
