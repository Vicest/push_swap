/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:23:44 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/16 21:23:51 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, const char **args)
{
	t_ps		ps;

	instr = NULL;
	if (argc == 1)
		exit_handler(SUCCS);
	set_up(&ps, argc, args);
	if (is_sorted(ps.stack_a))
		exit_handler(SUCCS);
	shortest = run_algorithms(t_ps *ps);
	print_instr(shortest);
	//system("leaks -q push_swap");
	exit_handler(SUCCS);
}
