/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:53:53 by jhakala           #+#    #+#             */
/*   Updated: 2020/03/04 19:45:37 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static int	get_id(t_room_l *room_lst, char *name)
{
	while (room_lst)
	{
		if (ft_strcmp(room_lst->name, name) == 0)
			return (room_lst->id);
		room_lst = room_lst->next;
	}
	ft_error("Error: did not find link end name\n");
	return (0);
}

static void	init_room_link_arr(t_room_l *room, t_room_l *room_lst,
							t_link_l *link_lst, int size)
{
	int i;

	if (!(room->link_arr = (int *)malloc(sizeof(int) * size)))
		ft_error("Error: room_link_malloc\n");
	i = 0;
	while (link_lst)
	{
		if (ft_strcmp(room->name, link_lst->start) == 0)
		{
			room->link_arr[i] = get_id(room_lst, link_lst->end);
			i++;
		}
		else if (ft_strcmp(room->name, link_lst->end) == 0)
		{
			room->link_arr[i] = get_id(room_lst, link_lst->start);
			i++;
		}
		link_lst = link_lst->next;
	}
}

static int	count_links(char *name, t_link_l *link_lst)
{
	int	i;

	i = 0;
	while (link_lst)
	{
		if (ft_strcmp(name, link_lst->start) == 0)
			i++;
		if (ft_strcmp(name, link_lst->end) == 0)
			i++;
		link_lst = link_lst->next;
	}
	return (i);
}

static void	make_mem_id_arr(t_mem *mem, t_room_l *room_lst)
{
	int i;

	if (!(mem->id_arr = (t_room_l **)malloc(sizeof(t_room_l*) * mem->n_rooms)))
		ft_error("Error: mem->id_arr malloc error\n");
	i = 0;
	while (room_lst)
	{
		mem->id_arr[i] = room_lst;
		room_lst = room_lst->next;
		i++;
	}
}

void		ft_make_links(t_mem *mem)
{
	t_room_l	*tmp_r;
	int			count;

	count = 0;
	tmp_r = mem->room_lst;
	while (tmp_r)
	{
		if (tmp_r->pos == 1)
			mem->id_start = tmp_r->id;
		else if (tmp_r->pos == 2)
			mem->id_end = tmp_r->id;
		tmp_r->n_links = count_links(tmp_r->name, mem->link_lst);
		init_room_link_arr(tmp_r, mem->room_lst, mem->link_lst, tmp_r->n_links);
		tmp_r = tmp_r->next;
		count++;
	}
	mem->n_rooms = count;
	make_mem_id_arr(mem, mem->room_lst);
}
