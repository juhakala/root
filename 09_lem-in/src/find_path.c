/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:44:46 by jhakala           #+#    #+#             */
/*   Updated: 2020/03/11 20:57:25 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	print_links(t_mem *mem)
{
	int i;
	int j;
	t_room_l *room;

	i = 0;
	while (i < mem->n_rooms)
	{
		room = mem->id_arr[i];
		j = 0;
		ft_printf("room id = %d\n", room->id);
		while (j < room->n_links)
			ft_printf("	->%d\n", room->link_arr[j++]);
		i++;
	}
}

void	print_dead_bits(char *arr, t_mem *mem, int j)
{
	int i;
	int count = 0;

	i = 0;
	while (i < mem->n_rooms)
	{
		if (get_bit(arr, i) == 1)
			count++;
//			ft_printf("id = %d, i = %d\n", mem->id_arr[i]->id, i);
		i++;
	}
	ft_printf("count + j = %d, n_rooms = %d\n", count + j, mem->n_rooms);
}

void	print_tmp(int *arr, int j)
{
	int i;

	i = 0;
	ft_printf("new =	");
	while (i < j)
		ft_printf("%d, ", arr[i++]);
	ft_printf("\n");
}

void	print_routes(t_mem *mem)
{
	int i;
	int j;

	i = 0;
	ft_printf("start_id = %d, end_id = %d\n", mem->id_start, mem->id_end);
	while (i < mem->n_paths)
	{
		j = 0;
		ft_printf("len = %d, i = %d	", mem->paths_len[i], i);
		while (j < mem->paths_len[i])// && j < 20)
//			ft_printf("%s, ", mem->id_arr[mem->paths[i][j++]]->name);
			ft_printf("%d, ", mem->id_arr[mem->paths[i][j++]]->id);
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

int		save_route(t_mem *mem, int j)
{
	int k;

	if (!(mem->paths[mem->n_paths] = (int *)malloc(sizeof(int) * (j))))
		ft_error("Error: paths[i]_malloc\n");
	k = 0;
	mem->paths_len[mem->n_paths] = j;
	while (k < j)
	{
		mem->paths[mem->n_paths][k] = mem->tmp[mem->tmp_id][k];
		k++;
	}
	mem->paths[mem->n_paths][0] = mem->tmp_id;
	print_tmp(mem->tmp[mem->tmp_id], j);
	mem->n_paths++;
	mem->tmp_id++;
//	print_routes(mem);
	if (!(mem->tmp[mem->n_paths] = (int *)malloc(sizeof(int) * mem->n_rooms)))
        ft_error("Error: paths_tmp[i]_malloc\n");
	k = 0;
	while (k < j)
	{
		mem->tmp[mem->tmp_id][k] = mem->tmp[mem->tmp_id - 1][k];
		k++;
	}
	if (mem->tmp_id > mem->same_paths)
		mem->same_paths = mem->tmp_id;
	ft_find_path(mem, mem->id_start, 0);
//	ft_printf("mem->tmp_id = %d\n", mem->tmp_id);
	mem->tmp_id--;
	mem->path_id++;
//	ft_printf("\n");
	return (j);
}

int		ft_find_path(t_mem *mem, int id, int j)
{
	t_room_l *room = NULL;
	int k;
	int res;
	int tmp;

	if (j > mem->max_len || mem->max_paths == mem->same_paths)
		return (-1);
	ft_printf("fp->  tmp id = %d, j = %d\n", id, j);
	room = mem->id_arr[id];
	mem->tmp[mem->tmp_id][j] = room->id;
	if (room->id == mem->id_end)
		return (save_route(mem, j + 1));
	k = 0;
	toggle_bit(mem->visited, id);
	res = -1;
	while (k < room->n_links)
	{
		if (get_bit(mem->visited, room->link_arr[k]) == 0 && room->link_arr[k] != mem->id_start)
		{
			if ((tmp = ft_find_path(mem, room->link_arr[k], j + 1)) != -1)
				res = tmp + 1;
		}
		k++;
	}
	toggle_bit(mem->visited, id);
	return (res);
}

//laske maksimi mahdolliset reitit sulkemalla aina yksi kyseiselta reitita ja katsomalla while_possible funcktiolla onko mahdollista, jos mahdollista niin sitten taas seuraava reitti yksi sulkemalla aina
//katso etta 
//tarkista myos validointi


//lasketaan sittenkin onko enaa kannattavaa etsia uusia reitteja niiden pituuden ja j:n pituuden ja muurahaisten maarasta riippuen ja myos maksimi reiteista riippuen, jotka saadaan alun ja lopun linkeista, ja jostain muusta jos saadaan pullonkaulat laskettu
