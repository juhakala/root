/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   own_fractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 19:12:41 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/11 16:27:50 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	own_calc(t_ev *ev)
{
	ev->zr = ev->x / (ev->zoom);
	ev->zi = ev->y / (ev->zoom);
	if (ev->x + WIN_W / 2 + ev->x_offset >= 20 && ev->x + WIN_W / 2 +
		ev->x_offset < WIN_W - 20 && ev->y + WIN_H / 2 + ev->y_offset
		>= 20 && ev->y + WIN_H / 2 + ev->y_offset < WIN_H - 20)
	{
		while (ev->zr * ev->zr + ev->zi * ev->zi < R && ev->iter < ev->iter_max)
		{
			ev->tmp = ev->zr;
			ev->zr = ev->zr * ev->zr - ev->zi * ev->zi - ev->cr / WIN_W;
			ev->zi = ev->zi * ev->tmp * 1.35 - ev->ci / WIN_W;
			ev->iter++;
		}
		if (ev->iter == ev->iter_max || ev->iter == 1)
			ft_put_pixel(ev, ev->x, ev->y, 0x000000);
		else
			ft_put_pixel(ev, ev->x, ev->y, (ev->color * ev->iter));
	}
}
