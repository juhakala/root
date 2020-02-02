/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:30:55 by jhakala           #+#    #+#             */
/*   Updated: 2020/01/24 11:32:25 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	return (1);
}

int		cmd_rr(t_mem *mem)
{
	cmd_ra(mem);
	cmd_rb(mem);
	return (1);
}
