/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 19:23:33 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/02 17:49:07 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "common.h" //TODO either pushswap or common
#include <string.h>//TODO forbidden functs

static void	pa_pb_redundancies(char *instr)
{
	size_t	i;

	i = 0;
	while (instr[i] && instr[i + 1])
	{
		if ((instr[i] == PA && instr[i + 1]  == PB)
			|| (instr[i] == PB && instr[i + 1] == PA))
		{
			memcpy(instr + i, instr + i + 2, strlen(instr + i + 2) + 1);
			if (i > 0)
				i--;
		}
		else
			i++;
	}
}

static void	rot_reverserot_redundancies(char *instr)
{
	size_t	i;

	i = 0;
	while (instr[i] && instr[i + 1])
	{
		if ((instr[i] == RA && instr[i + 1]  == RRA)
			|| (instr[i] == RRA && instr[i + 1] == RA)
			|| (instr[i] == RB && instr[i + 1] == RRB)
			|| (instr[i] == RRB && instr[i + 1] == RB)
			|| (instr[i] == RR && instr[i + 1] == RRR)
			|| (instr[i] == RRR && instr[i + 1] == RR))
		{
			memcpy(instr + i, instr + i + 2, strlen(instr + i + 2) + 1);
			if (i > 0)
				i--;
		}
		else
			i++;
	}
}

void	optimizations(char *instr)
{//TODO Geezums
	rot_reverserot_redundancies(instr);
	pa_pb_redundancies(instr);
	rot_reverserot_redundancies(instr);
	pa_pb_redundancies(instr);
	rot_reverserot_redundancies(instr);
	pa_pb_redundancies(instr);
	rot_reverserot_redundancies(instr);
	pa_pb_redundancies(instr);
	rot_reverserot_redundancies(instr);
	pa_pb_redundancies(instr);
	rot_reverserot_redundancies(instr);
	pa_pb_redundancies(instr);
	rot_reverserot_redundancies(instr);
	pa_pb_redundancies(instr);
}
