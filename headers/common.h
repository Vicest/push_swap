/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 20:38:00 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/15 16:32:16 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define SUCCS 0
# define ERROR 1

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

typedef struct s_stack
{
	int		*val;
	size_t	size;
	size_t	max_size;
}			t_stack;

typedef struct s_ps
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}		t_ps;

void	exit_handler(char status);
void	arr_sort(int *arr, size_t size);

//void	reset(t_stacks *game);
void	init_mem(t_ps *ps, size_t size);
void	init_stack(t_stack **stack, size_t size);
void	copy(t_stack **dst, t_stack *src);
void	clean_stack(t_stack *stack);
void	load_stack(t_ps *ps, char *numbers_str, size_t numbers_cnt);
void	print_status(t_ps *ps);
void	preprocess(t_stack *stack);
int		is_sorted(t_stack *stack);
int		has_value(int n, t_stack *stack);
int		max_val(t_stack *stack);
size_t	index_of(int value, t_stack *stack);

void	swap(t_stack *stack);
void	push(t_stack *dst, t_stack *src);
void	rot(t_stack *stack);
void	rrot(t_stack *stack);

void	do_instr(t_ps *ps, char instr_id);
void	do_sequence(t_ps *ps, const char seq[]);
void	log_and_do_instr(t_ps *ps, t_list **instr, char instr_id);
void	log_and_do_n(t_ps *ps, t_list **instr, char instr_id, size_t n);
void	log_and_do_sequence(t_ps *ps, t_list **instr, const char seq[]);
#endif
