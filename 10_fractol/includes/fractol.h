/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:49:32 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/11 15:55:23 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>

# define WIN_W 1600
# define WIN_H 1200
# define THREAD 100
# define R 4

# define FT_ABS(nb) (nb) < (0) ? (-nb) : (nb)

typedef struct	s_ev
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			type;
	int			julia_mouse;
	int			iter;
	int			iter_max;
	int			color;
	double		zoom;
	int			x;
	int			y;
	int			y_max;
	int			x_offset;
	int			y_offset;
	int			offset_speed;
	int			animation;
	int			animation_color;
	int			animation_xy;
	int			animation_speed;
	int			animation_cr;
	int			animation_ci;
	int			a_cr_move;
	int			a_cr_dir;
	int			a_ci_move;
	int			a_ci_dir;
	double		cr;
	double		ci;
	double		zr;
	double		zi;
	double		tmp;
	int			cinematic;
	int			info;
}				t_ev;

/*
**init.c
*/
t_ev			*ft_init_ev(void);

/*
**draw.c
*/
void			ft_draw(t_ev *ev);
void			ft_put_pixel(t_ev *ev, int x, int y, int color);
void			ft_background(t_ev *ev);

/*
**pthread.c
*/
void			ft_pthread(t_ev *ev);

/*
**calcukations
*/
void			julia_calc(t_ev *ev);
void			mandelbrot_calc(t_ev *ev);
void			burningship_calc(t_ev *ev);
void			sierpinski_calc(t_ev *ev);
void			own_calc(t_ev *ev);

/*
**keys.c and info.c
*/
int				ft_keyevent(int key, t_ev *ev);
void			reset(t_ev *ev);
int				ft_keyinfo(int key, t_ev *ev);
void			ft_print_keys(void);

/*
**mouse.c
*/
int				mouse_julia(int x, int y, t_ev *ev);
int				mouse_hook(int mousecode, int x, int y, t_ev *ev);

/*
**animation.c and animation_support.c
*/
int				ft_animation_control(int key, t_ev *ev);
int				animation(t_ev *ev);
void			cr_ci_random(t_ev *ev);
void			ft_make_animation_move(t_ev *ev);

#endif
