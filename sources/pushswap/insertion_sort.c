/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:30:37 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/18 21:48:22 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include <stdio.h>

/*
** The value to insert is at the top of the stack.
** Distance is the number of elements the stack needs to rotate through to let
** the top be the element that goes right below the inserted value.
** Positive distance means going through the unsorted sub-stack.
** Negative distance means traversing the sorted sub-stack.
** The stack may rotate either way.
** The values below top and before sorted_top_val are unsorted, we ignore them.
** The values below sorted_top_val are already sorted.
*/

static int	insertion_distance(t_stacks *game, int sorted_top_val)
{
	int	i;
	int	stacka_size;

	i = 0;
	while (game->top_a[0] < game->stack[i] && sorted_top_val != game->stack[i])
		i++;
	i++;
	stacka_size = game->top_a - game->stack;
	print_status(game);
	printf("A:%d|I:%d\n", stacka_size, sorted_top_val);
	if (stacka_size - i < i)
		return (stacka_size - i);
	return (-i);
}

/*
**	Performs an essential step in the insertion sort algorithm.
**	Place the top of the unsorted stack into the sorted stack.
**	It checks the distance to said position to choose the shortest path
*/

static void	next_insertion(t_stacks *game, t_list **instr, int sorted_top_val)
{
	const int	d = insertion_distance(game, sorted_top_val);

	if (d == 1)
		log_and_do_instr(game, instr, SA);
	else if (d == -1)
		log_and_do_sequence(game, instr, (const char []){RRA, SA, RA, RA, 0});
	else if (d > 1) //Go through the unsorted stack
	{
		log_and_do_instr(game, instr, PB);
		log_and_do_n(game, instr, RA, d);
		log_and_do_instr(game, instr, PA);
		log_and_do_n(game, instr, RRA, d);
	}
	else //Go through the sorted stack
	{
		log_and_do_instr(game, instr, PB);
		log_and_do_n(game, instr, RRA, d);
		log_and_do_instr(game, instr, PA);
		log_and_do_n(game, instr, RA, d);
	}
}

/*
** For the insertion sort we handle two sub-stacks, sorted and unsorted.
** The sorted stack is kept track of from the top.
** The sorted stack will progressively grow through insertions.
** The value to insert starts at the top of the stack.
** The general-case of an insertion is saving said value into the temp stack.
** Rotate the stack to find the insertion place.
** Restore ("reverse rotate") the stack to let the top be the next elem.
*/

char	*insertion_sort(t_stacks game)
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
	if (is_sorted(game))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	instr_str = copy_instructions(instr);
	ft_lstclear(&instr, NULL);
	return (instr_str);
}
