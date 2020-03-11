/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:32:47 by jhakala           #+#    #+#             */
/*   Updated: 2020/03/11 19:08:22 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

t_mem		*ft_init(t_mem *mem)
{
	if (!(mem = (t_mem *)ft_memalloc(sizeof(t_mem))))
		ft_error("mem_malloc_error\n");
	mem->n_ants = 0;
	mem->max_len = 2147483647;
	mem->flow = 2147483647;
	mem->room_lst = NULL;
	mem->link_lst = NULL;
	return (mem);
}

t_room_l	*ft_init_room(int pos, char *line, int id)
{
	t_room_l	*room;
	int			i;

	i = 0;
	if (!(room = (t_room_l *)ft_memalloc(sizeof(t_room_l))))
		ft_error("room_malloc_error\n");
	while (line[i] == ' ')
		i++;
	while (line[i] != ' ')
		i++;
	room->name = ft_strsub(line, 0, i);
	i++;
	room->x = ft_atoi(line + i);
	while (line[i] != ' ')
		i++;
	i++;
	room->y = ft_atoi_mod(line + i);
	room->pos = pos;
	room->id = id;
	room->next = NULL;
	if (pos == 2)
		room->to_end = 0;
	else
		room->to_end = -1;
	return (room);
}

t_link_l	*ft_init_link(char *line)
{
	t_link_l	*link;
	int			i;

	i = 0;
	if (!(link = (t_link_l *)ft_memalloc(sizeof(t_link_l))))
		ft_error("link_malloc_error\n");
	while (line[i] != '-')
		i++;
	link->start = ft_strsub(line, 0, i);
	while (*line != '-')
		line++;
	line++;
	i = 0;
	while (line[i] != '\0')
		i++;
	link->end = ft_strsub(line, 0, i);
	return (link);
}

void		ft_init_visit_dead(t_mem *mem, int size)
{
	int			i;

	if (!(mem->visited = (char *)malloc(sizeof(char) * (size + 1))))
		ft_error("Error: visited_path_malloc\n");
	i = 0;
	while (i < size)
		mem->visited[i++] = 0;
	if (!(mem->dead_end = (char *)malloc(sizeof(char) * (size + 1))))
		ft_error("Error: dead_end_malloc\n");
	i = 0;
	while (i < size)
        mem->dead_end[i++] = 0;
	while (ft_trim(mem));
}

void		ft_init_ants(t_mem *mem)
{
	int i;

	if (!(mem->ant_arr = (t_ant**)malloc(sizeof(t_ant*) * (mem->n_ants + 1))))
		ft_error("Error: ant_arr_malloc\n");
	i = 0;
	while (i < mem->n_ants)
	{
		if (!(mem->ant_arr[i] = (t_ant*)malloc(sizeof(t_ant))))
			ft_error("Error: ant_arr[i]_malloc\n");
		mem->ant_arr[i]->n = i + 1;
		i++;
	}
}
