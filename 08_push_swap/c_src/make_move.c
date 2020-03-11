/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 22:41:20 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/02 21:03:18 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	make(int i, t_mem *mem)
{
	i == 0 ? cmd_sa(mem) : 0;
	i == 1 ? cmd_sb(mem) : 0;
	i == 2 ? cmd_ss(mem) : 0;
	i == 3 ? cmd_pa(mem) : 0;
	i == 4 ? cmd_pb(mem) : 0;
	i == 5 ? cmd_ra(mem) : 0;
	i == 6 ? cmd_rb(mem) : 0;
	i == 7 ? cmd_rr(mem) : 0;
	i == 8 ? cmd_rra(mem) : 0;
	i == 9 ? cmd_rrb(mem) : 0;
	i == 10 ? cmd_rrr(mem) : 0;
	return (1);
}

int			ft_make_move(char *str, t_mem *mem)
{
	int i;

	i = -1;
	ft_strcmp(str, "sa") == 0 ? i = 0 : 0;
	ft_strcmp(str, "sb") == 0 ? i = 1 : 0;
	ft_strcmp(str, "ss") == 0 ? i = 2 : 0;
	ft_strcmp(str, "pa") == 0 ? i = 3 : 0;
	ft_strcmp(str, "pb") == 0 ? i = 4 : 0;
	ft_strcmp(str, "ra") == 0 ? i = 5 : 0;
	ft_strcmp(str, "rb") == 0 ? i = 6 : 0;
	ft_strcmp(str, "rr") == 0 ? i = 7 : 0;
	ft_strcmp(str, "rra") == 0 ? i = 8 : 0;
	ft_strcmp(str, "rrb") == 0 ? i = 9 : 0;
	ft_strcmp(str, "rrr") == 0 ? i = 10 : 0;
	if (i == -1)
		ft_error("Error\n");
	else
		make(i, mem);
	return (0);
}
