/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_pick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 14:23:28 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/02 21:40:07 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	ft_solve(t_mem *mem)
{
	if (ft_order(mem))
		return (0);
	if (mem->size < 6)
		ft_small_solve(mem);
	else if (mem->size > 5 && mem->size < 251)
		ft_medium_solve(mem);
	else
		ft_large_solve(mem);
	if (!ft_order(mem))
		ft_solve(mem);
	return (0);
}
