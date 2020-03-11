/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:29:36 by jhakala           #+#    #+#             */
/*   Updated: 2020/03/11 15:54:30 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	print_steps(t_mem *mem)
{
	int i;
	t_room_l *room_lst = mem->room_lst;

	while (room_lst)
	{
		i = 0;
		ft_printf("name = %s, steps = %d\n", room_lst->name, room_lst->to_end);
		while (i < room_lst->n_links)
		{
			ft_printf("	id = %d, steps = %d\n", mem->id_arr[room_lst->link_arr[i]]->id, mem->id_arr[room_lst->link_arr[i]]->to_end);
			i++;
		}
		room_lst = room_lst->next;
	}
	ft_printf("\n");
}

int		count_max_paths(t_room_l *start, t_room_l *end, t_mem *mem)
{
	int s_count;
	int e_count;
	int i;

	s_count = 0;
	e_count = 0;
	i = 0;
	while (i < start->n_links)
	{
		if (get_bit(mem->dead_end, mem->id_arr[start->link_arr[i]]->id) == 0)
			s_count++;
		i++;
	}
	i = 0;
	while (i < end->n_links)
	{
		if (get_bit(mem->dead_end, mem->id_arr[end->link_arr[i]]->id) == 0)
			e_count++;
		i++;
	}
	ft_printf("e_count = %d, s_count = %d, n_ants = %d\n", e_count, s_count, mem->n_ants);
	if (e_count < mem->n_ants || s_count < mem->n_ants)
		return (e_count < s_count ? e_count : s_count);
	return (mem->n_ants);
}

void	ft_find_steps(t_mem *mem)
{
	int i;

	i = 0;
	while (i < mem->n_rooms)
	{
		if (get_bit(mem->dead_end, i) == 1)
			mem->id_arr[i]->to_end = -2;
		i++;
	}
//	ft_sort_room_link_arrs(mem);
	ft_set_steps(mem, mem->id_end, 0);
	ft_sort_room_link_arrs(mem);

	t_room_l *room;
	room = mem->id_arr[mem->id_start];
//	print_steps(mem);
	ft_printf("name = %s, to_end = %d\n", room->name, mem->id_arr[mem->id_start]->to_end);
	if (mem->id_arr[mem->id_start]->to_end == -1)
		ft_error("Error: no path\n");
	if ((mem->max_paths = count_max_paths(mem->id_arr[mem->id_start],
										mem->id_arr[mem->id_end], mem)) == 0)
		ft_error("Error: count_max_paths_zero(no paths?)\n");
}

//	katotaan dead_endista onko room umpikuja, ja poistetaan jokaisen huoneen linkkilistalta, siirtamalla muita
//	eteenpain ja miinustamalla room->n_links - 1
//done
