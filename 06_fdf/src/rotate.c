/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 23:50:44 by jhakala           #+#    #+#             */
/*   Updated: 2019/12/04 19:41:29 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_x(int *y, int *z, double alpha, t_event *ev)
{
	int previous_y;

	previous_y = *y - ev->zoom * (ev->map->height - 1) / 2;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(int *x, int *z, double beta, t_event *ev)
{
	int previous_x;

	previous_x = *x - ev->zoom * (ev->map->width - 1) / 2;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

void	rotate_z(int *x, int *y, double gamma)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}

void	iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

t_xyz	ft_newxy(int x, int y, t_event *ev)
{
	t_xyz	point;

	point.x = x * ev->zoom;
	point.y = y * ev->zoom;
	point.z = ev->map->value_arr[y * ev->map->width + x] * ev->z_dim;
	rotate_x(&point.y, &point.z, ev->alpha, ev);
	rotate_y(&point.x, &point.z, ev->beta, ev);
	rotate_z(&point.x, &point.y, ev->gamma);
	if (ev->projection == 1)
		iso(&point.x, &point.y, point.z);
	point.x += WIN_W / 2 + ev->x_offset;
	point.y += WIN_H / 2 + ev->y_offset;
	if (ev->color_scheme == 0)
		point.color = ft_atoi_base("FFFFFF", 16);
	else if (ev->color_scheme == 1)
		point.color = ft_atoi_base("CFC1C1", 16);
	else if (ev->color_scheme == 2)
		point.color = ev->map->color_arr[y * ev->map->width + x];
	else
		point.color = ft_color_alt(ev->map->value_arr[y * ev->map->width + x]);
	return (point);
}
