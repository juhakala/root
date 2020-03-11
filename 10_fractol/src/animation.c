/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:04:53 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/11 15:57:41 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_dir(t_ev *ev)
{
	int cr_dir;
	int ci_dir;

	cr_dir = ev->animation_cr - (int)ev->cr;
	ci_dir = ev->animation_ci - (int)ev->ci;
	if (cr_dir > -11 && cr_dir < 11)
		ev->a_cr_dir = 0;
	else if (cr_dir > 0)
		ev->a_cr_dir = 1;
	else
		ev->a_cr_dir = 2;
	if (ci_dir > -11 && ci_dir < 11)
		ev->a_ci_dir = 0;
	else if (ci_dir > 0)
		ev->a_ci_dir = 1;
	else
		ev->a_ci_dir = 2;
	if (ev->a_cr_dir == 0 && ev->a_ci_dir == 0)
		return (0);
	return (1);
}

static void	animation_speed(int key, t_ev *ev)
{
	key == 83 ? ev->animation_speed = 1 : 0;
	key == 84 ? ev->animation_speed = 2 : 0;
	key == 85 ? ev->animation_speed = 3 : 0;
	key == 86 ? ev->animation_speed = 4 : 0;
	key == 87 ? ev->animation_speed = 5 : 0;
	key == 88 ? ev->animation_speed = 6 : 0;
	key == 89 ? ev->animation_speed = 7 : 0;
	key == 91 ? ev->animation_speed = 8 : 0;
	key == 92 ? ev->animation_speed = 9 : 0;
}

void		cr_ci_random(t_ev *ev)
{
	ev->animation_cr = rand() % 1200;
	ev->animation_ci = rand() % 1244;
	ev->a_cr_move = FT_ABS(ev->animation_cr - (int)ev->cr);
	ev->a_ci_move = FT_ABS(ev->animation_ci - (int)ev->ci);
}

int			animation(t_ev *ev)
{
	if (ev->animation == 1)
	{
		if (ev->animation_color == 1)
			ev->color += 1 * ev->animation_speed;
		else if (ev->animation_color == 2)
			ev->color = rand() % 16777216;
		if (ev->animation_xy == 1)
		{
			while (get_dir(ev) == 0)
				cr_ci_random(ev);
			ft_make_animation_move(ev);
		}
		ft_pthread(ev);
	}
	return (0);
}

int			ft_animation_control(int key, t_ev *ev)
{
	if ((key > 82 && key < 90) || key == 91 || key == 92)
		animation_speed(key, ev);
	else if (key == 0)
	{
		ev->animation += 1;
		if (ev->animation > 1)
			ev->animation = 0;
	}
	else if (key == 18)
	{
		ev->animation_color += 1;
		if (ev->animation_color > 2)
			ev->animation_color = 0;
	}
	else if (key == 19)
	{
		ev->animation_xy += 1;
		if (ev->animation_xy > 1)
			ev->animation_xy = 0;
	}
	return (0);
}
