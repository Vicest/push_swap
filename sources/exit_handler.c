/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 21:31:58 by vicmarti          #+#    #+#             */
/*   Updated: 2021/04/09 16:08:12 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker.h"

void	exit_handler(char status, void *stc_mem)
{
	if (stc_mem)
		free(stc_mem);
	if (status == ERROR)
		write(2, "Error\n", 6);
	//system("leaks checker");
	exit(status);
}
