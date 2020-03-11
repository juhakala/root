/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:40:59 by jhakala           #+#    #+#             */
/*   Updated: 2020/03/10 15:15:59 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static void	add_room(t_room_l **alst, t_room_l *new)
{
	new->next = *alst;
	*alst = new;
}

static void	add_link(t_link_l **alst, t_link_l *new)
{
	new->next = *alst;
	*alst = new;
}

static void	get_n_ants(t_mem *mem)
{
	char		*line;
	long long	n_ants;

	n_ants = 0;
	if (get_next_line(FROM, &line) > 0)
	{
		while (line[0] == '#')
		{
			free(line);
			get_next_line(FROM, &line);
		}
		n_ants = ft_atoi_mod(line);
		free(line);
	}
	if (n_ants < 1 || n_ants > 2147483647)
		ft_error("Error: invalid number of ants\n");
	mem->n_ants = (int)n_ants;
}

static void	get_rooms_n_links(t_mem *mem)
{
	char	*line;
	int		pos;
	int		links_started;
	int		id;

	id = 0;
	links_started = 0;
	while (get_next_line(FROM, &line) > 0)
	{
		if (line[0] == 'L' || line[0] == '\0')
		{
			free(line);
			break ;
		}
		else if (line[0] == '#')
			pos = ft_get_comment(line);
		else if (links_started == 0 && ft_valid_room(line))
		{
			add_room(&mem->room_lst, ft_init_room(pos, line, id));
			id++;
			pos = 0;
		}
		else if ((links_started = 1) && ft_valid_link(line, mem->room_lst, mem->link_lst))
		{
			add_link(&mem->link_lst, ft_init_link(line));
		}
//		else
//		{
//			free(line);
//			break ;
//		}
		free(line);
	}
}

void		ft_read_info(t_mem *mem)
{
	get_n_ants(mem);
	get_rooms_n_links(mem);
	reverse_room_list(mem);
	reverse_link_list(mem);
	ft_validate_info(mem);
}
