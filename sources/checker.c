/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:21:05 by vicmarti          #+#    #+#             */
/*   Updated: 2021/03/23 15:22:28 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <errno.h>
#include "checker.h"

#include <stdio.h>
void	error()
{
	write(2, "Error\n", 6);
	exit(1);
}

void	check_args(int argc, char **args)
{
	long	num;
	char	*end;

	while(argc > 1)
	{
		end = args[argc];
		num = ft_strtol(args[argc], end);
		if (*end || (num == 0 && errno == EINVAL) ||
			num > INT_MAX || num < INT_MIN)
			error();
		else
			printf("Num is: %ld\n", num);
		argc--;
	}
}

int	main(int argc, char **args)
{
	check_args(argc, args);
	exit(0);
}



	/*
	int	*stacks;

	stacks = malloc
	check_args();
	while (argc *
	*/
