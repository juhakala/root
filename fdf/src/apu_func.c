/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apu_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:14:46 by jhakala           #+#    #+#             */
/*   Updated: 2019/12/04 20:35:47 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point		*ft_pointrev(t_point **lst)
{
	t_point *prev;
	t_point *cur;
	t_point *next;

	prev = NULL;
	cur = *lst;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*lst = prev;
	return (*lst);
}

void		ft_freepoints(t_point *point)
{
	t_point *cur;

	while (point != NULL)
	{
		cur = point->next;
		free(point);
		point = cur;
	}
}

void		ft_maparray(t_point *point, t_map *map)
{
	size_t	i;
	size_t	size;
	t_point	*tmp;

	i = 0;
	tmp = point;
	size = sizeof(int) * map->height * map->width;
	if (!(map->value_arr = (int *)ft_memalloc(size)))
		ft_error("");
	if (!(map->color_arr = (int *)ft_memalloc(size)))
		ft_error("");
	while (point != NULL)
	{
		map->value_arr[i] = point->i;
		if (point->color == -1)
			map->color_arr[i] = ft_atoi_base("FFFFFF", 16);
		else
			map->color_arr[i] = point->color;
		point = point->next;
		i++;
	}
	point = tmp;
	ft_freepoints(point);
}
