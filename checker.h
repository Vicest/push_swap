/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:32:53 by vicmarti          #+#    #+#             */
/*   Updated: 2021/03/30 15:19:48 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h" //TODO Cp to includes

# define SUCCS 0
# define ERROR 1

typedef struct s_psh_swp
{
	int		*max_i;
	int		*top_a;
	int		*stack;
}			t_psh_swp;

int		get_next_line(char **);
void	rot(t_psh_swp game, char *spec);
void	swap(t_psh_swp game, char *spec);
void	push(t_psh_swp *game, char *spec);
void	exit_handler(char status, void *stc_mem);
void	print_sts(t_psh_swp game);
int		is_ordered(t_psh_swp game);
#endif
