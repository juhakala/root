/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:53:00 by jhakala           #+#    #+#             */
/*   Updated: 2020/03/04 19:46:37 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	print_bits(char *arr, t_mem *mem)
{
	int i;

	i = -1;
	while (++i < mem->n_rooms)
		ft_printf("%s: %d\n", mem->id_arr[i]->name, get_bit(arr, i));
}

void	toggle_bit(char *arr, int i)
{
	arr[i / 8] ^= 1 << (i % 8);
}

char	get_bit(char *arr, int i)
{
	return (1 & (arr[i / 8] >> (i % 8)));
}

int		count_dead(t_room_l *room, t_mem *mem)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(i < room->n_links)
	{
		if (get_bit(mem->dead_end, mem->id_arr[room->link_arr[i]]->id))
			count++;
		i++;
	}
	return (count);
}

/*
**mark all rooms that are never getting visited
*/

int		ft_trim(t_mem *mem)
{
	t_room_l	*lst;
	int			check;

	check = 0;
	lst = mem->room_lst;
//	ft_printf("%d\n", mem->id_end);
	while (lst)
	{
		if (get_bit(mem->dead_end, lst->id) != 1)
		{
			if (lst->n_links == 0)
			{
				toggle_bit(mem->dead_end, lst->id);
				check = 1;
			}
			else if (lst->n_links - 1 == count_dead(lst, mem)
					 && lst->id != mem->id_end && lst->id != mem->id_start)
			{
				toggle_bit(mem->dead_end, lst->id);
				check = 1;
			}
		}
		lst = lst->next;
	}
	return (check);
}
