/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:32:53 by vicmarti          #+#    #+#             */
/*   Updated: 2021/03/28 17:02:54 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h" //TODO Cp to includes

# define SUCCS 0
# define ERROR 1

typedef struct s_psh_swp
{
	size_t	top_a;
	int		*stack;
}			t_psh_swp;
#endif
