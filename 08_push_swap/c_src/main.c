/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 20:42:44 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/02 22:32:46 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		check_double(int n, int *stack, int j)
{
	int i;

	i = 0;
	while (i < j)
	{
		if (stack[i] == n)
			return (0);
		i++;
	}
	return (1);
}

void	get_stack_arg(char **av, t_mem *mem)
{
	int				i;
	long long int	n;

	i = 0;
	while (i < mem->a_size)
	{
		n = ft_atoi_mod(av[i]);
		if (n > 2147483647 || n < -2147483648)
			ft_error("Error\n");
		if (!check_double((int)n, mem->a, i))
			ft_error("Error\n");
		mem->a[i] = n;
		i++;
	}
}

void	get_stack(char **av, t_mem *mem, int flag)
{
	int				i;
	long long int	n;

	i = (flag ? 1 : 0);
	while (i < mem->a_size)
	{
		n = ft_atoi_mod(av[i + 1]);
		if (n > 2147483647 || n < -2147483648)
			ft_error("Error\n");
		if (!check_double((int)n, mem->a, i))
			ft_error("Error\n");
		mem->a[i] = n;
		i++;
	}
	if (flag)
	{
		mem->size--;
		mem->a_size--;
	}
}

int		get_flag(char **av)
{
	if (av[1][0] == '-')
	{
		if (av[1][1] == 'v')
		{
			if (av[1][2] == '\0')
				return (1);
		}
		else if (av[1][1] == 'h')
		{
			if (av[1][2] == '\0')
			{
				ft_putendl("-v : visualize the sorting");
				ft_error("-u : usage\n");
			}
		}
		else if (av[1][1] == 'u')
		{
			if (av[1][2] == '\0')
				ft_error("usage: [-v] [n times integer numbers ...]");
		}
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_mem	*mem;
	char	*line;
	char	**str;
	int		flag;

	if (ac < 2)
		return (0);
	mem = NULL;
	str = NULL;
	flag = get_flag(av);
	if (ac == 2 || (flag && av[2] != NULL && av[3] == NULL))
		str = ft_strsplit(av[ac == 2 ? 1 : 2], ' ');
	mem = ft_stack_init(mem, str ? ft_str_size(str) : ac);
	(str == NULL && av[1] == NULL) ? ft_error("") : 0;
	str ? get_stack_arg(str, mem) : get_stack(av, mem, flag);
	if (flag)
		ft_mlx(mem);
	while (get_next_line(0, &line) > 0)
	{
		ft_make_move(line, mem);
		free(line);
	}
	ft_end_order(mem);
	return (0);
}
