/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 21:19:16 by jhakala           #+#    #+#             */
/*   Updated: 2019/12/04 18:35:46 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	ft_perce(int start, int end, int cur)
{
	double dist;
	double place;

	place = cur - start;
	dist = end - start;
	return ((dist == 0) ? 1.0 : (place / dist));
}

int		ft_get_light(int start, int end, double perce)
{
	return ((int)((1 - perce) * start + end * perce));
}

int		ft_color(t_xyz start, t_xyz end, t_xyz cur, t_xyz delta)
{
	double	perce;
	int		red;
	int		green;
	int		blue;

	if (start.color == end.color)
		return (end.color);
	if (delta.x > delta.y)
		perce = ft_perce(start.x, end.x, cur.x);
	else
		perce = ft_perce(start.y, end.y, cur.y);
	red = ft_get_light((start.color >> 16) & 0xFF,
				(end.color >> 16) & 0xFF, perce);
	green = ft_get_light((start.color >> 8) & 0xFF,
				(end.color >> 8) & 0xFF, perce);
	blue = ft_get_light(start.color & 0xFF, end.color & 0xFF, perce);
	return ((red << 16) | (green << 8) | blue);
}

int		ft_color_alt(int i)
{
	if (i < 10)
		return (ft_atoi_base("3D84D5", 16));
	if (i < 50)
		return (ft_atoi_base("53DA8A", 16));
	if (i < 70)
		return (ft_atoi_base("896D47", 16));
	else
		return (ft_atoi_base("EFEBE7", 16));
}
