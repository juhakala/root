/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 23:17:27 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/10 22:39:39 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	*pick_calc(void *tmp)
{
	t_ev	*data;

	data = (t_ev *)tmp;
	while (data->y < data->y_max)
	{
		data->x = -(WIN_W / 2) - data->x_offset;
		while (data->x < WIN_W / 2 - data->x_offset)
		{
			data->iter = 0;
			data->type == 1 ? julia_calc(data) : 0;
			data->type == 2 ? mandelbrot_calc(data) : 0;
			data->type == 3 ? burningship_calc(data) : 0;
			data->type == 5 ? own_calc(data) : 0;
			data->x++;
		}
		data->y++;
	}
	return (tmp);
}

void	make_sure(t_ev *ev)
{
	if (ev->zoom > 25000)
		ev->zoom = 25000;
	if (ev->zoom < 1)
		ev->zoom = 1;
	if (ev->iter_max > 200)
		ev->iter_max = 200;
	if (ev->iter_max < 0)
		ev->iter_max = 0;
	(ev->color > 16777216) ? ev->color = 1 : 0;
	(ev->color < 0) ? ev->color = 16777216 : 0;
}

void	ft_pthread(t_ev *ev)
{
	t_ev		tmp[THREAD];
	pthread_t	thread[THREAD];
	int			id;

	make_sure(ev);
	(ev->type == 4) ? sierpinski_calc(ev) : 0;
	id = 0;
	while (id < THREAD)
	{
		ft_memcpy((void*)&tmp[id], (void*)ev, sizeof(t_ev));
		tmp[id].y = WIN_H / THREAD * id - (WIN_H / 2) - ev->y_offset;
		tmp[id].y_max = WIN_H / THREAD * (id + 1) - (WIN_H / 2) - ev->y_offset;
		pthread_create(&thread[id], NULL, pick_calc, &tmp[id]);
		id++;
	}
	while (id--)
		pthread_join(thread[id], NULL);
	mlx_put_image_to_window(ev->mlx, ev->win, ev->img, 0, 0);
}
