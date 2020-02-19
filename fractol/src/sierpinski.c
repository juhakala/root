/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:45:08 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/10 22:29:47 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	make_box(t_ev *ev, int f_x, int f_y, int to)
{
	int x;
	int y;
	int color;

	if (to == 729)
		color = 0xFFFFFF;
	else
		color = 0x000000;
	y = 0 + f_y;
	while (y < to + f_y)
	{
		x = 0 + f_x;
		while (x < to + f_x)
		{
			ft_put_pixel(ev, x + (WIN_W / 4) + ev->x_offset, y +
						(WIN_H / 4) + ev->y_offset, color);
			x++;
		}
		y++;
	}
}

static void	back(t_ev *ev)
{
	int x;
	int y;

	x = 20;
	y = 20;
	ev->iter = 0;
	if (ev->iter_max > 6)
		ev->iter_max = 6;
	while (y < WIN_H - 20)
	{
		x = 0;
		while (x < WIN_W - 20)
		{
			ft_put_pixel(ev, x, y, 0x000000);
			x++;
		}
		y++;
	}
	make_box(ev, 0, 0, 729);
}

void		sierpinski_calc(t_ev *ev)
{
	int x;
	int times;
	int k;
	int w;

	back(ev);
	while (ev->iter < ev->iter_max)
	{
		times = ev->iter_max - ev->iter;
		x = 1;
		while (times-- > 0)
			x *= 3;
		w = 0;
		while (w < 729)
		{
			k = 0;
			while (k < 729)
			{
				make_box(ev, k + 729 / x, w + 729 / x, 729 / x);
				k += 3 * (729 / x);
			}
			w += 3 * (729 / x);
		}
		ev->iter++;
	}
}
