/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size2_insertion_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 17:39:49 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/20 18:38:35 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include <stdio.h>

static int	insertion_distance(t_stacks *game, int sorted_top_val)
{
	const int	i = distance_to_ordered_pos(game, game->top_a[0]);
	const int	stacka_size = game->top_a - game->stack + 1;

	if (stacka_size / 2 < i)
		return (stacka_size - i);
	return (-i);
}

static int	distance_to_ordered_pos(t_stack *game, int val)
{
	int	i;

	i = 0;
	while (val < game->stack[i] && game->stack + i < game->top_a)
		i++;
	return (i);
}

static void	pb_rrotate_pa_rotate(t_stack *game, t_list **instr, int d)
{
	int	tot_rotations
	log_and_do_instr(game, instr, PB);
	log_and_do_instr(game, instr, PB);
	log_and_do_n(game, instr, RRA, d);
	log_and_do_instr(game, instr, PA);
	log_and_do_n(game, instr, RA, d);
}

static void	pb_rotate_pa_rrotate(t_stack *game, t_list **instr, int d)
{
	log_and_do_instr(game, instr, PB);
	log_and_do_n(game, instr, RA, d);
	log_and_do_instr(game, instr, PA);
	log_and_do_n(game, instr, RRA, d);
}

static void	next_insertion(t_stacks *game, t_list **instr, int sorted_top_val)
{
	const int	 = insertion_distance(game, sorted_top_val);

	if (d == 0)
		log_and_do_instr(game, instr, RA);
	else if (d == 1)
		log_and_do_instr(game, instr, SA);
	else if (d > 1)
		pb_rotate_pa_rrotate(game, instr, d);
	else
		pb_rrotate_pa_rotate(game, instr, -d);
}

char	*size_2insertion_sort(t_stacks game)
{
	const size_t	element_number = game.max_i - game.stack;
	size_t	sorted_top_i;
	char	*instr_str;
	t_list	*instr;

	/*
	**	Starting setup.
	*/
	instr = NULL;
	print_status(&game);
	if (game.top_a[0] > game.top_a[-1])
		log_and_do_instr(&game, &instr, SA);
	while (game.top_a[0] > game.stack[0])
		log_and_do_instr(&game, &instr, RA);
	print_status(&game);
	sorted_top_i = 0;
	while (sorted_top_i < element_number)
	{
		if (game.stack[sorted_top_i] > game.stack[sorted_top_i + 1])
			sorted_top_i++;
		else
			next_insertion(&game, &instr, game.stack[sorted_top_i]);
	}
	print_status(&game);
	if (is_sorted(game))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	instr_str = copy_instructions(instr);
	ft_lstclear(&instr, NULL);
	return (instr_str);
}
