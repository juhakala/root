/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 19:05:46 by jhakala           #+#    #+#             */
/*   Updated: 2020/01/24 11:33:31 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	return (1);
}

int		cmd_rrr(t_mem *mem)
{
	cmd_rra(mem);
	cmd_rrb(mem);
	return (1);
}
