/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:18:21 by vicmarti          #+#    #+#             */
/*   Updated: 2021/04/09 19:20:51 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_opts(int argc, const char **args, char *sts)
{
	int			argpos;
	int			char_read;

	argpos = 0;
	while (argc - 1 > ++argpos && args[argpos][0] == '-')
	{
		if (!ft_strcmp(args[argpos], "-"))
			return (argpos);
		char_read = 0;
		while (args[argpos][++char_read])
		{
			if (args[argpos][char_read] == 'v')
				*sts |= VERBOSE;
			else
				exit_handler(ERROR, NULL);
		}
	}
	return (argpos);
}
