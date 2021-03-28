/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:08:35 by vicmarti          #+#    #+#             */
/*   Updated: 2021/03/28 21:59:07 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

	unsigned	ft_strlen(char *s)
	{
		unsigned	i;

		i = 0;
		while(s[i])
			i++;
		return (i);
	}

	void	ft_strcpy(char *dest, char *s)
	{
		unsigned	i;

		i = ft_strlen(s);
		dest[i] = 0;
		while (i-- > 0)
			dest[i] = s[i];
	}

	int	get_next_line(char **line)
	{
		unsigned	len;
		int			rout;
		char		buf;
		char		*aux;

		*line = malloc(1);
		(*line)[0] = 0;
		while((rout = read(0, &buf, 1)) > 0)
		{
			if (buf == '\n')
				return (1);
			len = ft_strlen(*line) + 1;
			aux = malloc(sizeof(char) * (len + 1));
			ft_strcpy(aux, *line);
			free(*line);
			aux[len - 1] = buf;
			aux[len] = 0;
		*line = aux;
	}
	return (rout);
}

int	main(void)
{
	char	*line;

	while (get_next_line(&line) == 1)
	{
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
		free(line);
	}
	system("leaks a.out");
	return (0);
}
