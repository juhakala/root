/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_support.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:08:14 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/08 21:19:23 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_make_animation_move(t_ev *ev)
{
	if (ev->a_cr_dir == 1)
		ev->cr += 1 * ev->animation_speed;
	else if (ev->a_cr_dir == 2)
		ev->cr -= 1 * ev->animation_speed;
	if (ev->a_ci_dir == 1)
		ev->ci += 1 * ev->animation_speed;
	else if (ev->a_ci_dir == 2)
		ev->ci -= 1 * ev->animation_speed;
}
