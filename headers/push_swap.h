/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:33:08 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/20 20:12:35 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "common.h"

# define BRUTEFORCE_DEPTH 6

char	*copy_instructions(t_list *last_instr);
void	print_instr(char *str);
void	set_up(t_ps *ps, int argc, const char **args);
char	*run_algorithms(t_ps *ps);
void	push_block_sorted(t_ps *ps, t_list **instr, int max_val,
			size_t block_size);

char	*block_sort(t_ps *ps, size_t blocks);
char	*bruteforce(t_ps *ps);

#endif
