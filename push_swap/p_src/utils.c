/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 22:13:53 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/02 21:07:55 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ft_error(char *str)
{
	ft_putstr(str);
	exit(0);
}

int		ft_order(t_mem *mem)
{
	int i;

	i = 0;
	while (mem->a[i] == mem->real[i] && mem->b_size == 0 && i < mem->size)
		i++;
	if (!mem->b_size && i == mem->size)
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
