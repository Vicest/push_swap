/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:17:46 by vicmarti          #+#    #+#             */
/*   Updated: 2021/03/29 13:56:53 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rrotate(int *start, int *end)
{
	int	aux;
	int	i;

	aux = *end;
	i = end - start;
	while (i > 0)
	{
		start[i] = start[i - 1];
		i++;
	}
	start[0] = aux;
}
/*
static void	rrotate(int *start, int *end)
{
	int	aux;
	int	i;

	aux = *start
*/

