/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:09:07 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/17 20:40:33 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	cnt_words(const char *nums)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (nums[i] == ' ')
		i++;
	while (nums[i])
	{
		words++;
		while (nums[i] && nums[i] != ' ')
			i++;
		while (nums[i] == ' ')
			i++;
	}
	return (words);
}

static char	*join_args(int argn, const char **argv)
{
	char	*joined;
	char	*prev_str;
	int		i;

	joined = ft_strdup(argv[0]);
	if (!joined)
		exit_handler(ERROR);
	i = 1;
	while (i < argn)
	{
		prev_str = joined;
		joined = ft_strjoin(joined, " ");
		if (!joined)
			exit_handler(ERROR);
		free(prev_str);
		prev_str = joined;
		joined = ft_strjoin(joined, argv[i]);
		if (!joined)
			exit_handler(ERROR);
		free(prev_str);
		i++;
	}
	return (joined);
}

void	set_up(t_ps *ps, int argc, const char **args)
{
	char	*concatenated_args;
	size_t	number_cnt;

	concatenated_args = join_args(argc - 1, &(args[1]));
	number_cnt = cnt_words(concatenated_args);
	init_mem(ps, number_cnt);
	load_stack(ps, concatenated_args, number_cnt);
	free(concatenated_args);
	preprocess(ps->stack_a);
	copy(ps->a_backup, ps->stack_a);
}
