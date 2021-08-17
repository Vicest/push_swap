/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 17:38:37 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/17 20:37:38 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	init_mem(t_ps *ps, size_t size)
{
	init_stack(&(ps->stack_a), size);
	init_stack(&(ps->stack_b), size);
	init_stack(&(ps->a_backup), size);
}
