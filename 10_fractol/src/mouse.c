/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:57:20 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/11 16:19:36 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse_julia(int x, int y, t_ev *ev)
{
	if ((ev->type == 1 || ev->type == 5) && ev->julia_mouse == 1)
	{
		ev->cr = x * 2;
		ev->ci = y * 2 - 800;
		ft_pthread(ev);
	}
	return (0);
}

static void	zoom(int x, int y, double z, t_ev *ev)
{
	double w;
	double wx;
	double h;
	double hy;

	w = (2.0f - (-2.0f)) * ev->zoom;
	h = (2.0f - (-2.0f)) * ev->zoom;
	wx = (2.0f - (-2.0f)) * (ev->zoom * z);
	hy = (2.0f - (-2.0f)) * (ev->zoom * z);
	ev->zoom *= z;
	ev->x_offset -= (((double)x - WIN_W / 2) / WIN_W) * (wx - w);
	ev->y_offset -= (((double)y - WIN_H / 2) / WIN_H) * (hy - h);
}

static void	middle_mouse(int x, int y, t_ev *ev)
{
	ft_printf("type	%9d\n", ev->type);
	ft_printf("m->x	%9d\n", x);
	ft_printf("m->y	%9d\n", y);
	ft_printf("ev->cr	%9.2f\n", ev->cr);
	ft_printf("ev->ci	%9.2f\n", ev->ci);
	ft_printf("color	%9d\n", ev->color);
	ft_printf("zoom	%9.2f\n", ev->zoom);
	ft_printf("iter_max%9d\n\n", ev->iter_max);
}

int			mouse_hook(int mousecode, int x, int y, t_ev *ev)
{
	if (mousecode == 2)
	{
		if (ev->julia_mouse == 1)
			ev->julia_mouse = 0;
		else
			ev->julia_mouse = 1;
	}
	else if (mousecode == 1)
	{
		ev->cr = x * 2;
		ev->ci = y * 2 - 800;
	}
	else if (mousecode == 4)
		zoom(x, y, 1.1f, ev);
	else if (mousecode == 5)
		zoom(x, y, 1 / 1.1f, ev);
	else if (mousecode == 3)
		middle_mouse(x, y, ev);
	ft_pthread(ev);
	return (0);
}
