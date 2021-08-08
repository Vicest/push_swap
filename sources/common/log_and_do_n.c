/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_and_do_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 22:19:35 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/08 15:06:22 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	log_and_do_n(t_ps *ps, t_list **instr, char instr_id, size_t n)
{
	while (n--)
		log_and_do_instr(ps, instr, instr_id);
}
