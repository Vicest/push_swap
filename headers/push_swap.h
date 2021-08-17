/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:33:08 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/17 18:01:13 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "common.h"

# define BRUTEFORCE_DEPTH 6

typedef struct s_moves
{
	size_t	a_top;
	size_t	a_base;
	size_t	b_top;
	size_t	b_base;
	size_t	best_top;
	size_t	best_base;
	int		top_candidate;
	int		base_candidate;
}			t_moves;

char	*copy_instructions(t_list *last_instr);
void	print_instr(char *str);
void	set_up(t_ps *ps, int argc, const char **args);
char	*run_algorithms(t_ps *ps);
void	optimizations(char *instr);
//void	inc_instr(t_stacks *game, t_list *last_instr);
//void	delete_last_instr(t_backtrace_info *bi, t_stacks *game);
//void	sort_rotate_3(t_stacks *game, t_list **instr, size_t size);

char	*block_sort(t_ps *ps, size_t blocks);
char	*bruteforce(t_ps *ps);
//char	*insertion_sort(t_stacks game);
//void	quick(t_stacks *game, t_list **instr, int base_val, int top_val);
//void	bubble_sort(t_list **inst, t_stacks *game);

void	rotate_value_to_top(int value, t_stack *stack, t_list **instr);
void	find_candidates(t_stack *stack, t_moves *sort_info, int max_pick);
#endif
