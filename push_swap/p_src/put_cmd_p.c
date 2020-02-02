/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cmd_pa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:56:56 by jhakala           #+#    #+#             */
/*   Updated: 2020/01/30 16:02:33 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		cmd_pa(t_mem *mem)
{
	int i;

	i = 0;
	if (mem->b_size < 1)
		return (1);
	while (i < mem->a_size)
	{
		mem->a[mem->a_size - i] = mem->a[mem->a_size - i - 1];
		i++;
	}
	mem->a[0] = mem->b[0];
	mem->a_size += 1;
	i = 0;
	while (i < mem->b_size)
	{
		mem->b[i] = mem->b[i + 1];
		i++;
	}
	mem->b_size -= 1;
	mem->now_cmd = 3;
	ft_cmd(mem);
	return (1);
}

int		cmd_pb(t_mem *mem)
{
	int i;

	i = 0;
	while (i < mem->b_size)
	{
		mem->b[mem->b_size - i] = mem->b[mem->b_size - i - 1];
		i++;
	}
	mem->b[0] = mem->a[0];
	mem->b_size += 1;
	i = 0;
	while (i < mem->a_size)
	{
		mem->a[i] = mem->a[i + 1];
		i++;
	}
	if (mem->mid_from < mem->b[0] && mem->b_size > 0)
		mem->mid_from = mem->b[0];
	mem->a_size -= 1;
	mem->now_cmd = 4;
	ft_cmd(mem);
	return (1);
}
