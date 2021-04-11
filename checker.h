/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:32:53 by vicmarti          #+#    #+#             */
/*   Updated: 2021/04/11 17:46:54 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# include <unistd.h>
# include "common.h"

# define VERBOSE 1

void	rot(t_psh_swp game, char *spec);
void	swap(t_psh_swp game, char *spec);
void	push(t_psh_swp *game, char *spec);
void	print_sts(t_psh_swp game);
int		check_ordered(t_psh_swp game);
int		check_opts(int argc, const char **args, char *sts);
#endif
