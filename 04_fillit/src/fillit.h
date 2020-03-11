/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:38:43 by jhakala           #+#    #+#             */
/*   Updated: 2019/11/23 16:10:10 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_map
{
	int			size;
	char		**table;
}				t_map;

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_piece
{
	int			height;
	int			width;
	char		letter;
	char		**pos;
}				t_piece;

t_list			*ft_read2(t_list *lst, char *str, char c);
int				ft_error(void);

void			ft_lst_rev(t_list **lst);
int				ft_lst_count(t_list *lst);
int				ft_calc_min_map_size(int nb);
void			ft_free_map(t_map *map);

t_map			*ft_solve(t_list *lst);

t_piece			*ft_new_piece(char **pos, int width, int height, char c);
t_pos			*ft_new_pos_xy(int x, int y);
t_map			*ft_new_map(int nb);
void			ft_free_piece(t_piece *piece);
t_list			*ft_free_lst(t_list *lst);

#endif
