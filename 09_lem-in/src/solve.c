/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:24:35 by jhakala           #+#    #+#             */
/*   Updated: 2020/03/11 19:07:19 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	copy_visited(int j, t_mem *mem)
{
	int i;

	i = 1;
	while (i < mem->paths_len[j] - 1)
		toggle_bit(mem->visited, mem->paths[j][i++]);
}

//int		calc_flow(t_mem *mem)
//{


void	ft_solve(t_mem *mem)
{
	int i;
	int j;

	if (!(mem->paths = (int**)malloc(sizeof(int*) * 100000)))//mem->n_rooms)))
		ft_error("Error: paths_malloc\n");
	if (!(mem->paths_len = (int *)malloc(sizeof(int) * 100000)))//mem->n_rooms)))
		ft_error("Error: paths_len_malloc\n");
	j = -1;
	while (++j < mem->n_rooms)
	{
		if (get_bit(mem->dead_end, j) == 1)
			toggle_bit(mem->visited, j);
	}
	if (!(mem->tmp = (int **)malloc(sizeof(int*) * 1000000)))
		ft_error("Error: paths_tmp_malloc\n");
	if (!(mem->tmp[0] = (int *)malloc(sizeof(int) * mem->n_rooms)))
		ft_error("Error: paths_tmp[i]_malloc\n");
	ft_printf("start_id = %d, end_id = %d\n", mem->id_start, mem->id_end);
//	mem->max_len = mem->id_arr[mem->id_start]->to_end;
	i = 0;
	mem->tmp_id = 0;
	mem->same_paths = 0;
	mem->path_id = 0;
	if (i < mem->max_paths)
	{
		mem->n_paths = 0;
		ft_find_path(mem, mem->id_start, 0);
	}
	ft_printf("after2\n");
	print_routes(mem);
	ft_printf("mem->n_paths = %d\n", mem->n_paths);
}
