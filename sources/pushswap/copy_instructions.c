/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:00:26 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/20 19:51:59 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*copy_instructions(t_list *last_instr)
{
	char	*instr_set;
	size_t	instr_num;

	instr_num = ft_lstsize(last_instr);
	instr_set = malloc(sizeof(char) * (instr_num + 1));
	if (!instr_set)
		return (NULL);
	instr_set[instr_num] = 0;
	while (instr_num-- > 0)
	{
		instr_set[instr_num] = (char)(last_instr->content);
		last_instr = last_instr->next;
	}
	return (instr_set);
}
