/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 20:08:17 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/27 20:15:47 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*get_position(int value, t_stacks *game)
{
	int	*i;

	i = game->top_a;
	while (i >= game->stacks)
	{
		if (*i == value)
			return (i);
		i++;
	}
	return (0);
}
