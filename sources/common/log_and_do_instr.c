/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_and_do_instr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:22:29 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/08 15:04:22 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	log_and_do_instr(t_ps *ps, t_list **instr, char instr_id)
{
	size_t	aux;

	aux = instr_id;
	do_instr(ps, instr_id);
	ft_lstadd_front(instr, ft_lstnew(((void *)aux)));
}
