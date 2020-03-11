/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:19:18 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/02 21:40:51 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		ft_small_solve(t_mem *mem)
{
	int mid;

	if (mem->size > 3)
	{
		mid = mem->real[mem->size - 4];
		while (ft_contains_lower(mem, mid))
			cmd_pb(mem);
	}
	if (!ft_order(mem) && mem->size == 2)
		cmd_sa(mem);
	if (ft_order(mem))
		return (0);
	ft_three_solve(mem);
	cmd_pa(mem);
	while (mem->b_size > 0)
		ft_calc_best_nb(mem);
	ft_make_min_first(mem);
	return (0);
}
