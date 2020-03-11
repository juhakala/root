/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 22:00:48 by jhakala           #+#    #+#             */
/*   Updated: 2020/01/23 14:02:17 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	print_cmd(t_mem *mem)
{
	mem->last_cmd == 0 ? ft_putstr("sa\n") : 0;
	mem->last_cmd == 1 ? ft_putstr("sb\n") : 0;
	mem->last_cmd == 2 ? ft_putstr("ss\n") : 0;
	mem->last_cmd == 3 ? ft_putstr("pa\n") : 0;
	mem->last_cmd == 4 ? ft_putstr("pb\n") : 0;
	mem->last_cmd == 5 ? ft_putstr("ra\n") : 0;
	mem->last_cmd == 6 ? ft_putstr("rb\n") : 0;
	mem->last_cmd == 7 ? ft_putstr("rr\n") : 0;
	mem->last_cmd == 8 ? ft_putstr("rra\n") : 0;
	mem->last_cmd == 9 ? ft_putstr("rrb\n") : 0;
	mem->last_cmd == 10 ? ft_putstr("rrr\n") : 0;
}

void	ft_cmd(t_mem *mem)
{
	if ((mem->last_cmd == 0 && mem->now_cmd == 1) || (mem->last_cmd == 1
			&& mem->now_cmd == 0))
		mem->last_cmd = 2;
	else if ((mem->last_cmd == 5 && mem->now_cmd == 6) || (mem->last_cmd == 6
			&& mem->now_cmd == 5))
		mem->last_cmd = 7;
	else if ((mem->last_cmd == 8 && mem->now_cmd == 9) || (mem->last_cmd == 9
			&& mem->now_cmd == 8))
		mem->last_cmd = 10;
	print_cmd(mem);
	if (mem->last_cmd == 2 || mem->last_cmd == 7 || mem->last_cmd == 10)
		mem->last_cmd = -1;
	else
	{
		mem->last_cmd = mem->now_cmd;
		mem->steps += 1;
	}
}
