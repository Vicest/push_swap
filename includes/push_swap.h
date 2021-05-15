/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:33:08 by vicmarti          #+#    #+#             */
/*   Updated: 2021/05/15 19:57:46 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include "common.h"

# define NOP	-1
# define SA		0
# define RA		1
# define RRA	2
# define LAST_INSTR 2

typedef struct	s_backtrace_info
{
	t_list				*instr1;
	t_list				*last_instr;
	char				*shortest;
	unsigned long		max_steps;
	unsigned long		step;
}				t_backtrace_info;

char	*backtrace(t_stacks *game);
void	bubble_sort(t_list **inst, t_stacks *game);
void	try_ra(t_list **inst, t_stacks *game, int steps, char *f);
void	try_sa(t_list **inst, t_stacks *game, int steps, char *f, char *prev);
#endif
