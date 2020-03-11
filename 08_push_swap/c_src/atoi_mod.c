/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 21:30:07 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/06 23:41:52 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long long int	ft_atoi_mod(const char *str)
{
	size_t	res;
	int		minus;

	minus = 1;
	res = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == '-')
		minus = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str > 47 && *str < 58)
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	if ((*str > 57 || *str < 48) && *str != '\0' && *str != ' ')
		ft_error("Error\n");
	if (res > 9223372036854775807)
		ft_error("Error\n");
	return (res * minus);
}

void			ft_end_order(t_mem *mem)
{
	if (ft_order(mem))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}
