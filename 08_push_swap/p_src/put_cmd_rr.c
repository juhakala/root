/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cmd_rra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:35:54 by jhakala           #+#    #+#             */
/*   Updated: 2020/01/23 14:03:35 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		cmd_rra(t_mem *mem)
{
	int tmp;
	int i;

	if (mem->a_size < 2)
		return (1);
	i = 1;
	tmp = mem->a[mem->a_size - 1];
	while (i < mem->a_size)
	{
		mem->a[mem->a_size - i] = mem->a[mem->a_size - i - 1];
		i++;
	}
	mem->a[0] = tmp;
	mem->now_cmd = 8;
	ft_cmd(mem);
	return (1);
}

int		cmd_rrb(t_mem *mem)
{
	int tmp;
	int i;

	if (mem->b_size < 2)
		return (1);
	i = 1;
	tmp = mem->b[mem->b_size - 1];
	while (i < mem->b_size)
	{
		mem->b[mem->b_size - i] = mem->b[mem->b_size - i - 1];
		i++;
	}
	mem->b[0] = tmp;
	mem->now_cmd = 9;
	ft_cmd(mem);
	return (1);
}

int		cmd_rrr(t_mem *mem)
{
	if (mem->a_size > 1 && mem->b_size > 1)
	{
		cmd_rra(mem);
		cmd_rrb(mem);
	}
	return (1);
}
