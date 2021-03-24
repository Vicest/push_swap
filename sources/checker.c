/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:21:05 by vicmarti          #+#    #+#             */
/*   Updated: 2021/03/24 14:48:29 by vicmarti         ###   ########.fr       */
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

	while(--argc >= 0)
	{
		end = args[argc];
		num = ft_strtol(args[argc], end);
		if (*end || (num == 0 && errno == EINVAL) ||
			num > INT_MAX || num < INT_MIN)
			error();
		else
			printf("Num is: %ld\n", num);
	}
}

int	main(int argc, char **args)
{
	check_args(argc - 1, args + 1);
	exit(0);
}



	/*
	int	*stacks;

	stacks = malloc
	check_args();
	while (argc *
	*/
