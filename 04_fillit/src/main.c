/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:32:53 by jhakala           #+#    #+#             */
/*   Updated: 2019/11/23 16:09:34 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_map_print(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			ft_putchar(map->table[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		ft_error(void)
{
	ft_putstr("error\n");
	return (-1);
}

t_list	*ft_read(int fd)
{
	int		count;
	char	*buf;
	t_list	*lst;
	char	c;
	int		i;

	i = 1;
	c = 'A';
	lst = NULL;
	buf = ft_strnew(21);
	while ((count = read(fd, buf, 21)))
	{
		i = 0;
		lst = ft_read2(lst, buf, c++);
		if (lst == NULL)
			return (NULL);
		if (count != 20 && count != 21)
			return (NULL);
		if (count == 21)
			i++;
	}
	ft_memdel((void **)&buf);
	if (i != 0)
		return (NULL);
	return (lst);
}

int		main(int ac, char **av)
{
	int		fd;
	t_list	*lst;
	t_map	*map;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (ft_error());
	lst = ft_read(fd);
	if (lst != NULL)
	{
		ft_lst_rev(&lst);
		map = ft_solve(lst);
		ft_map_print(map);
		ft_free_map(map);
	}
	else
		return (ft_error());
	ft_free_lst(lst);
	return (0);
}
