/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apu_fuct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:45:14 by jhakala           #+#    #+#             */
/*   Updated: 2019/11/23 16:10:22 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lst_rev(t_list **lst)
{
	t_list *prev;
	t_list *cur;
	t_list *next;

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
}

int		ft_lst_count(t_list *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int		ft_calc_min_map_size(int nb)
{
	int i;

	i = 2;
	while (i * i < nb)
		i++;
	return (i);
}

void	ft_free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
		ft_memdel((void **)&(map->table[i++]));
	ft_memdel((void **)&(map->table));
	ft_memdel((void **)&map);
}
