/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 19:54:44 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/03 16:34:38 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		main(int ac, char **av)
{
	t_mem	*mem;
	char	**str;
	int		i;

	i = 0;
	if (ac < 2)
		return (0);
	mem = NULL;
	str = NULL;
	if (ac == 2)
		str = ft_strsplit(av[1], ' ');
	mem = ft_stack_init(mem, str ? ft_str_size(str) : ac);
	if (ac == 2 && str[1] == NULL && ft_atoi_mod(av[1]))
		exit(0);
	str ? ft_get_stack_arg(str, mem) : ft_get_stack(av, mem);
	ft_get_order(mem);
	ft_solve(mem);
	mem->now_cmd = -1;
	ft_cmd(mem);
	mem->steps == -1 ? mem->steps = 0 : 0;
	return (0);
}
