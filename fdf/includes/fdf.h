/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:29:34 by jhakala           #+#    #+#             */
/*   Updated: 2019/12/04 19:30:43 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

# define WIN_W 1800
# define WIN_H 1200
# define C 0x938888

# define FT_MIN(A, B) (((A) < (B)) ? (A) : (B))

typedef struct		s_point
{
	int				i;
	int				color;
	void			*next;
}					t_point;
typedef struct		s_map
{
	int				*value_arr;
	int				*color_arr;
	int				height;
	int				width;
	size_t			count;
}					t_map;
typedef struct		s_event
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data_address;
	int				pits_in_pixel;
	int				size_line;
	int				endian;
	t_map			*map;
	double			gamma;
	double			alpha;
	double			beta;
	int				x_offset;
	int				y_offset;
	int				zoom;
	int				projection;
	int				z_dim;
	int				color_scheme;
	int				bg_color;
	int				instructions;
}					t_event;
typedef struct		s_xyz
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_xyz;

void				ft_error(char *str);
void				ft_menu(t_event *ev);

t_map				*ft_malloc_map(t_map *map);
t_event				*ft_initevent(t_map *map, char *name);

void				ft_read(char *av, t_map *map, t_point **lst);

t_point				*ft_pointrev(t_point **lst);
void				ft_maparray(t_point *point, t_map *map);

void				ft_draw(t_event *ev, t_map *map);

t_xyz				ft_newxy(int x, int y, t_event *ev);

int					ft_color_alt(int i);
int					ft_color(t_xyz start, t_xyz end, t_xyz cur, t_xyz delta);

void				ft_key_move(int key, t_event *ev);
void				ft_key_color(int key, t_event *ev);
void				ft_key_rotate(int key, t_event *ev);
void				ft_key_projection(int key, t_event *ev);
void				ft_key_rest(int key, t_event *ev);

#endif
