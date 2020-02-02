/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fie...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:36:03 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/02 23:45:01 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	draw_bar_a(int x, int y, t_event *ev, int ac)
{
	int i;
	int count;
	int color;

	y -= (ev->mem->size < 301 ? (ac * 3) : (ac * 2));
	color = 0xFFFFFF;
	i = 0;
	if (ev->mem->a[ev->mem->a_size - ac] <= 0)
		ft_a_nega(x, y, ev, ac);
	else
	{
		while (ev->mem->a[ev->mem->a_size - ac] - i > 0)
		{
			count = (ev->mem->size < 301 ? 2 : 1);
			while (count-- > 0)
			{
				ft_put_pixel(ev, x, y, color);
				ev->mem->size < 301 ? ft_put_pixel(ev, x, y - 1, color) : 0;
				x++;
			}
			i++;
		}
	}
}

void	draw_bar_b(int x, int y, t_event *ev, int ac)
{
	int i;
	int count;
	int color;

	y -= (ev->mem->size < 301 ? (ac * 3) : (ac * 2));
	color = 0xFFFFFF;
	i = 0;
	if (ev->mem->b[ev->mem->b_size - ac] <= 0)
		ft_b_nega(x, y, ev, ac);
	else
	{
		while (ev->mem->b[ev->mem->b_size - ac] - i > 0)
		{
			count = (ev->mem->size < 301 ? 2 : 1);
			while (count-- > 0)
			{
				ft_put_pixel(ev, x, y, color);
				ev->mem->size < 301 ? ft_put_pixel(ev, x, y - 1, color) : 0;
				x++;
			}
			i++;
		}
	}
}

void	background(t_event *ev)
{
	int *image;
	int i;

	ft_bzero(ev->data_addr, WIN_W * WIN_H * (ev->pits_in_pixel / 8));
	image = (int *)(ev->data_addr);
	i = 0;
	while (i < WIN_W * WIN_H)
	{
		image[i] = 0x000000;
		i++;
	}
}

void	ft_draw(t_event *ev, t_mem *mem)
{
	int ac;
	int bc;

	background(ev);
	ac = mem->a_size;
	bc = mem->b_size;
	while (ac > 0 || bc > 0)
	{
		if (ac > 0)
			draw_bar_a(20, WIN_H - 26, ev, mem->a_size - (ac - 1));
		if (bc > 0)
			draw_bar_b(WIN_W / 2 + 26, WIN_H - 26, ev, mem->b_size - (bc - 1));
		ac--;
		bc--;
	}
	mlx_put_image_to_window(ev->mlx, ev->win, ev->img, 0, 0);
}

void	ft_mlx(t_mem *mem)
{
	t_event	*ev;

	if (!(ev = (t_event *)ft_memalloc(sizeof(t_event))))
		ft_error("event_Error\n");
	ev->mlx = mlx_init();
	ev->win = mlx_new_window(ev->mlx, WIN_W, WIN_H, "checker_vis");
	ev->img = mlx_new_image(ev->mlx, WIN_W, WIN_H);
	ev->data_addr = mlx_get_data_addr(ev->img, &(ev->pits_in_pixel),
			&(ev->size_line), &(ev->endian));
	ev->mem = mem;
	ev->step_count = 0;
	ft_draw(ev, mem);
	mlx_hook(ev->win, 2, 0, ft_keyevent, ev);
	mlx_loop(ev->mlx);
	free(ev);
}
