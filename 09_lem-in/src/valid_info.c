/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 01:42:35 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/19 16:06:57 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static int	start_end_room(t_room_l *room_lst)
{
	int start;
	int end;

	start = 0;
	end = 0;
	while (room_lst)
	{
		if (room_lst->pos == 1)
			start++;
		if (room_lst->pos == 2)
			end++;
		room_lst = room_lst->next;
	}
	if (start < 1)
		ft_putstr_fd("Error: no start point\n", 2);
	else if (start > 1)
		ft_putstr_fd("Error: too many start points\n", 2);
	if (end < 1)
		ft_putstr_fd("Error: no end point\n", 2);
	else if (end > 1)
		ft_putstr_fd("Error: too many end points\n", 2);
	if (start == 1 && end == 1)
		return (1);
	return (0);
}

void		ft_validate_info(t_mem *mem)
{
	if (!mem->room_lst)
		ft_error("Error: missing rooms\n");
	else if (!mem->link_lst)
		ft_error("Error: missing links\n");
	else if (!start_end_room(mem->room_lst))
		ft_error("");
}
