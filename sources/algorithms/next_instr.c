/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:21:28 by vicmarti          #+#    #+#             */
/*   Updated: 2021/05/15 19:40:17 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	next_instr(char instr, char prev_instr)
{
	if (instr < SA && prev_instr != SA)
		return (SA);
	else if (instr < RA && prev_instr != RRA)
		return (RA);
	else if (instr < RRA && prev_instr != RA)
		return (RRA);
	return (LAST_INSTR + 1);
}
