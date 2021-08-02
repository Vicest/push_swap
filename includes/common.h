/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 20:38:00 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/01 20:54:15 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define SUCCS 0
# define ERROR 1

# define A 0b01
# define B 0b10

# define NOP	'\x00'
# define SA		'\x41'
# define RA		'\x42'
# define RRA	'\x43'
# define SB		'\x44'
# define RB		'\x45'
# define RRB	'\x46'
# define SS		'\x47'
# define RR		'\x48'
# define RRR	'\x49'
# define PA		'\x4a'
# define PB		'\x4b'
# define FIRST_INSTR SA
# define LAST_INSTR PB

typedef struct s_stacks
{
	int		*max_i;
	int		*top_a;
	int		*stack;
	int		*copy;
}			t_stacks;

void	exit_handler(char status, void *stc_mem);

void	reset(t_stacks *game);
void	load_stack(t_stacks *game, int argn, const char **argv);
size_t	stack_size(t_stacks *game, char which);
int		is_sorted(t_stacks game);
int		range_is_sorted(t_stacks *game, size_t base, size_t top);


/*
**	Instructions
*/
void	swap(t_stacks *game, char which);
void	push(t_stacks *game, char which);
void	rrot(t_stacks *game, char which);
void	rot(t_stacks *game, char which);

size_t	index_of(int value, t_stacks *game);
int		*get_position(int value, t_stacks *game);
int		*peek_base(t_stacks *game, char which);
int		*peek_top(t_stacks *game, char which);

void	do_instr(t_stacks *game, char instr_id);
void	do_sequence(t_stacks *game, const char seq[]);
void	log_and_do_instr(t_stacks *game, t_list **instr, char instr_id);
void	log_and_do_n(t_stacks *game, t_list **instr, char instr_id, size_t n);
void	log_and_do_sequence(t_stacks *game, t_list **instr, const char seq[]);
#endif
