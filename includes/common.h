/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 20:38:00 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/12 21:32:32 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include "../libft/libft.h"
# define SUCCS 0
# define ERROR 1

# define A 0b01
# define B 0b10

//TODO: Check if it can be simplified
# define NOP	0
# define SA		1
# define RA		2
# define RRA	3
# define SB		4
# define RB		5
# define RRB	6
# define SS		7
# define RR		8
# define RRR	9
# define PA		10
# define PB		11
# define LAST_INSTR 12

typedef struct s_stacks
{
	int		*max_i;
	int		*top_a;
	int		*stack;
}			t_stacks;

int		is_sorted(t_stacks game);
int		get_next_line(char **line);
void	exit_handler(char status, void *stc_mem);
void	load_stack(t_stacks *game, int argn, const char **argv);

/*
**	Instructions
*/
void	do_instr(t_stacks *game, char instr_id);
void	undo_instr(t_stacks *game, char instr_id);
void	log_do(t_stacks *game, t_list **instr, char instr_id);
void	swap(t_stacks *game, char which);
void	push(t_stacks *game, char which);
void	rrot(t_stacks *game, char which);
void	rot(t_stacks *game, char which);
#endif
