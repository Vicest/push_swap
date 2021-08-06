/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:44:12 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/06 16:27:53 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	arr_sort(int *arr, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size - 1)
	{
		j = i;
		while (j < size - 1)
		{
			if (arr[j] < arr[j + 1])
				ft_swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}
