/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:17:20 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/06 23:35:04 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static int	check_double(int n, int *stack, int j)
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

void		ft_get_stack_arg(char **av, t_mem *mem)
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

void		ft_get_stack(char **av, t_mem *mem)
{
	int				i;
	long long int	n;

	i = 0;
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
}

static void	put_to_struct(t_mem *mem, int ac)
{
	mem->a_size = ac - 1;
	mem->b_size = 0;
	mem->size = ac - 1;
	mem->steps = -1;
	mem->last_cmd = -1;
	mem->now_cmd = -1;
}

t_mem		*ft_stack_init(t_mem *mem, int ac)
{
	int i;

	i = 0;
	if (!(mem = (t_mem*)ft_memalloc(sizeof(t_mem))))
		ft_error("Pmalloc1_Error\n");
	if (!(mem->a = (int*)malloc(sizeof(int) * (ac - 1))))
		ft_error("Pmalloc2_Error\n");
	if (!(mem->b = (int*)malloc(sizeof(int) * (ac - 1))))
		ft_error("Pmalloc2_Error\n");
	if (!(mem->real = (int*)malloc(sizeof(int) * (ac - 1))))
		ft_error("Pmalloc3_Error\n");
	while (i < ac)
		mem->a[i++] = 0;
	i = 0;
	while (i < ac)
		mem->b[i++] = 0;
	put_to_struct(mem, ac);
	return (mem);
}
