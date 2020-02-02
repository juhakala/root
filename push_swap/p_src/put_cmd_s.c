/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cmd_sa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 22:24:43 by jhakala           #+#    #+#             */
/*   Updated: 2020/01/21 18:54:47 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		cmd_sa(t_mem *mem)
{
	int tmp;

	if (mem->a_size < 2)
		return (1);
	tmp = mem->a[0];
	mem->a[0] = mem->a[1];
	mem->a[1] = tmp;
	mem->now_cmd = 0;
	ft_cmd(mem);
	return (1);
}

int		cmd_sb(t_mem *mem)
{
	int tmp;

	if (mem->b_size < 2)
		return (1);
	tmp = mem->b[0];
	mem->b[0] = mem->b[1];
	mem->b[1] = tmp;
	mem->now_cmd = 1;
	ft_cmd(mem);
	return (1);
}

int		cmd_ss(t_mem *mem)
{
	if (mem->a_size > 1 && mem->b_size > 1)
	{
		cmd_sa(mem);
		cmd_sb(mem);
	}
	return (1);
}
