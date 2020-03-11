/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_and_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:32:18 by jhakala           #+#    #+#             */
/*   Updated: 2019/11/21 16:54:31 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_pos	*ft_new_pos_xy(int x, int y)
{
	t_pos	*point;

	point = ft_memalloc(sizeof(t_pos));
	point->x = x;
	point->y = y;
	return (point);
}

t_piece	*ft_new_piece(char **pos, int width, int height, char c)
{
	t_piece	*piece;

	piece = ft_memalloc(sizeof(t_piece));
	piece->height = height;
	piece->width = width;
	piece->letter = c;
	piece->pos = pos;
	return (piece);
}

t_map	*ft_new_map(int nb)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = nb;
	map->table = (char **)ft_memalloc(sizeof(char *) * nb);
	i = 0;
	while (i < nb)
	{
		map->table[i] = ft_strnew(nb);
		j = 0;
		while (j < nb)
		{
			map->table[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

void	ft_free_piece(t_piece *piece)
{
	int i;

	i = 0;
	while (i < piece->height)
		ft_memdel((void **)(&(piece->pos[i++])));
	ft_memdel((void **)(&(piece->pos)));
	ft_memdel((void **)&piece);
}

t_list	*ft_free_lst(t_list *lst)
{
	t_piece	*piece;
	t_list	*next;

	while (lst)
	{
		piece = (t_piece *)lst->content;
		next = lst->next;
		ft_free_piece(piece);
		ft_memdel((void **)&lst);
		lst = next;
	}
	return (NULL);
}
