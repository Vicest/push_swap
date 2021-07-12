/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_do.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:22:29 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/05 17:30:44 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdio.h>

void	log_do(t_stacks *game, t_list **instr, char instr_id)
{
	size_t	aux;

	printf("%d\n", instr_id);
	aux = instr_id;
	do_instr(game, instr_id);
	ft_lstadd_front(instr, ft_lstnew(((void *)aux)));
}
