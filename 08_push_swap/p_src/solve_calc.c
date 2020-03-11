/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 19:39:22 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/02 21:54:49 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void		rotate(int direction, int steps, t_mem *mem)
{
	if (direction == 5)
	{
		while (steps-- > 0)
			cmd_ra(mem);
	}
	else if (direction == 8)
	{
		while (steps-- > 0)
			cmd_rra(mem);
	}
	else if (direction == 6)
	{
		while (steps-- > 0)
			cmd_rb(mem);
	}
	else if (direction == 9)
	{
		while (steps-- > 0)
			cmd_rrb(mem);
	}
}

static void	make_best_move(t_nb *nb, t_mem *mem)
{
	int dir_a;
	int dir_b;

	dir_a = (nb->type == 1) ? 5 : 0;
	dir_b = (nb->type == 1) ? 6 : 0;
	(nb->type == 2) ? dir_a = 8 : 0;
	(nb->type == 2) ? dir_b = 9 : 0;
	(nb->type == 3) ? dir_a = 5 : 0;
	(nb->type == 3) ? dir_b = 9 : 0;
	(nb->type == 4) ? dir_a = 8 : 0;
	(nb->type == 4) ? dir_b = 6 : 0;
	while (nb->a_move > 0 || nb->b_move > 0)
	{
		if (nb->a_move-- > 0)
			rotate(dir_a, 1, mem);
		if (nb->b_move-- > 0)
			rotate(dir_b, 1, mem);
	}
	cmd_pa(mem);
}

void		ft_calc_best_nb(t_mem *mem)
{
	int		i;
	int		a_i;
	t_nb	*nb;

	i = 0;
	a_i = 0;
	if (!(nb = (t_nb*)ft_memalloc(sizeof(t_nb))))
		ft_error("calc_best_nbError\n");
	nb->best = 10000;
	while (i < mem->b_size)
	{
		a_i = ft_index_in_a(mem, mem->b[i]);
		nb = ft_distance(a_i, i, nb, mem);
		i++;
	}
	make_best_move(nb, mem);
	free(nb);
}

static void	change_nb_best(int type, int a_i, int b_i, t_nb *nb)
{
	nb->type = type;
	nb->a_move = a_i;
	nb->b_move = b_i;
}

t_nb		*ft_distance(int a_i, int b_i, t_nb *nb, t_mem *mem)
{
	int one;
	int two;
	int three;
	int four;

	one = (a_i > b_i ? a_i : b_i);
	two = (mem->a_size - a_i > mem->b_size - b_i ? mem->a_size - a_i :
	mem->b_size - b_i);
	three = a_i + (mem->b_size - b_i);
	four = mem->a_size - a_i + b_i;
	(one < nb->best) ? change_nb_best(1, a_i, b_i, nb) : 0;
	nb->best = (one < nb->best) ? one : nb->best;
	(two < nb->best) ? change_nb_best(2, mem->a_size - a_i, mem->b_size -
	b_i, nb) : 0;
	nb->best = (two < nb->best) ? two : nb->best;
	(three < nb->best) ? change_nb_best(3, a_i, mem->b_size - b_i, nb) : 0;
	nb->best = (three < nb->best) ? three : nb->best;
	(four < nb->best) ? change_nb_best(4, mem->a_size - a_i, b_i, nb) : 0;
	nb->best = (four < nb->best) ? four : nb->best;
	return (nb);
}
