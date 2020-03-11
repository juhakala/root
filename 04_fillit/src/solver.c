/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:26:37 by jhakala           #+#    #+#             */
/*   Updated: 2019/11/21 16:58:13 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_place_in_map(t_map *map, t_piece *piece, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < piece->width)
	{
		j = 0;
		while (j < piece->height)
		{
			if (piece->pos[j][i] == '#')
				map->table[j + y][i + x] = piece->letter;
			j++;
		}
		i++;
	}
}

void	ft_take_from_map(t_map *map, t_piece *piece, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < piece->width)
	{
		j = 0;
		while (j < piece->height)
		{
			if (piece->pos[j][i] == '#')
				map->table[j + y][i + x] = '.';
			j++;
		}
		i++;
	}
}

int		ft_place_check(t_map *map, t_piece *piece, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < piece->width)
	{
		j = 0;
		while (j < piece->height)
		{
			if (piece->pos[j][i] == '#' && map->table[j + y][i + x] != '.')
				return (0);
			j++;
		}
		i++;
	}
	ft_place_in_map(map, piece, x, y);
	return (1);
}

int		ft_place_to_map(t_map *map, t_list *lst)
{
	int		x;
	int		y;
	t_piece	*piece;

	if (lst == NULL)
		return (1);
	y = 0;
	piece = (t_piece *)(lst->content);
	while (y < map->size - piece->height + 1)
	{
		x = 0;
		while (x < map->size - piece->width + 1)
		{
			if (ft_place_check(map, piece, x, y))
			{
				if (ft_place_to_map(map, lst->next))
					return (1);
				else
					ft_take_from_map(map, piece, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_map	*ft_solve(t_list *lst)
{
	t_map	*map;
	int		size;

	size = ft_calc_min_map_size(ft_lst_count(lst) * 4);
	map = ft_new_map(size);
	while (!ft_place_to_map(map, lst))
	{
		size++;
		ft_free_map(map);
		map = ft_new_map(size);
	}
	return (map);
}
