/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 19:55:22 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/02 21:54:22 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"

typedef struct	s_mem
{
	int			*a;
	int			*b;
	int			*real;
	int			a_size;
	int			b_size;
	int			size;
	int			steps;
	int			last_cmd;
	int			now_cmd;
	int			mid_from;
}				t_mem;

typedef struct	s_nb
{
	int			type;
	int			a_move;
	int			b_move;
	int			best;
}				t_nb;

long long int	ft_atoi_mod(const char *str);
int				ft_solve(t_mem *mem);
void			ft_cmd(t_mem *mem);
void			ft_get_order(t_mem *mem);

/*
**stack.c
*/
t_mem			*ft_stack_init(t_mem *mem, int ac);
void			ft_get_stack(char **av, t_mem *mem);
void			ft_get_stack_arg(char **av, t_mem *mem);

/*
**utils.c
*/
void			ft_error(char *str);
int				ft_order(t_mem *mem);
int				ft_str_size(char **str);
int				ft_get_nb(int n, char delim, t_mem *mem);
void			ft_pick_first_last(t_mem *mem);

/*
**solve_utils.c
*/
int				ft_get_min_a(t_mem *mem);
int				ft_contains_lower(t_mem *mem, int mid);
int				ft_contains_higher(t_mem *mem, int mid);
void			rotate(int direction, int steps, t_mem *mem);

/*
**solve_calc.c
*/
void			rotate(int direction, int steps, t_mem *mem);
void			ft_calc_best_nb(t_mem *mem);
t_nb			*ft_distance(int a_i, int b_i, t_nb *nb, t_mem *mem);

/*
**solve_support.c
*/
void			ft_make_min_first(t_mem *mem);
int				ft_index_in_a(t_mem *mem, int nb);
int				ft_three_solve(t_mem *mem);

/*
**solvers
*/
int				ft_solve(t_mem *mem);
int				ft_small_solve(t_mem *mem);
int				ft_medium_solve(t_mem *mem);
int				ft_large_solve(t_mem *mem);

/*
** cmd
*/
int				cmd_sa(t_mem *mem);
int				cmd_sb(t_mem *mem);
int				cmd_ss(t_mem *mem);
int				cmd_pa(t_mem *mem);
int				cmd_pb(t_mem *mem);
int				cmd_ra(t_mem *mem);
int				cmd_rb(t_mem *mem);
int				cmd_rr(t_mem *mem);
int				cmd_rra(t_mem *mem);
int				cmd_rrb(t_mem *mem);
int				cmd_rrr(t_mem *mem);

#endif
