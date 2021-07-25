/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:50:07 by vicmarti          #+#    #+#             */
/*   Updated: 2021/07/25 22:00:22 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	push_back_into_a()
{
	while (pushed_from_low > 0)
	{
		if (stack_base[0] > b_next)
			log_and_do(RRA);
			rotated--;
		else
		{
			log_and_do(RRB, PA);
			pushed_from_low--;
		}
	}
	while (size(stack_b) > 0)
	{
		same_as_before_noRRB();
	}
}

void	align_into_a()
{
	while(rotated > 0)
		log_and_do(RRA);
		rotated--;
}

void	quick()
{
	if (is_sorted(substack))
		;
	else if (size(game) < COMFORTABLE_SORT_SIZE)
		brute(substack); //Just a SA for a size 2 and the maybe optimize.
	else
	{
		pivot = game->substack[(size(substack) + 1) / 2];
		i = substack_top;
		pushed_from_low = 0;
		while (i > substack_base)
		{
			if (i > middle_point && substack[i] > pivot)
			{
				log_and_do(PB);
			}
			else if (i < middle_point && substack[i] < pivot)
			{
				log_and_do(PB);
				pushed_from_low++;
			}
			else
			{
				log_and_do(RA);
				rotated++;
			}
			i++;
		}
		push_back_into_a(rotated, pushed_low);
		upper_part = giv_part();
		lower_part = gib_part();
		quick(upper_part);
		align_stack_to_lower();
		quick(lower_part);
	}
}
