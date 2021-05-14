/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:49:43 by vicmarti          #+#    #+#             */
/*   Updated: 2021/05/14 18:57:34 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# include "../libft/libft.h"
# define SUCCS 0
# define ERROR 1

typedef struct s_stacks
{
	int		*max_i;
	int		*top_a;
	int		*stack;
}			t_stacks;

int		is_sorted(t_stacks game);
int		get_next_line(char **);
void	exit_handler(char status, void *stc_mem);
void	load_stack(t_stacks *game, const char *nums);
void	swap(t_stacks *game, char *spec);
void	rot(t_stacks *game, char *spec);
#endif
