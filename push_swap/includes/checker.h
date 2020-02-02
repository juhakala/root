/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 20:43:36 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/02 23:26:30 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include <mlx.h>

# define WIN_W 1250
# define WIN_H 1050

typedef struct	s_mem
{
	int			*a;
	int			*b;
	int			a_size;
	int			b_size;
	int			size;
}				t_mem;

typedef struct	s_event
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_addr;
	int			pits_in_pixel;
	int			size_line;
	int			endian;
	int			step_count;
	t_mem		*mem;
}				t_event;

long long int	ft_atoi_mod(const char *str);
int				ft_make_move(char *str, t_mem *mem);
void			ft_end_order(t_mem *mem);

/*
** mlx
*/
void			ft_mlx(t_mem *mem);
void			ft_draw(t_event *ev, t_mem *mem);
int				ft_keyevent(int key, t_event *ev);
void			ft_put_pixel(t_event *ev, int x, int y, int color);
void			ft_a_nega(int x, int y, t_event *ev, int ac);
void			ft_b_nega(int x, int y, t_event *ev, int ac);

/*
** cmd
*/
int				cmd_sa(t_mem *mem);
int				cmd_sb(t_mem *mem);
int				cmd_ss(t_mem *mem);
int				cmd_pa(t_mem *mem);
int				cmd_pb(t_mem *mem);
int				cmd_ra(t_mem *mem);
int				cmd_rb(t_mem *mem);
int				cmd_rr(t_mem *mem);
int				cmd_rra(t_mem *mem);
int				cmd_rrb(t_mem *mem);
int				cmd_rrr(t_mem *mem);

/*
** utils
*/
void			ft_error(char *str);
int				ft_order(t_mem *mem);
int				ft_str_size(char **str);
int				ft_get_high(t_mem *mem);
t_mem			*ft_stack_init(t_mem *mem, int ac);

#endif
