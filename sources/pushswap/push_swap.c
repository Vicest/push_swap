/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:23:44 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/15 16:26:14 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, const char **args)
{
	t_ps		ps;
	t_list		*instr;
	size_t		blocks;
	//char		*tmp;
	char		*shortest;

	instr = NULL;
	if (argc == 1)
		exit_handler(SUCCS);
	set_up(&ps, argc, args);
	if (is_sorted(ps.stack_a))
		exit_handler(SUCCS);
	blocks = 3;
	block_sort(&ps, &instr, blocks);
	shortest = copy_instructions(instr);
	ft_lstclear(&instr, NULL);
	optimizations(shortest);
	/*
	while (++blocks < ps)
	{
		block_sort(&ps, &instr, blocks);
		tmp = copy_instructions(instr);
		ft_lstclear(&instr, NULL);
		optimizations(tmp);
		if (ft_strlen(tmp) < ft_strlen(shortest))
		{
			free(shortest);
			shortest = tmp;
		}
		else
			free(tmp);
		tmp = NULL;
	}
*/


	print_instr(shortest);
	//system("leaks -q push_swap");
	exit_handler(SUCCS);
}
