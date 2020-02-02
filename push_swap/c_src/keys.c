/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fie...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:04:02 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/02 23:15:29 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ok(t_event *ev)
{
	char	*itoa;

	itoa = ft_itoa(ev->step_count);
	mlx_string_put(ev->mlx, ev->win, WIN_W / 2, WIN_H / 2, 0xFF0000, "OK");
	mlx_string_put(ev->mlx, ev->win, WIN_W / 2 - 13, 45, 0xFF0000, itoa);
	free(itoa);
}

int			esc_event(int key, t_event *ev)
{
	char	*line;
	int		i;
	char	*itoa;

	i = 0;
	if (key == 124)
	{
		if ((i = get_next_line(0, &line)) > 0)
		{
			ft_make_move(line, ev->mem);
			ev->step_count++;
		}
	}
	ft_draw(ev, ev->mem);
	if (i > 0)
	{
		mlx_string_put(ev->mlx, ev->win, WIN_W / 2 - 13, 20, 0xFF0000, line);
		itoa = ft_itoa(ev->step_count);
		mlx_string_put(ev->mlx, ev->win, WIN_W / 2 - 13, 45, 0xFF0000, itoa);
		free(itoa);
		free(line);
	}
	if (ft_order(ev->mem))
		ok(ev);
	return (1);
}

static int	nb_event(t_event *ev)
{
	char	*itoa;

	itoa = ft_itoa(ev->step_count);
	mlx_string_put(ev->mlx, ev->win, WIN_W / 2 - 13, 45, 0xFF0000, itoa);
	free(itoa);
	return (1);
}

int			ft_keyevent(int key, t_event *ev)
{
	if (key == 53)
		exit(0);
	if (key == 124)
		esc_event(key, ev);
	else if (key == 123)
		nb_event(ev);
	return (1);
}

void		ft_put_pixel(t_event *ev, int x, int y, int color)
{
	int i;

	if (y >= 0 && x >= 0 && WIN_H > y && WIN_W > x)
	{
		i = (x * ev->pits_in_pixel / 8) + (y * ev->size_line);
		ev->data_addr[i] = color;
		ev->data_addr[++i] = color >> 8;
		ev->data_addr[++i] = color >> 16;
	}
}
