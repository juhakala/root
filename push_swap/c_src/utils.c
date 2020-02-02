/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 22:13:53 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/02 17:31:58 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_error(char *str)
{
	ft_putstr(str);
	exit(0);
}

int		ft_order(t_mem *mem)
{
	int i;

	i = 0;
	while (mem->a[i] < mem->a[i + 1] && mem->b_size == 0 && i - 1 < mem->a_size)
		i++;
	if (!mem->b_size && i + 1 == mem->a_size)
		return (1);
	return (0);
}

int		ft_str_size(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i + 1);
}

int		ft_get_high(t_mem *mem)
{
	int i;
	int high;

	i = 0;
	high = mem->a[0];
	while (i < mem->size)
	{
		if (high < mem->a[i])
			high = mem->a[i];
		i++;
	}
	return (high);
}

t_mem	*ft_stack_init(t_mem *mem, int ac)
{
	int i;

	i = 0;
	if (!(mem = (t_mem*)ft_memalloc(sizeof(t_mem))))
		ft_error("Cmalloc1_Error\n");
	if (!(mem->a = (int *)malloc(sizeof(int) * (ac - 1))))
		ft_error("Cmalloc2_Error\n");
	if (!(mem->b = (int *)malloc(sizeof(int) * (ac - 1))))
		ft_error("Cmalloc2_Error\n");
	while (i < ac)
		mem->a[i++] = 0;
	i = 0;
	while (i < ac)
		mem->b[i++] = 0;
	mem->a_size = ac - 1;
	mem->b_size = 0;
	mem->size = ac - 1;
	return (mem);
}
