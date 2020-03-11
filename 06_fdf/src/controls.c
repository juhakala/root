/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:33:19 by jhakala           #+#    #+#             */
/*   Updated: 2019/12/04 20:37:43 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_key_move(int key, t_event *ev)
{
	if (key == 123 || key == 0)
		ev->x_offset -= 10;
	else if (key == 124 || key == 2)
		ev->x_offset += 10;
	else if (key == 125 || key == 1)
		ev->y_offset += 10;
	else
		ev->y_offset -= 10;
}

void	ft_key_color(int key, t_event *ev)
{
	if (key == 8)
	{
		if (ev->color_scheme == 3)
			ev->color_scheme = 0;
		else
			ev->color_scheme++;
	}
	else if (key == 49)
		ev->color_scheme = 2;
	else
	{
		if (ev->bg_color == 2)
			ev->bg_color = 0;
		else
			ev->bg_color++;
	}
}

void	ft_key_rotate(int key, t_event *ev)
{
	if (key == 91)
		ev->alpha -= 0.05;
	else if (key == 84)
		ev->alpha += 0.05;
	else if (key == 86)
		ev->beta += 0.05;
	else if (key == 88)
		ev->beta -= 0.05;
	else if (key == 85 || key == 89)
		ev->gamma -= 0.05;
	else if (key == 83 || key == 92)
		ev->gamma += 0.05;
}

void	ft_key_projection(int key, t_event *ev)
{
	ev->alpha = 0;
	ev->beta = 0;
	ev->gamma = 0;
	ev->projection = 0;
	if (key == 15)
	{
		ev->instructions = 0;
		ev->color_scheme = 0;
		ev->bg_color = 0;
		ev->x_offset = 0;
		ev->y_offset = 0;
		ev->zoom = FT_MIN(WIN_W / ev->map->width / 2,
					WIN_H / ev->map->height / 2);
		ev->z_dim = ev->zoom;
	}
	else if (key == 34)
		ev->projection = 1;
}

void	ft_key_rest(int key, t_event *ev)
{
	if (key == 53)
		exit(0);
	else if (key == 32)
	{
		if (ev->instructions == 1)
			ev->instructions = 0;
		else
			ev->instructions++;
	}
	else if (key == 78)
		ev->z_dim -= 1;
	else if (key == 69)
		ev->z_dim += 1;
	else if (key == 82)
	{
		ev->zoom += 1;
		ev->z_dim += 1;
	}
	else if (key == 65)
	{
		ev->zoom -= 1;
		ev->z_dim -= 1;
	}
}
