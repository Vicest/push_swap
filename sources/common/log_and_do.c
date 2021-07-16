/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_and_do_instr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:22:29 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/16 22:31:29 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	log_and_do_instr(t_stacks *game, t_list **instr, char instr_id)
{
	size_t	aux;

	aux = instr_id;
	do_instr(game, instr_id);
	ft_lstadd_front(instr, ft_lstnew(((void *)aux)));
}
