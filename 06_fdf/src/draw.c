/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:07:46 by jhakala           #+#    #+#             */
/*   Updated: 2019/12/04 19:27:14 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_put_pixel(t_event *ev, int x, int y, int color)
{
	int i;

	if (y >= 0 && x >= 0 && WIN_H > y && WIN_W > x)
	{
		i = (x * ev->pits_in_pixel / 8) + (y * ev->size_line);
		ev->data_address[i] = color;
		ev->data_address[++i] = color >> 8;
		ev->data_address[++i] = color >> 16;
	}
}

void	ft_drawline(t_xyz a, t_xyz b, t_event *ev)
{
	t_xyz	delta;
	t_xyz	sign;
	t_xyz	cur;
	int		error[2];

	delta.x = (b.x - a.x) < 0 ? (b.x - a.x) * -1 : b.x - a.x;
	delta.y = (b.y - a.y) < 0 ? (b.y - a.y) * -1 : b.y - a.y;
	sign.x = a.x < b.x ? 1 : -1;
	sign.y = a.y < b.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = a;
	while (cur.x != b.x || cur.y != b.y)
	{
		ft_put_pixel(ev, cur.x, cur.y, ft_color(a, b, cur, delta));
		if ((error[1] = error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

void	ft_background(t_event *ev)
{
	int *image;
	int i;

	ft_bzero(ev->data_address, WIN_W * WIN_H * (ev->pits_in_pixel / 8));
	image = (int *)(ev->data_address);
	i = 0;
	while (i < WIN_W * WIN_H)
	{
		if (ev->bg_color == 0)
			image[i] = 0x000000;
		else if (ev->bg_color == 1)
			image[i] = 0x494040;
		else
			image[i] = 0xFFFFFF;
		i++;
	}
}

void	ft_draw(t_event *ev, t_map *map)
{
	int x;
	int y;

	y = 0;
	x = 0;
	ft_background(ev);
	while (y < map->height)
	{
		while (x < map->width)
		{
			if (x != map->width - 1)
				ft_drawline(ft_newxy(x, y, ev), ft_newxy(x + 1, y, ev), ev);
			if (y != map->height - 1)
				ft_drawline(ft_newxy(x, y, ev), ft_newxy(x, y + 1, ev), ev);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(ev->mlx, ev->win, ev->img, 0, 0);
	ft_menu(ev);
}
