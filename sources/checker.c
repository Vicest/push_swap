/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:21:05 by vicmarti          #+#    #+#             */
/*   Updated: 2021/03/22 15:12:16 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <limits.h>

void	error()
{
	write(2, "Error\n", 6);
	exit(1);
}

void	check_args(int argc, char **args)
{
	long	num;

	while(--argc >= 0)
	{
		num = atol(args[argc]);//TODO: STRTOL
		if (num > INT_MAX || num < INT_MIN)
			error();

	}
}

int	main(int argc, char **args)
{
	t_psh_swp	ps;

	ps.elems = argc;
	ps.top_a = argc;
	ps.a = calloc(argc * 2, sizeof(int *));
	if (!ps.a)
		error();
	while (argc-- > 0)
	{
		ps.a[ps.elems - argc] = atoi(args[argc]);
		if (ps.a[ps.elems] == 

	exit(0);
}



	/*
	int	*stacks;

	stacks = malloc
	check_args();
	while (argc *
	*/
