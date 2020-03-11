/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_large.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:55:34 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/02 21:35:11 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int			ft_large_solve(t_mem *mem)
{
	int mid;

	mid = mem->real[mem->size / 2];
	while (ft_contains_lower(mem, mid))
		cmd_pb(mem);
	cmd_pa(mem);
	while (mem->b_size > 0)
		ft_calc_best_nb(mem);
	while (ft_contains_higher(mem, mid))
		cmd_pb(mem);
	while (mem->b_size > 0)
		ft_calc_best_nb(mem);
	ft_make_min_first(mem);
	return (0);
}
