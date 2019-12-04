/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:31:35 by jhakala           #+#    #+#             */
/*   Updated: 2019/12/04 19:40:36 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_error(char *str)
{
	ft_putstr(str);
	exit(0);
}

void	ft_instructions(t_event *ev)
{
	void *m;
	void *w;

	m = ev->mlx;
	w = ev->win;
	mlx_string_put(ev->mlx, ev->win, 30, 30, 0x938888, "quit:");
	mlx_string_put(ev->mlx, ev->win, 30, 30, 0xF76130, "      esc");
	mlx_string_put(ev->mlx, ev->win, 30, 60, 0x938888, "move:        and ");
	mlx_string_put(m, w, 30, 60, 0xF76130, "      arrows     wasd");
	mlx_string_put(m, w, 30, 90, 0x938888, "zoom:          and");
	mlx_string_put(m, w, 30, 90, 0xF76130, "      numpad 0     .");
	mlx_string_put(m, w, 30, 120, 0x938888, "change z:          and");
	mlx_string_put(m, w, 50, 120, 0xF76130, "        numpad -     +");
	mlx_string_put(m, w, 30, 150, 0x938888, "rotate: numbad 1 - 9");
	mlx_string_put(m, w, 30, 150, 0xF76130, "        numbad 1 - 9");
	mlx_string_put(m, w, 30, 180, 0x938888, "change projection:   and");
	mlx_string_put(m, w, 30, 180, 0xF76130, "                   i     p");
	mlx_string_put(m, w, 30, 210, 0x938888, "change color:");
	mlx_string_put(m, w, 30, 210, 0xF76130, "              c");
	mlx_string_put(m, w, 30, 240, 0x938888, "change bg-color: b");
	mlx_string_put(m, w, 30, 240, 0xF76130, "                 b");
	mlx_string_put(m, w, 30, 270, 0x938888, "reset:");
	mlx_string_put(m, w, 30, 270, 0xF76130, "       r");
	mlx_string_put(m, w, 30, 300, 0x938888, "original color:");
	mlx_string_put(m, w, 30, 300, 0xF76130, "                space");
}

void	ft_menu(t_event *ev)
{
	if (ev->instructions == 0)
	{
		mlx_string_put(ev->mlx, ev->win, 30, 30, C, "  for instructions");
		mlx_string_put(ev->mlx, ev->win, 30, 30, 0xF76130, "u");
	}
	else
		ft_instructions(ev);
}

int		ft_keyevent(int key, t_event *ev)
{
	if ((key >= 123 && key <= 126) || (key >= 0 && key <= 2) || key == 13)
		ft_key_move(key, ev);
	else if (key == 11 || key == 8 || key == 49)
		ft_key_color(key, ev);
	else if ((key >= 83 && key <= 89) || key == 91 || key == 92)
		ft_key_rotate(key, ev);
	else if (key == 15 || key == 35 || key == 34)
		ft_key_projection(key, ev);
	else
		ft_key_rest(key, ev);
	ft_draw(ev, ev->map);
	return (1);
}

int		main(int ac, char **av)
{
	t_map	*map;
	t_point	*lst;
	t_event	*ev;

	lst = NULL;
	map = NULL;
	if (ac != 2)
		ft_error("usage: ./fdf source_file\n");
	map = ft_malloc_map(map);
	ft_read(av[1], map, &lst);
	ft_maparray(ft_pointrev(&lst), map);
	ev = ft_initevent(map, av[1]);
	ft_draw(ev, ev->map);
	mlx_hook(ev->win, 2, 0, ft_keyevent, ev);
	mlx_loop(ev->mlx);
	return (0);
}
