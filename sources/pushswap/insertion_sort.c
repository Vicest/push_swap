/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:30:37 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/16 22:41:00 by vicmarti         ###   ########.fr       */
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

static void	next_insertion(t_stacks *game, t_list **instr, int sorted_top_val)
{
	const int	d = insertion_distance(game, sorted_top_val);
	int			i;

	i = 0;
	if (d == 1)
		log_do(game, instr, SA);
	else if (d == -1)
	{
		log_and_do_sequence(game, instr (const char []){RRA, SA, RA, RA, 0});
		//log_do(game, instr, RRA);
		//log_do(game, instr, SA);
		//log_do(game, instr, RA);
		//log_do(game, instr, RA);
		//print_status(game);
	}
	else if (d > 1)
	{
		log_do(game, instr, PB);
		//print_status(game);
		while (i++ < d)
			log_do(game, instr, RA);
		log_do(game, instr, PA);
		//print_status(game);
		while (i-- > 0)
			log_do(game, instr, RRA);
		//print_status(game);
	}
	else
	{
		log_do(game, instr, PB);
		//print_status(game);
		while (d < i--)
			log_do(game, instr, RRA);
		log_do(game, instr, PA);
		//print_status(game);
		while (i++ < 0)
			log_do(game, instr, RA);
		//print_status(game);
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
	char	*instr_str;
	t_list	*instr;
	size_t	stack_imax;
	size_t	sorted_top_i;

	//TODO LOG&DO instructions
	/*
	**	Starting setup.
	*/
	/*
	**	Always just swap&rot when possible, should save steps.
	*/
	printf("START\n");
	print_status(&game);
	instr = NULL;
	if (*(game.top_a) > *(game.top_a - 1))
	{
		log_do(&game, &instr, SA);
		log_do(&game, &instr, RA);
	}
	log_do(&game, &instr, RA);
	sorted_top_i = 0;
	while (game.stack[sorted_top_i] > game.stack[sorted_top_i + 1])
		sorted_top_i++;
	stack_imax = (game.max_i - game.stack);
	printf("stackimax %lu\n", stack_imax);
	while (sorted_top_i < stack_imax)
	{
		if (*(game.top_a) > *(game.stack))
			log_do(&game, &instr, RA);
		else
			next_insertion(&game, &instr, game.stack[sorted_top_i]);
		sorted_top_i++;
		while (game.stack[sorted_top_i] > game.stack[sorted_top_i + 1]
			&& (sorted_top_i < stack_imax))
			sorted_top_i++;
	}
	if (is_sorted(game))
		write(1, "OK", 2);
	else
		write(1, "KO", 2);
	instr_str = copy_instructions(instr);
	ft_lstclear(&instr, NULL);
	return (instr_str);
}
