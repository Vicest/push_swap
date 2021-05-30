/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:08:35 by vicmarti          #+#    #+#             */
/*   Updated: 2021/05/05 12:53:04 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

int	get_next_line(char **line)
{
	char			*aux;
	unsigned int	len;
	int				rout;
	char			buf;

	*line = malloc(1);
	(*line)[0] = 0;
	rout = read(0, &buf, 1);
	while (rout > 0)
	{
		if (buf == '\n')
			return (1);
		else if (buf == '\0')
			return (0);
		len = ft_strlen(*line) + 1;
		aux = malloc(sizeof(char) * (len + 1));
		ft_strcpy(aux, *line);
		free(*line);
		aux[len - 1] = buf;
		aux[len] = 0;
		*line = aux;
		rout = read(0, &buf, 1);
	}
	return (rout);
}
