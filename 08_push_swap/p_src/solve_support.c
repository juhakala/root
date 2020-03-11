/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_support.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:55:34 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/02 15:17:42 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int			ft_three_solve(t_mem *mem)
{
	int a;
	int b;
	int c;

	a = mem->a[0];
	b = mem->a[1];
	c = mem->a[2];
	if (b > a && b > c)
		cmd_rra(mem);
	else if (a > b && a < c)
		cmd_sa(mem);
	else if (a > b && a > c)
		cmd_ra(mem);
	else if (a < b && b < c)
		return (1);
	ft_three_solve(mem);
	return (0);
}

void		ft_make_min_first(t_mem *mem)
{
	int a_min;
	int i;

	i = 0;
	a_min = ft_get_min_a(mem);
	while (i < mem->a_size && mem->a[i] != a_min)
		i++;
	if (mem->a_size - i < i)
		rotate(8, mem->a_size - i, mem);
	else
		rotate(5, i, mem);
}

static int	index_a(t_mem *mem, int nb)
{
	int i;

	i = 0;
	while (i < mem->a_size)
	{
		if (nb == mem->a[i])
			return (i);
		i++;
	}
	ft_error("index_aError\n");
	return (0);
}

int			ft_index_in_a(t_mem *mem, int nb)
{
	int a_min;
	int i;

	a_min = ft_get_min_a(mem);
	if (nb < a_min)
		return (index_a(mem, a_min));
	else
	{
		i = 0;
		while (i < mem->a_size - 1)
		{
			if (mem->a[i] < nb && nb < mem->a[i + 1])
				return (i + 1);
			i++;
		}
	}
	return (0);
}
