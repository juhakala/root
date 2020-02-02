/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 23:20:16 by jhakala           #+#    #+#             */
/*   Updated: 2020/01/24 11:34:16 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		cmd_sa(t_mem *mem)
{
	int tmp;

	if (mem->a_size < 2)
		return (1);
	tmp = mem->a[0];
	mem->a[0] = mem->a[1];
	mem->a[1] = tmp;
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
	return (1);
}

int		cmd_ss(t_mem *mem)
{
	cmd_sa(mem);
	cmd_sb(mem);
	return (1);
}
