/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:01:35 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/27 20:41:49 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int			ft_get_comment(char *line)
{
	if (ft_strcmp(line, "##start") == 0)
		return (1);
	else if (ft_strcmp(line, "##end") == 0)
		return (2);
	return (0);
}

int			ft_valid_room(char *line)
{
	int	space_count;

	space_count = 0;
	while (*line == ' ')
		line++;
	while (*line != ' ' && *line)
		line++;
	(*line == ' ') ? space_count += 1 : 0;
	if (*line != '\0')
		line++;
	else
		return (0);
	(*line == '-') ? line++ : 0;
	while (*line && ft_isdigit(*line))
		line++;
	(*line == ' ') ? space_count += 1 : 0;
	if (*line != '\0')
		line++;
	else
		return (0);
	(*line == '-') ? line++ : 0;
	while (*line && ft_isdigit(*line))
		line++;
	if (*line == '\0' && space_count == 2)
		return (1);
	return (0);
}

static int	check_room_name(char *str1, t_room_l *room_lst)
{
	while (room_lst)
	{
		if (ft_strcmp(str1, room_lst->name) == 0)
			return (1);
		room_lst = room_lst->next;
	}
	return (0);
}

static int	check_double_link(char *start, char *end, t_link_l *link_lst)
{
	t_link_l *lst;

	lst = link_lst;
	while (lst)
	{
		if (ft_strcmp(start, lst->start) == 0 && ft_strcmp(end, lst->end) == 0)
			return (0);
		if (ft_strcmp(start, lst->end) == 0 && ft_strcmp(end, lst->start) == 0)
			return (0);
		lst = lst->next;
	}
	return (1);
} 

int			ft_valid_link(char *line, t_room_l *room_lst, t_link_l *link_lst)
{
	int		i;
	char	*start;
	char	*end;

	i = 0;
	while (line[i] != '-' && line[i] != '\0')
		i++;
	start = ft_strsub(line, 0, i);
	while (i-- > 0)
		line++;
	*line == '-' ? line++ : 0;
	i = 0;
	while (line[i] != '\0')
		i++;
	end = ft_strsub(line, 0, i);
	if (check_room_name(start, room_lst) && check_room_name(end, room_lst)
		&& check_double_link(start, end, link_lst))
		i = (ft_strcmp(start, end) == 0) ? 0 : 1;
	else
		i = 0;
	free(start);
	free(end);
	return (i);
}
