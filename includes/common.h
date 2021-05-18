/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:49:43 by vicmarti          #+#    #+#             */
/*   Updated: 2021/05/18 14:03:03 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include "../libft/libft.h"
# define SUCCS 0
# define ERROR 1
# define NOP	0
# define SA		1
# define RA		2
# define RRA	3
# define LAST_INSTR 3

typedef struct s_stacks
{
	int		*max_i;
	int		*top_a;
	int		*stack;
}			t_stacks;

int		is_sorted(t_stacks game);
void	do_instr(t_stacks *game, char instr_id);
void	undo_instr(t_stacks *game, char instr_id);
int		get_next_line(char **line);
void	exit_handler(char status, void *stc_mem);
void	load_stack(t_stacks *game, const char *nums);
void	swap(t_stacks *game, char *spec);
void	rot(t_stacks *game, char *spec);
#endif
