/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:33:08 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/08 18:16:21 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "common.h"

# define BRUTEFORCE_DEPTH 6

char	*copy_instructions(t_list *last_instr);
//void	inc_instr(t_stacks *game, t_list *last_instr);
//void	delete_last_instr(t_backtrace_info *bi, t_stacks *game);
//void	sort_rotate_3(t_stacks *game, t_list **instr, size_t size);
void	optimizations(char *instr);

void	block_sort(t_ps *ps, t_list **instr, size_t blocks);
//char	*insertion_sort(t_stacks game);
//char	*bruteforce(t_stacks *game);
//void	quick(t_stacks *game, t_list **instr, int base_val, int top_val);
//void	bubble_sort(t_list **inst, t_stacks *game);
#endif
