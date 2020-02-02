/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:01:53 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/02 21:41:23 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		ft_get_min_a(t_mem *mem)
{
	int i;
	int min;

	i = 0;
	min = mem->a[0];
	while (i < mem->a_size)
	{
		if (min > mem->a[i])
			min = mem->a[i];
		i++;
	}
	return (min);
}

int		ft_contains_lower(t_mem *mem, int mid)
{
	int i;

	i = 0;
	while (i < mem->a_size)
	{
		if (mem->a[i] <= mid)
		{
			while (i > 0)
			{
				if (i-- > 0)
					cmd_ra(mem);
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_contains_higher(t_mem *mem, int mid)
{
	int i;

	i = 0;
	while (i < mem->a_size)
	{
		if (mem->a[i] > mid && mem->a[i] != mem->real[mem->size - 1])
		{
			while (i > 0)
			{
				if (i-- > 0)
					cmd_ra(mem);
			}
			return (1);
		}
		i++;
	}
	return (0);
}
