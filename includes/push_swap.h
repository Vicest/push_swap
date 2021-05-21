/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:33:08 by vicmarti          #+#    #+#             */
/*   Updated: 2021/05/21 15:57:06 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "../libft/libft.h"
# include "common.h"


typedef struct	s_backtrace_info
{
	t_list				*instr1;
	t_list				*last_instr;
	char				*shortest;
	unsigned long		max_steps;
	unsigned long		step;
}				t_backtrace_info;

char	*start_backtrace(t_stacks *game);
char	*copy_instructions(t_list *last_instr);
int		is_sorted(t_stacks game);
void	inc_instr(t_stacks *game, t_list *last_instr);
void	delete_last_instr(t_backtrace_info *bi, t_stacks *game);
void	bubble_sort(t_list **inst, t_stacks *game);
#endif
