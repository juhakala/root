/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cmd_ra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 22:21:30 by jhakala           #+#    #+#             */
/*   Updated: 2020/01/21 18:58:56 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		cmd_ra(t_mem *mem)
{
	int tmp;
	int i;

	if (mem->a_size < 2)
		return (1);
	i = 0;
	tmp = mem->a[0];
	while (i < mem->a_size - 1)
	{
		mem->a[i] = mem->a[i + 1];
		i++;
	}
	mem->a[i] = tmp;
	mem->now_cmd = 5;
	ft_cmd(mem);
	return (1);
}

int		cmd_rb(t_mem *mem)
{
	int tmp;
	int i;

	if (mem->b_size < 2)
		return (1);
	i = 0;
	tmp = mem->b[0];
	while (i < mem->b_size - 1)
	{
		mem->b[i] = mem->b[i + 1];
		i++;
	}
	mem->b[i] = tmp;
	mem->now_cmd = 6;
	ft_cmd(mem);
	return (1);
}

int		cmd_rr(t_mem *mem)
{
	if (mem->a_size > 1 && mem->b_size > 1)
	{
		cmd_ra(mem);
		cmd_rb(mem);
	}
	return (1);
}
