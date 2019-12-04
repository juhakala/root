/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:56:25 by jhakala           #+#    #+#             */
/*   Updated: 2019/12/04 20:38:39 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map	*ft_malloc_map(t_map *map)
{
	map = NULL;
	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		ft_error("");
	map->value_arr = NULL;
	map->color_arr = NULL;
	map->height = 0;
	map->width = 0;
	map->count = 0;
	return (map);
}

t_event	*ft_initevent(t_map *map, char *name)
{
	t_event *ev;

	if (!(ev = (t_event *)ft_memalloc(sizeof(t_event))))
		ft_error("");
	ev->mlx = mlx_init();
	ev->win = mlx_new_window(ev->mlx, WIN_W, WIN_H,
					ft_strjoin("FdF: ", name));
	ev->img = mlx_new_image(ev->mlx, WIN_W, WIN_H);
	ev->data_address = mlx_get_data_addr(ev->img, &(ev->pits_in_pixel),
			&(ev->size_line), &(ev->endian));
	ev->map = map;
	ev->gamma = 0;
	ev->beta = 0;
	ev->alpha = 0;
	ev->x_offset = 0;
	ev->y_offset = 0;
	ev->zoom = FT_MIN(WIN_W / map->width / 2, WIN_H / map->height / 2);
	ev->projection = 0;
	ev->z_dim = ev->zoom;
	ev->color_scheme = 0;
	ev->bg_color = 0;
	ev->instructions = 0;
	return (ev);
}
