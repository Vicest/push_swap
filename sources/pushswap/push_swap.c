/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:23:44 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/20 19:48:42 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, const char **args)
{
	t_ps	ps;
	char	*shortest;

	if (argc == 1)
		exit_handler(SUCCS);
	set_up(&ps, argc, args);
	if (is_sorted(ps.stack_a))
		exit_handler(SUCCS);
	shortest = run_algorithms(&ps);
	print_instr(shortest);
	free(shortest);
	exit_handler(SUCCS);
}
