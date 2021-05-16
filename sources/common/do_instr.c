/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 19:23:49 by vicmarti          #+#    #+#             */
/*   Updated: 2021/05/16 22:15:39 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	do_instr(t_stacks *game, char instr_id)
{
	if (instr_id == SA)
		 return (swap(game, SA));
	else if (instr_id == RA)
		 return (rotate(game, RA));
	else if (instr_id == RRA)
		 return (rrotate(game, RRA));
	return (-1);
}
