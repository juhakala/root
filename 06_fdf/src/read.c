/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:43:54 by jhakala           #+#    #+#             */
/*   Updated: 2019/12/04 19:42:53 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_pointadd(t_point **alst, t_point *new)
{
	if (alst)
	{
		if (new)
			new->next = *alst;
		*alst = new;
	}
}

t_point	*ft_newpoint(char *str)
{
	t_point	*point;
	int		i;

	if (!(point = (t_point *)ft_memalloc(sizeof(t_map))))
		ft_error("");
	i = ft_atoi(str);
	point->i = i;
	i = 0;
	point->color = -1;
	while (str[i] != '\0')
	{
		if (str[i] == ',' && str[i + 1] == '0' && str[i + 2] == 'x')
		{
			i = i + 3;
			point->color = ft_atoi_base(str + i, 16);
		}
		i++;
	}
	point->next = NULL;
	return (point);
}

void	ft_vali(char **arr, t_map *map, t_point **lst)
{
	int width;
	int i;

	i = 0;
	width = 0;
	while (*arr)
	{
		ft_pointadd(lst, ft_newpoint(*(arr++)));
		width++;
		map->count++;
	}
	if (map->height == 0)
		map->width = width;
	else if (map->width != width)
		ft_error("");
}

void	ft_read(char *av, t_map *map, t_point **lst)
{
	int		fd;
	char	*line;
	char	**arr;
	size_t	i;

	if ((fd = open(av, O_RDONLY)) < 0)
		ft_error("");
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		arr = ft_strsplit(line, ' ');
		ft_vali(arr, map, lst);
		while (arr[i])
			free(arr[i++]);
		free(arr);
		free(line);
		map->height++;
	}
}
