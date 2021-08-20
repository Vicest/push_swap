/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_block_sorted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:05:28 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/20 20:12:35 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			return ;
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
		if (ps->stack_b->val[i - 1] < new_val && new_val < ps->stack_b->val[i])
		{
			if (i < size / 2)
				log_and_do_n(ps, instr, RRB, i);
			else
				log_and_do_n(ps, instr, RB, size - i);
			return ;
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
	size_t			i;
	size_t			rot;
	size_t			rrot;

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

void	push_block_sorted(t_ps *ps, t_list **instr, int max_val,
			size_t block_size)
{
	size_t	rrot_to_top;
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
