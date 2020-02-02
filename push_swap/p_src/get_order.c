/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:53:43 by jhakala           #+#    #+#             */
/*   Updated: 2020/01/30 15:58:07 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		get_last(t_mem *mem)
{
	int last;
	int i;

	i = 0;
	last = mem->a[0];
	while (i < mem->size)
	{
		if (mem->a[i] > last)
			last = mem->a[i];
		i++;
	}
	return (last);
}

int		get_first(t_mem *mem)
{
	int now;
	int i;

	i = 0;
	now = mem->a[0];
	while (i < mem->size)
	{
		if (mem->a[i] < now)
			now = mem->a[i];
		i++;
	}
	return (now);
}

void	ft_get_order(t_mem *mem)
{
	int now;
	int i;
	int count;

	count = 1;
	i = 0;
	mem->real[0] = get_first(mem);
	mem->real[mem->size - 1] = get_last(mem);
	while (count < mem->size - 1)
	{
		now = mem->real[mem->size - 1];
		i = 0;
		while (i < mem->size)
		{
			if (mem->a[i] < now && mem->a[i] > mem->real[count - 1])
				now = mem->a[i];
			i++;
		}
		mem->real[count] = now;
		count++;
	}
	mem->mid_from = mem->real[0];
}
