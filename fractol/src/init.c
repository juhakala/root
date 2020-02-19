/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 20:05:14 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/09 19:43:41 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_ev	*ft_init_ev(void)
{
	t_ev *ev;

	if (!(ev = (t_ev *)ft_memalloc(sizeof(t_ev))))
		exit(0);
	ev->mlx = mlx_init();
	ev->win = mlx_new_window(ev->mlx, WIN_W, WIN_H, "fractol");
	ev->img = mlx_new_image(ev->mlx, WIN_W, WIN_H);
	ev->data_addr = mlx_get_data_addr(ev->img, &(ev->bits_per_pixel),
					&(ev->size_line), &(ev->endian));
	ev->type = 0;
	ev->info = 0;
	reset(ev);
	return (ev);
}
