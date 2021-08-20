/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 18:36:15 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/20 20:06:04 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*block_sort(t_ps *ps, size_t blocks)
{
	const size_t	block_size = ps->stack_a->size / blocks;
	const size_t	remainder_block = ps->stack_a->size % blocks;
	t_list			*instr;
	char			*result;
	int				max_val;

	instr = NULL;
	max_val = -1;
	while (blocks > 0)
	{
		max_val += block_size;
		push_block_sorted(ps, &instr, max_val, block_size);
		blocks--;
	}
	max_val += remainder_block;
	push_block_sorted(ps, &instr, max_val, remainder_block);
	log_and_do_n(ps, &instr, PA, ps->stack_b->size);
	result = copy_instructions(instr);
	ft_lstclear(&instr, NULL);
	return (result);
}
