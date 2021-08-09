/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:44:12 by vicmarti          #+#    #+#             */
/*   Updated: 2021/08/09 16:48:21 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdbool.h>

void	arr_sort(int *arr, size_t size)
{
	size_t	i;
	bool	swapped;

	i = 1;
	swapped = true;
	while (swapped)
	{
		i = 1;
		swapped = false;
		while (i < size)
		{
			if (arr[i - 1] > arr[i])
			{
				ft_swap(&arr[i - 1], &arr[i]);
				swapped = true;
			}
			i++;
		}
	}
}
