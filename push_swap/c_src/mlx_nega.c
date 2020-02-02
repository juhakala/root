/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_nega.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 23:08:59 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/02 23:45:37 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_b_nega(int x, int y, t_event *ev, int ac)
{
	int i;
	int count;

	i = 0;
	if (ev->mem->b[ev->mem->b_size - ac] == 0)
	{
		count = (ev->mem->size < 301 ? 2 : 1);
		while (count-- > 0)
		{
			ft_put_pixel(ev, x - 1, y, 0x00FF00);
			ev->mem->size < 301 ? ft_put_pixel(ev, x - 1, y - 1, 0x00FF00) : 0;
			x--;
		}
	}
	while (ev->mem->b[ev->mem->b_size - ac] + i < 0)
	{
		count = (ev->mem->size < 301 ? 2 : 1);
		while (count-- > 0)
		{
			ft_put_pixel(ev, x, y, 0x0000FF);
			ev->mem->size < 301 ? ft_put_pixel(ev, x, y - 1, 0x0000FF) : 0;
			x++;
		}
		i++;
	}
}

void	ft_a_nega(int x, int y, t_event *ev, int ac)
{
	int i;
	int count;

	i = 0;
	if (ev->mem->a[ev->mem->a_size - ac] == 0)
	{
		count = (ev->mem->size < 301 ? 2 : 1);
		while (count-- > 0)
		{
			ft_put_pixel(ev, x - 1, y, 0x00FF00);
			ev->mem->size < 301 ? ft_put_pixel(ev, x - 1, y - 1, 0x00FF00) : 0;
			x--;
		}
	}
	while (ev->mem->a[ev->mem->a_size - ac] + i < 0)
	{
		count = (ev->mem->size < 301 ? 2 : 1);
		while (count-- > 0)
		{
			ft_put_pixel(ev, x, y, 0x0000FF);
			ev->mem->size < 301 ? ft_put_pixel(ev, x, y - 1, 0x0000FF) : 0;
			x++;
		}
		i++;
	}
}
