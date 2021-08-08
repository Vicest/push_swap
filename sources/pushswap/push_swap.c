/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:39:30 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/08 21:00:43 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>//TODO redundant?
#include <stdio.h> //REMOVE
#include "push_swap.h"

static void	print_instr(char *str)
{
	while (*(str++))
	{
		if (*(str - 1) == SA)
			ft_putstr_fd("sa\n", 1);
		else if (*(str - 1) == RA)
			ft_putstr_fd("ra\n", 1);
		else if (*(str - 1) == RRA)
			ft_putstr_fd("rra\n", 1);
		else if (*(str - 1) == SB)
			ft_putstr_fd("sb\n", 1);
		else if (*(str - 1) == RB)
			ft_putstr_fd("rb\n", 1);
		else if (*(str - 1) == RRB)
			ft_putstr_fd("rrb\n", 1);
		else if (*(str - 1) == SS)
			ft_putstr_fd("ss\n", 1);
		else if (*(str - 1) == RR)
			ft_putstr_fd("rr\n", 1);
		else if (*(str - 1) == RRR)
			ft_putstr_fd("rrr\n", 1);
		else if (*(str - 1) == PA)
			ft_putstr_fd("pa\n", 1);
		else if (*(str - 1) == PB)
			ft_putstr_fd("pb\n", 1);
	}
}

static size_t	cnt_words(const char *nums)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (nums[0] && nums[0] != ' ')
		len = 1;
	while (nums[i] && nums[i + 1])
	{
		if (nums[i] == ' ' && nums [i + 1] != ' ')
			len++;
		i++;
	}
	return (len);
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

static void	set_up(t_ps *ps, int argc, const char **args)
{
	char	*concatenated_args;
	size_t	number_cnt;

	concatenated_args = join_args(argc - 1, &(args[1]));
	number_cnt = cnt_words(concatenated_args);
	init_mem(ps, number_cnt);
	load_stack(ps, concatenated_args, number_cnt);
	free(concatenated_args);
	print_status(ps);
	preprocess(ps->stack_a);
	print_status(ps);
}

int	main(int argc, const char **args)
{
	t_ps		ps;
	t_list		*instr;
	char		*tmp;

	instr = NULL;
	if (argc == 1)
		exit_handler(SUCCS);
	set_up(&ps, argc, args);
	if (is_sorted(ps.stack_a))
		exit_handler(SUCCS);
	block_sort(&ps, &instr, 5);
	print_status(&ps);


	//quick(&ps, &instr, *(ps.stack), *(ps.top_a));
	tmp = copy_instructions(instr);
	optimizations(tmp);
	print_instr(tmp);
	//run_algorithms(&ps);
	system("leaks -q push_swap");
	exit_handler(SUCCS);
}
