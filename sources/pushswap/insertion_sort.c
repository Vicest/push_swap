/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:30:37 by vicmarti          #+#    #+#             */
/*   Updated: 2021/06/03 13:09:18 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

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
	int	a_size;

	i = 0;
	while (*(game->top_a) < game->stack[i] && sorted_top_val != game->stack[i])
		i++;
	a_size = game->top_a - game->stack;
	if (a_size - i < i)
		return (a_size - i);
	return (-i);
}

/*
**	Performs an essential step in the insertion sort algorithm.
**	Place the top of the unsorted stack into the sorted stack.
**	It checks the distance to said position to choose the shortest path
*/

static void	next_insertion(t_stacks *game, int sorted_top_val)
{
	int	d = insertion_distance(game, sorted_top_val);
	int	i = 0;

	if (d == 1)
		swap(game, A);
	else if (d == -1)
	{
		rrot(game, A);
		swap(game, A);
		rot(game, A);
		rot(game, A);
	}
	else if (d > 1)
	{
		push(game, B);
		while (i++ < d)
			rot(game, A);
		push(game, A);
		while (i-- > 0)
			rrot(game, A);
	}
	else
	{
		push(game, B);
		while (i-- < d)
			rrot(game, A);
		push(game, A);
		while (i++ <= d)
			rot(game, A);
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
	//t_list	instr;
	size_t	stack_imax;
	size_t	sorted_top_i;

	//TODO LOG&DO instructions
	/*
	**	Starting setup.
	*/
	if (*(game.top_a) > *(game.top_a - 1))
	{
		swap(&game, A);
		rot(&game, A);
	}
	rot(&game, A);
	sorted_top_i = 0;
	while (game.stack[sorted_top_i] > game.stack[sorted_top_i + 1])
		sorted_top_i++;
	stack_imax = (game.max_i - game.stack);
	/*
	**	Loop proper.
	*/
	while (sorted_top_i < stack_imax)
	{
		if (*(game.top_a) > *(game.stack))
			rot(&game, A);
		else
			next_insertion(&game, game.stack[sorted_top_i]);
		sorted_top_i++;
		while (game.stack[sorted_top_i] > game.stack[sorted_top_i + 1] &&
				(sorted_top_i < stack_imax))
			sorted_top_i++;
	}
	if (is_sorted(game))
		write(1, "OK", 2);
	else
		write(1, "KO", 2);

	return ("here be instructions");
}
