/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:49:43 by vicmarti          #+#    #+#             */
/*   Updated: 2021/05/05 10:38:55 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# include "../libft/libft.h"
# define SUCCS 0
# define ERROR 1

typedef struct s_psh_swp
{
	int		*max_i;
	int		*top_a;
	int		*stack;
}			t_psh_swp;

int		get_next_line(char **);
void	exit_handler(char status, void *stc_mem);
void	load_stack(t_psh_swp *game, const char *nums);
#endif
