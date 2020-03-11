/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revers_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:13:50 by jhakala           #+#    #+#             */
/*   Updated: 2020/03/07 15:45:42 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	reverse_room_list(t_mem *mem)
{
	t_room_l *prev;
	t_room_l *cur;
	t_room_l *next;

	prev = NULL;
	cur = mem->room_lst;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	mem->room_lst = prev;
}

void	reverse_link_list(t_mem *mem)
{

	t_link_l *prev;
	t_link_l *cur;
	t_link_l *next;

	prev = NULL;
	cur = mem->link_lst;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	mem->link_lst = prev;
}
