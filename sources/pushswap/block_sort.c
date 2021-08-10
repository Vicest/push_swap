/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 18:36:15 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/10 20:29:35 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdboll.h>
#include <stdio.h> //TODO

static size_t	where_index(t_stack *stack, int new_val) //TODO name
{
	const size_t	size = stack->size;
	size_t	i;

	i = 1;
	while (i < size)
	{
		if (stack->val[i - 1] < new_val && new_val < stack->val[i])
			return (i);
	}
	return (0);
}

static size_t	find_candidates(t_stack *stack, t_block_aux *sort_info,
		int max_pickable)
{
	const size_t	size = stack->size;
	size_t			i;
	bool			found_one;

	found_one = false;
	i = 0;
	while (i < size)
	{
		if (stack->val[i] <= max_pickable)
		{
			sort_info->top_candidate = stack->val[i];
			sort_info->top_rotates = size - i - 1;
			if (!found_one)
			{
				found_one = true;
				sort_info->base_candidate = sort_info->top_candidate;
				sort_info->base_rrotates = i + 1;
			}
			i++;
		}
	}
}

//SET ROTATIONS WITH A|B  TODO
static void	adjust_rotations_with_b(t_stack *stack, t_block_aux *sort_info)
{
	size_t	size = stack->size;

	sort_info->b_base_rrot = 1 + where_index(stack,
			sort_info->base_candidate);
	sort_info->b_top_rot = size - 1
		- where_index(stack, sort_info->top_candidate);
	sort_info->best_top_rot =
		ft_min(sort_info->a_top_rot, sort_info->b_top_rot);
	sort_info->best_base_rot =
		ft_min(sort_info->a_base_rrot, sort_info->b_base_rrot);
}

static void	set_stacks(t_ps *ps, t_block_aux *sort_info, t_list **instr)
{
	//PSEUDO
	//TODO Consider that size+ rotates are possible as
	if (best_bot > best_top)
	{
		if (a_top > b_top)
			log_and_do_n(RR, b_top);
			log_and_do_n(RA, best_top - min(a_top, b_top));
		else
			log_and_do_n(RR, a_top);
			log_and_do_n(RB, best_top - min(a_top, b_top));
	}
	else
	{
		if (a_base > b_base)
			log_and_do_n(RRR, b_base);
			log_and_do_n(RRA, best_base - min(a_top, b_top));
		else
			log_and_do_n(RRR, a_base);
			log_and_do_n(RRB, best_base - min(a_top, b_top));
	}
}

static void	push_block_sorted(t_ps *ps, t_list **instr, t_block_aux *sort_info,
		int min_val, size_t block_size)
{
	size_t	i;
	size_t	rra_to_top;
	size_t	ra_to_top;

	i = 0;
	while (i < block_size)
	{
		find_candidates(ps->stack_a, sort_info, min_val + block_size);
		adjust_rotations_with_b(ps->stack_b, sort_info);
		set_stacks(ps, sort_info, instr);
		log_and_do_instr(ps, instr, PB);
		i++;
	}
}

void	block_sort(t_ps *ps, t_list **instr, size_t blocks)
{
	const size_t	block_size = ps->stack_a->size / blocks;
	const size_t	remainder_block = ps->stack_a->size % blocks;
	t_block_aux		sort_info;
	int				min_val;

	print_status(ps);
	min_val = block_size - 1;
	while (blocks > 0)
	{
		push_block_sorted(ps, instr, &block_aux, min_val, block_size);
		min_val += block_size;
		print_status(ps);
		blocks--;
	}
	push_block_sorted(ps, instr, &block_aux, min_val, remainder_block);
	//TODO SEND BACK TO A
	print_status(ps);
}
