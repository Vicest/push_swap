/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_and_do_sequence.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 22:03:40 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/16 22:40:22 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	log_and_do_sequence(t_stacks *game, t_list **instr, const char seq[])
{
	size_t	i;

	i = -1;
	while (seq[++i])
		log_and_do_instr(game, instr, seq[i]);
}
