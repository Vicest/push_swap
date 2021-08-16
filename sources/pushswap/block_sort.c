/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 18:36:15 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/16 17:57:56 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //TODO

static void	place_greatest_smallest(t_ps *ps, t_list **instr)
{
	const size_t	size = ps->stack_b->size;
	size_t			i;

	i = 0;
	if (size == 0)
		return ;
	while (++i < size)
	{
		if (ps->stack_b->val[i - 1] > ps->stack_b->val[i])
		{
			if (i < size / 2)
				log_and_do_n(ps, instr, RRB, i);
			else
				log_and_do_n(ps, instr, RB, size - i);
			return;
		}
	}
}

static void	place_general_case(t_ps *ps, t_list **instr, int new_val)
{
	const size_t	size = ps->stack_b->size;
	size_t			i;

	i = 0;
	if (size == 0)
		return ;
	while (++i < size)
	{
		if (ps->stack_b->val[i - 1] < new_val && new_val <  ps->stack_b->val[i])
		{
			if (i < size / 2)
				log_and_do_n(ps, instr, RRB, i);
			else
				log_and_do_n(ps, instr, RB, size - i);
			return;
		}
	}
}

static void	set_stack_b(t_ps *ps, t_list **instr, int new_val)
{
	if (max_val(ps->stack_b) < new_val || min_val(ps->stack_b) > new_val)
		place_greatest_smallest(ps, instr);
	else
		place_general_case(ps, instr, new_val);
}

static void	set_stack_a(t_ps *ps, t_list **instr, int max_val)
{
	const size_t	size = ps->stack_a->size;
	size_t	i;
	size_t	rot;
	size_t	rrot;

	i = -1;
	rrot = 1;
	while (++i < size && ps->stack_a->val[i] > max_val)
		rrot++;
	i = size;
	rot = 0;
	while (--i > 0 && ps->stack_a->val[i] > max_val)
		rot++;
	if (rot < rrot)
		log_and_do_n(ps, instr, RA, rot);
	else
		log_and_do_n(ps, instr, RRA, rrot);
}

static void	push_block_sorted(t_ps *ps, t_list **instr, t_moves *sort_info,
		int max_val, size_t block_size)
{
	size_t	rrot_to_top;
	(void)sort_info;
	size_t	i;

	i = 0;
	while (i < block_size)
	{
		set_stack_a(ps, instr, max_val);
		set_stack_b(ps, instr, ps->stack_a->val[ps->stack_a->size - 1]);
		log_and_do_instr(ps, instr, PB);
		i++;
	}
	rrot_to_top = index_of(max_val, ps->stack_b) + 1;
	if (rrot_to_top < (ps->stack_b->size + 1) / 2)
		log_and_do_n(ps, instr, RRB, rrot_to_top);
	else
		log_and_do_n(ps, instr, RB, ps->stack_b->size - rrot_to_top);
}

void	block_sort(t_ps *ps, t_list **instr, size_t blocks)
{
	const size_t	block_size = ps->stack_a->size / blocks;
	const size_t	remainder_block = ps->stack_a->size % blocks;
	t_moves			sort_info;
	int				max_val;

	max_val = -1;
	while (blocks > 0)
	{
		max_val += block_size;
		push_block_sorted(ps, instr, &sort_info, max_val, block_size);
		blocks--;
	}
	max_val += remainder_block;
	push_block_sorted(ps, instr, &sort_info, max_val, remainder_block);
	log_and_do_n(ps, instr, PA, ps->stack_b->size);
}
