/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:28:22 by jhakala           #+#    #+#             */
/*   Updated: 2020/03/11 18:53:49 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include <fcntl.h>

void		ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(0);
}

/*
**can be taken away == just for testing
*/

void		print_linkeds(t_mem *mem)
{
	t_room_l	*room_lst;
	int			i;

	room_lst = mem->room_lst;
	while (room_lst)
	{
		i = 0;
		ft_printf("room_name = %s, n_links = %d\n", room_lst->name, room_lst->n_links);
		while (i < room_lst->n_links)
			ft_printf("from->id = %d, to->id = %d\n", room_lst->id, room_lst->link_arr[i++]);
		room_lst = room_lst->next;
	}
}

void	print_info(t_mem *mem)
{
	t_room_l *room;
	t_link_l *link;

	room = mem->room_lst;
	link = mem->link_lst;
	ft_printf("%d\n", mem->n_ants);
	while (room)
	{
		room->pos == 1 ? ft_printf("##start\n") : 0;
		room->pos == 2 ? ft_printf("##end\n") : 0;
		ft_printf("%s %d %d\n", room->name, room->x, room->y);
		room = room->next;
	}
	while (link)
	{
		ft_printf("%s-%s\n", link->start, link->end);
		link = link->next;
	}
	ft_printf("\n");
}

//tarkista viela ettei samannimisia huoneita -> ehka binary treella?
//muuta ft_strcmp binaariseks -> pitais nopeuttaa huomattavasti

int			main(int ac, char **av)
{
	t_mem *mem;

	if (ac > 2)
		ft_printf("ac = %d av[1] = %s\n", ac, av[1]);
	mem = NULL;
	mem = ft_init(mem);
	ft_read_info(mem);
	ft_make_links(mem);
	ft_init_visit_dead(mem, mem->n_rooms / 8 + 1);
	ft_find_steps(mem);
//	print_info(mem);
	ft_solve(mem);
	ft_init_ants(mem);
//	print_links(mem);
//	system("leaks lem-in");
	return (0);
}
