/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:54:51 by jhakala           #+#    #+#             */
/*   Updated: 2020/01/28 16:03:01 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		cmd_pb(t_mem *mem)
{
	int i;

	i = 0;
	if (mem->a_size < 1)
		return (1);
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
	mem->a_size -= 1;
	return (1);
}

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
	return (1);
}
