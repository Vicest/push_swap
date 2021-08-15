/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 18:36:15 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/15 16:55:45 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //TODO

static size_t	place_greatest(t_stack *stack)
{
	const size_t	size = stack->size;
	size_t			i;

	i = 0;
	if (size == 0)
		return (i);
	while (++i < size)
		if (stack->val[i - 1] > stack->val[i])
			return (i);
	return (i);
}

static size_t	index_sorted(t_stack *stack, int new_val)
{
	const size_t	size = stack->size;
	size_t			i;

	if (max_val(stack) < new_val)
		return (place_greatest(stack));
	if (stack->val[0] > new_val && new_val > stack->val[size - 1])
		return (0);
	i = 0;
	while (++i < size)
		if (stack->val[i - 1] < new_val && new_val < stack->val[i])
			return (i);
	return (size);
}

//SET ROTATIONS WITH A|B  TODO when B is unsorted and pushable is lowest or greatest
static void	adjust_rotations_with_b(t_stack *stack, t_moves *sort_info)
{
	size_t	size = stack->size;

	sort_info->b_base = index_sorted(stack, sort_info->base_candidate);
	if (sort_info->b_base == stack->size)
		sort_info->b_base = 0;
	sort_info->best_base = ft_max(sort_info->a_base, sort_info->b_base);
	sort_info->b_top = size - index_sorted(stack, sort_info->top_candidate);
	if (sort_info->b_top == stack->size)
		sort_info->b_top = 0;
	sort_info->best_top = ft_max(sort_info->a_top, sort_info->b_top);
}

static void	set_stacks(t_ps *ps, t_moves *sort_info, t_list **instr)
{
	//PSEUDO -> Needs cleaning
	//TODO Consider that size+ rotates are possible as well
	if (sort_info->best_base > sort_info->best_top)
	{
		if (sort_info->a_top > sort_info->b_top)
		{
			log_and_do_n(ps, instr, RR, sort_info->b_top);
			log_and_do_n(ps, instr, RA, sort_info->best_top
					- ft_min(sort_info->a_top, sort_info->b_top));
		}
		else
		{
			log_and_do_n(ps, instr, RR, sort_info->a_top);
			log_and_do_n(ps, instr, RB, sort_info->best_top
					- ft_min(sort_info->a_top, sort_info->b_top));
		}
	}
	else
	{
		if (sort_info->a_base > sort_info->b_base)
		{
			log_and_do_n(ps, instr, RRR, sort_info->b_base);
			log_and_do_n(ps, instr, RRA, sort_info->best_base
					- ft_min(sort_info->a_base, sort_info->b_base));
		}
		else
		{
			log_and_do_n(ps, instr, RRR, sort_info->a_base);
			log_and_do_n(ps, instr, RRB, sort_info->best_base
					- ft_min(sort_info->a_base, sort_info->b_base));
		}
	}
}

static void	push_block_sorted(t_ps *ps, t_list **instr, t_moves *sort_info,
		int max_val, size_t block_size)
{
	size_t	rrot_to_top;
	size_t	i;

	i = 0;
	while (i < block_size)
	{
		find_candidates(ps->stack_a, sort_info, max_val);
		adjust_rotations_with_b(ps->stack_b, sort_info);
		set_stacks(ps, sort_info, instr);
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
	print_status(ps);
}
