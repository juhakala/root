/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_steps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:42:13 by jhakala           #+#    #+#             */
/*   Updated: 2020/03/11 16:01:55 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		ft_set_steps(t_mem *mem, int id, int parent)
{
	t_room_l	*room;
	int			i;
	int			check;
	int			count;

	room = mem->id_arr[id];
	i = 0;
	check = 0;
	count = parent + 1;
	while (i < room->n_links)
	{
		if (mem->id_arr[room->link_arr[i]]->to_end > count || mem->id_arr[room->link_arr[i]]->to_end == -1)
		{
			mem->id_arr[room->link_arr[i]]->to_end = count;
			check = 1;
		}
		i++;
	}
	if (check == 0)
		return (1);
	i = 0;
	while (i < room->n_links)
	{
		if (mem->id_arr[room->link_arr[i]]->to_end != -2 && room->link_arr[i] != mem->id_start)
			ft_set_steps(mem, room->link_arr[i], count);
		i++;
	}
	return (1);
}

void	ft_trim_links(t_mem *mem)
{
	t_room_l	*room;
	int			i;
	int			j;

	i = 0;
	while (i < mem->n_rooms)
	{
		room = mem->id_arr[i];
		j = 0;
		while (j < room->n_links)
		{
			if (room->link_arr[j] == mem->id_end && room->id != mem->id_start)
			{
				room->link_arr[0] = mem->id_end;
				room->n_links = 1;
			}
			else if (room->link_arr[j] == mem->id_start)
			{
				room->link_arr[j] = room->link_arr[room->n_links - 1];
				room->n_links--;
			}
			if (get_bit(mem->dead_end, room->link_arr[j]) == 1)
			{
				if (j != room->n_links - 1)
					room->link_arr[j] = room->link_arr[room->n_links - 1];
				room->n_links--;
			}
			j++;
		}
		i++;
	}
}

void	ft_sort_room_link_arrs(t_mem *mem)
{
	t_room_l	*room;
	int			i;
	int			j;
	int			tmp;

	ft_trim_links(mem);
	i = 0;
//			print_links(mem);
	while (i < mem->n_rooms)
	{
		j = 0;
		while (get_bit(mem->dead_end, i) == 1)
			i++;
		if (!(i < mem->n_rooms))
			break ;
		room = mem->id_arr[i];
		while (j + 1 < room->n_links)
		{
			if (mem->id_arr[room->link_arr[j]]->to_end > mem->id_arr[room->link_arr[j + 1]]->to_end)
			{
				tmp = room->link_arr[j + 1];
				room->link_arr[j + 1] = room->link_arr[j];
				room->link_arr[j] = tmp;
				j = -1;
			}
			j++;
		}
		i++;
	}
//			print_links(mem);
}
