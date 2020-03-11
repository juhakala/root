/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:43:13 by jhakala           #+#    #+#             */
/*   Updated: 2019/12/19 17:03:15 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_xy_values(char *str, t_pos *min, t_pos *max)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i / 5) < min->y)
				min->y = i / 5;
			if ((i / 5) > max->y)
				max->y = i / 5;
			if ((i % 5) < min->x)
				min->x = i % 5;
			if ((i % 5) > max->x)
				max->x = i % 5;
		}
		i++;
	}
}

t_piece	*ft_piece(char *str, char c)
{
	int		i;
	t_pos	*min;
	t_pos	*max;
	t_piece	*piece;
	char	**pos;

	i = 0;
	min = ft_new_pos_xy(3, 3);
	max = ft_new_pos_xy(0, 0);
	ft_xy_values(str, min, max);
	pos = ft_memalloc(sizeof(char *) * (max->y - min->y + 1));
	while (i < max->y - min->y + 1)
	{
		pos[i] = ft_strnew(max->x - min->x + 1);
		ft_strncpy(pos[i], str + (min->x) + (i + min->y) * 5,
			max->x - min->x + 1);
		i++;
	}
	piece = ft_new_piece(pos, max->x - min->x + 1, max->y - min->y + 1, c);
	ft_memdel((void **)&min);
	ft_memdel((void **)&max);
	return (piece);
}

int		ft_check_connect(char *str)
{
	int i;
	int termi;

	termi = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (str[i - 1] == '#' && (i - 1) >= 0)
				termi++;
			if (str[i + 1] == '#' && (i + 1) < 20)
				termi++;
			if (str[i + 5] == '#' && (i + 5) < 20)
				termi++;
			if (str[i - 5] == '#' && (i - 5) >= 0)
				termi++;
		}
		i++;
	}
	if (termi != 6 && termi != 8)
		return (-1);
	return (0);
}

int		ft_check(char *str)
{
	int i;
	int h;

	h = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (str[i] != '#' && str[i] != '.')
				return (-1);
			if (str[i] == '#')
				h++;
		}
		else if (str[i] != '\n')
			return (-1);
		i++;
	}
	if (str[20] == '\n' && str[21] != '\0')
		return (-1);
	if (ft_check_connect(str) < 0 || h != 4)
		return (-1);
	return (0);
}

t_list	*ft_read2(t_list *lst, char *str, char c)
{
	t_piece		*piece;

	if (c > 'Z')
		return (NULL);
	if (ft_check(str) < 0 || (piece = ft_piece(str, c)) == NULL)
		return (NULL);
	ft_lstadd(&lst, ft_lstnew(piece, sizeof(t_piece)));
	ft_memdel((void **)&piece);
	return (lst);
}
