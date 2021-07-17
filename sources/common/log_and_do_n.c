/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_and_do_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 22:19:35 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/17 22:22:11 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	log_and_do_n(t_stacks *game, t_list **instr, char instr_id, size_t n)
{
	while (n--)
		log_and_do_instr(game, instr, instr_id);
}
