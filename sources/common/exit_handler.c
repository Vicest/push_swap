/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 21:31:58 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/24 21:32:28 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	exit_handler(char status, void *stc_mem)
{
	if (stc_mem)
		free(stc_mem);
	if (status == ERROR)
		write(2, "Error\n", 6);
	exit(status);
}
