/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:30:56 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/11 16:00:55 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_info(char *str)
{
	ft_putendl(str);
}

static void	more_info(int key)
{
	(key == 124) ? print_info("move right") : 0;
	(key == 123) ? print_info("move left") : 0;
	(key == 125) ? print_info("move down") : 0;
	(key == 126) ? print_info("move up") : 0;
	(key == 0) ? print_info("toggle animation") : 0;
	(key == 18) ? print_info("toggle/change animation colors") : 0;
	(key == 19) ? print_info("toggle animation movement (julia)") : 0;
	key == 83 ? print_info("animation speed = 1") : 0;
	key == 84 ? print_info("animation speed = 2") : 0;
	key == 85 ? print_info("animation speed = 3") : 0;
	key == 86 ? print_info("animation speed = 4") : 0;
	key == 87 ? print_info("animation speed = 5") : 0;
	key == 88 ? print_info("animation speed = 6") : 0;
	key == 89 ? print_info("animation speed = 7") : 0;
	key == 91 ? print_info("animation speed = 8") : 0;
	key == 92 ? print_info("animation speed = 9") : 0;
	(key == 29) ? print_info("color to next pure") : 0;
	(key == 25) ? print_info("color to prev pure") : 0;
	(key == 35) ? print_info("change settings to finematic") : 0;
}

int			ft_keyinfo(int key, t_ev *ev)
{
	if (ev->info == 1)
	{
		(key == 256) ? ev->info = 0 : 0;
		(key == 53) ? print_info("exit program") : 0;
		(key == 7) ? print_info("change fractal") : 0;
		(key == 15) ? print_info("reset") : 0;
		(key == 65) ? print_info("zoom++") : 0;
		(key == 82) ? print_info("zoom--") : 0;
		(key == 69) ? print_info("add iterations") : 0;
		(key == 78) ? print_info("reduce iterations") : 0;
		(key == 43) ? print_info("color--") : 0;
		(key == 47) ? print_info("color++") : 0;
		(key == 31) ? print_info("reset movement") : 0;
		(key == 49) ? print_info("random color combination") : 0;
		(key == 4) ? print_info("print help") : 0;
		more_info(key);
	}
	return (1);
}

void		ft_print_keys(void)
{
	system("clear");
	ft_printf("Info-mode:\n	left control + any valid key\n\n");
	ft_printf("Reset:\n	r\n\n");
	ft_printf("Movement:\n	arrow keys\n	right control for speed\n\n");
	ft_printf("Animation:\n	a = on/off\n	1 = color\n	2 = move\n");
	ft_printf("	numpad 1-9 for speed\n\n");
	ft_printf("Iteration:\n	numpad -/+\n\n");
	ft_printf("Zoom:\n	numpad 0/.\n	mousewheel\n\n");
	ft_printf("Cinematics:\n	p\n	9\n	0\n\n");
	ft_printf("Colors:\n	<\n	>\n	space\n\n");
	ft_printf("Center:\n	o\n\n");
	ft_printf("Change fractal:\n	x\n\n");
	ft_printf("Toggle mouse(julia):\n	right-click\n\n");
	ft_printf("Take coordinates(julia):\n	left-click\n\n");
	ft_printf("Fractal info:\n	middle\n\n");
}
