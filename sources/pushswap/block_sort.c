/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 18:36:15 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/09 20:04:31 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //TODO
/*
static int	find_min(t_stack *stack) //TODO
{
	size_t	i;
	int		min;
	
	i = 0;
	min = stack->val[i];
	while (++i < stack->size)
	{
		if (min > stack->val[i])
			min = stack->val[i];
	}
	return (min);
}*/

static size_t	find_from_top(t_stack *stack, int max_pickable)
{
	int		*top;
	size_t	i;

	top = stack->val + stack->size - 1;
	i = 1;
	while (stack->val[stack->size - i] > max_pickable)
		i++;
	return (i - 1);
}

static size_t	find_from_base(t_stack *stack, int max_pickable)
{
	size_t	i;

	i = 0;
	while (stack->val[i] > max_pickable)
		i++;
	return (i + 1);
}

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

static void	push_block_sorted(t_ps *ps, t_list **instr,
		int min_val, size_t block_size)
{
	size_t	i;
	size_t	rra_to_top;
	size_t	ra_to_top;
	//Pseudo
	i = 0;
	while (i < block_size)
	{
		//TODO Can fit in one if needed
		rra_to_top = find_from_base(ps->stack_a, min_val + block_size);
		ra_to_top = find_from_top(ps->stack_a, min_val + block_size);
		//TODO Check B
		//set_stacks(stack_a, stack_b, dir, value);
		if (rra_to_top > ra_to_top)
			log_and_do_n(ps, instr, RA, ra_to_top);
		else
			log_and_do_n(ps, instr, RRA, rra_to_top);
		log_and_do_instr(ps, instr, PB);
		i++;
	}
}

void	block_sort(t_ps *ps, t_list **instr, size_t blocks)
{
	const size_t	block_size = ps->stack_a->size / blocks;
	const size_t	remainder_block = ps->stack_a->size % blocks;
	int		min_val;

	print_status(ps);
	min_val = block_size - 1;
	while (blocks > 0)
	{
		push_block_sorted(ps, instr, min_val, block_size);
		min_val += block_size;
		print_status(ps);
		blocks--;
	}
	push_block_sorted(ps, instr, min_val, remainder_block);
	print_status(ps);
}
