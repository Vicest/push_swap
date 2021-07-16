/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 20:38:00 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/16 22:44:44 by vicmarti         ###   ########.fr       */
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
# define NOP	'\x00'
# define SA		'\x01'
# define RA		'\x02'
# define RRA	'\x03'
# define SB		'\x04'
# define RB		'\x05'
# define RRB	'\x06'
# define SS		'\x07'
# define RR		'\x08'
# define RRR	'\x09'
# define PA		'\x0a'
# define PB		'\x0b'
# define LAST_INSTR 12

typedef struct s_stacks
{
	int		*max_i;
	int		*top_a;
	int		*stack;
}			t_stacks;

void	exit_handler(char status, void *stc_mem);

void	load_stack(t_stacks *game, int argn, const char **argv);
int		is_sorted(t_stacks game);

/*
**	Instructions
*/
void	swap(t_stacks *game, char which);
void	push(t_stacks *game, char which);
void	rrot(t_stacks *game, char which);
void	rot(t_stacks *game, char which);

void	do_instr(t_stacks *game, char instr_id);
void	undo_instr(t_stacks *game, char instr_id);
void	log_and_do_instr(t_stacks *game, t_list **instr, char instr_id);
void	log_and_do_n(t_stacks *game, t_list **instr, char instr_id, size_t n);
void	log_and_do_sequence(t_stacks *game, t_list **instr, const char list[]);
#endif
