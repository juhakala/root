/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:52:57 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/11 15:55:13 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	usage(void)
{
	ft_printf("julia, mandelbrot, burningship, sierpinski_carpet, own\n");
	exit(0);
}

static int	pick_type(char *av)
{
	int i;

	i = 0;
	(ft_strcmp(av, "julia") == 0 ? i = 1 : 0);
	(ft_strcmp(av, "mandelbrot") == 0 ? i = 2 : 0);
	(ft_strcmp(av, "burningship") == 0 ? i = 3 : 0);
	(ft_strcmp(av, "sierpinski_carpet") == 0 ? i = 4 : 0);
	(ft_strcmp(av, "own") == 0 ? i = 5 : 0);
	if (i == 0)
		usage();
	return (i);
}

int			main(int ac, char **av)
{
	t_ev	*ev;

	if (ac != 2)
		usage();
	if (ac == 2)
		pick_type(av[1]);
	ev = ft_init_ev();
	ev->type = pick_type(av[1]);
	ft_pthread(ev);
	mlx_hook(ev->win, 6, 1L < 6, mouse_julia, ev);
	mlx_hook(ev->win, 2, 0, ft_keyevent, ev);
	mlx_key_hook(ev->win, ft_keyinfo, ev);
	mlx_mouse_hook(ev->win, mouse_hook, ev);
	mlx_loop_hook(ev->mlx, animation, ev);
	mlx_loop(ev->mlx);
	return (0);
}
