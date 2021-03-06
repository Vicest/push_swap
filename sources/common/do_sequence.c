/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sequence.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 21:06:06 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/07 18:41:17 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
void	do_sequence(t_ps *ps, const char seq[])
{
	size_t	i;

	i = -1;
	while (seq[++i])
		do_instr(ps, seq[i]);
}
