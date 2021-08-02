/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_insertion_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 14:19:52 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/25 18:46:09 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

static int	insertion_distance(t_stacks *game, int sorted_top_val)
{
	int	i;
	int	stacka_size;

	i = 0;
	do_instr(game, PB);
	while (game->top_a[1] < game->stack[i] && sorted_top_val != game->stack[i])
		i++;
	stacka_size = game->top_a - game->stack + 1;
	do_instr(game, PA);
	if (stacka_size / 2 < i)
		return (stacka_size - i);
	return (-i);
}

static void	pb_rrotate_pa_rotate(t_stacks *game, t_list **instr, int d)
{
	log_and_do_instr(game, instr, PB);
	log_and_do_n(game, instr, RRA, d);
	log_and_do_instr(game, instr, PA);
	log_and_do_n(game, instr, RA, d);
}

static void	pb_rotate_pa_rrotate(t_stacks *game, t_list **instr, int d)
{
	log_and_do_instr(game, instr, PB);
	log_and_do_n(game, instr, RA, d);
	log_and_do_instr(game, instr, PA);
	log_and_do_n(game, instr, RRA, d);
}

static void	next_insertion(t_stacks *game, t_list **instr, int *sorted_top, int block_size)
{
	log_and_do_n(game, instr, PB, ft_min(game->max_i - sorted_top, block_size));
	reverse_sort_b(game, instr);
	else if (d > 1)
		pb_rotate_pa_rrotate(game, instr, d);
	else
		pb_rrotate_pa_rotate(game, instr, -d);
}

char	*block_insertion_sort(t_stacks game, int block_size)
{
	const size_t	element_number = game.max_i - game.stack;
	size_t			sorted_top_i;
	char			*instr_str;
	t_list			*instr;

	instr = NULL;
	if (game.top_a[0] > game.top_a[-1])
		log_and_do_instr(&game, &instr, SA);
	sorted_top_i = 0;
	while (sorted_top_i < element_number)
	{
		if (game.stack[sorted_top_i] > game.stack[sorted_top_i + 1])
			sorted_top_i++;
		else
			next_insertion(&game, &instr, sorted_top_i, block_size);
	}
	if (is_sorted(game))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	instr_str = copy_instructions(instr);
	ft_lstclear(&instr, NULL);
	return (instr_str);
}
