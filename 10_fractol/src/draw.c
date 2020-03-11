/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 22:10:01 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/10 22:28:58 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_put_pixel(t_ev *ev, int x, int y, int color)
{
	int i;

	if (ev->type != 4)
	{
		y += WIN_H / 2 + ev->y_offset;
		x += WIN_W / 2 + ev->x_offset;
	}
	if (y >= 0 && x >= 0 && WIN_H > y && WIN_W > x)
	{
		i = (x * ev->bits_per_pixel / 8) + (y * ev->size_line);
		ev->data_addr[i] = color;
		ev->data_addr[++i] = color >> 8;
		ev->data_addr[++i] = color >> 16;
	}
}
