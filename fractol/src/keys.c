/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:30:56 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/11 16:02:39 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	offset_move(int key, t_ev *ev)
{
	int i;

	i = 1;
	if (ev->offset_speed == 0)
	{
		(key == 124) ? ev->x_offset += ev->zoom / 10 * i : 0;
		(key == 123) ? ev->x_offset -= ev->zoom / 10 * i : 0;
		(key == 125) ? ev->y_offset += ev->zoom / 10 * i : 0;
		(key == 126) ? ev->y_offset -= ev->zoom / 10 * i : 0;
	}
	else if (ev->offset_speed == 1)
	{
		(key == 124) ? ev->x_offset += 5 * i : 0;
		(key == 123) ? ev->x_offset -= 5 * i : 0;
		(key == 125) ? ev->y_offset += 5 * i : 0;
		(key == 126) ? ev->y_offset -= 5 * i : 0;
	}
	if (key == 269)
		ev->offset_speed = (ev->offset_speed == 1 ? 0 : 1);
}

static void	cinematic_settings(t_ev *ev)
{
	ev->type = 1;
	ev->zoom = 262;
	ev->animation_speed = 1;
	ev->iter_max = 50;
	ev->x_offset = 0;
	ev->y_offset = 0;
}

static void	cinematic_pick(int key, t_ev *ev)
{
	(key == 29) ? ev->cinematic += 1 : 0;
	(key == 25) ? ev->cinematic -= 1 : 0;
	(key == 31) ? ev->x_offset = 0 : 0;
	(key == 31) ? ev->y_offset = 0 : 0;
	if (key == 35)
		cinematic_settings(ev);
	else if (key == 4)
		ft_print_keys();
	else if (key == 29 || key == 25)
	{
		ev->cinematic > 3 ? ev->cinematic = 1 : 0;
		ev->cinematic < 0 ? ev->cinematic = 3 : 0;
		ev->cinematic == 0 ? ev->color = 16777216 : 0;
		ev->cinematic == 1 ? ev->color = 255 : 0;
		ev->cinematic == 2 ? ev->color = 65280 : 0;
		ev->cinematic == 3 ? ev->color = 16711680 : 0;
	}
}

int			ft_keyevent(int key, t_ev *ev)
{
	if (key == 53)
		exit(0);
	if (ev->info == 0)
	{
		(key == 256) ? ev->info = 1 : 0;
		(key == 7) ? ev->type += 1 : 0;
		ev->type > 5 ? ev->type = 1 : 0;
		(key == 15) ? reset(ev) : 0;
		(key == 65) ? ev->zoom *= 1.05 : 0;
		(key == 82) ? ev->zoom /= 1.05 : 0;
		(key == 69) ? ev->iter_max += 1 : 0;
		(key == 78) ? ev->iter_max -= 1 : 0;
		(key == 43) ? ev->color -= 1 : 0;
		(key == 47) ? ev->color += 1 : 0;
		if ((key > 122 && key < 127) || key == 269)
			offset_move(key, ev);
		else if (key == 0 || key == 18 || key == 19 ||
				(key > 82 && key < 90) || key == 91 || key == 92)
			ft_animation_control(key, ev);
		else if (key == 29 || key == 25 || key == 35 || key == 31 || key == 4)
			cinematic_pick(key, ev);
		(key == 49) ? ev->color = rand() % 16777216 : 0;
	}
	ft_pthread(ev);
	return (1);
}

void		reset(t_ev *ev)
{
	ev->julia_mouse = 1;
	ev->iter_max = 10;
	ev->color = 16777216;
	ev->zoom = 100;
	ev->x_offset = 0;
	ev->y_offset = 0;
	ev->cr = 0;
	ev->ci = 0;
	ev->offset_speed = 0;
	ev->animation = 0;
	ev->animation_color = 0;
	ev->animation_xy = 0;
	ev->animation_speed = 1;
	cr_ci_random(ev);
}
