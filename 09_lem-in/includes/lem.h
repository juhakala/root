/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:27:11 by jhakala           #+#    #+#             */
/*   Updated: 2020/03/11 19:06:13 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H

# define FROM 0

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"

typedef struct		s_room_l
{
	char			*name;
	int				to_end;
	int				id;
	int				x;
	int				y;
	int				pos;//0 = normal, 1 = start, 2 = end
	int				visited;
	int				n_links;
	int				*link_arr;
	struct s_room_l	*next;
}					t_room_l;

typedef struct		s_link_l
{
	char			*start;
	char			*end;
	struct s_link_l	*next;
}					t_link_l;

typedef struct		s_ant
{
	int				n;
	int				path_id;
}					t_ant;

typedef struct		s_mem
{
	int				max_paths;
	int				max_len;
	int				stop;
	int				n_ants;
	int				n_rooms;
	int				n_paths;
	int				id_start;
	int				id_end;
	char			*visited;
	char			*dead_end;
	t_room_l		**id_arr;
	t_room_l		*room_lst;
	t_link_l		*link_lst;
	t_ant			**ant_arr;
	int				**paths;
	int				*paths_len;
	int				**tmp;
	int				tmp_id;
	int				path_id;
	int				same_paths;
	int				flow;
}					t_mem;

/*
**main.c
*/
void				ft_error(char *str);

/*
**init.c
*/
t_mem				*ft_init(t_mem *mem);
t_room_l			*ft_init_room(int pos, char *line, int id);
t_link_l			*ft_init_link(char *line);
void				ft_init_visit_dead(t_mem *mem, int size);
void				ft_init_ants(t_mem *mem);

/*
**read.c and revers_lists.c
*/
void				ft_read_info(t_mem *mem);
void				reverse_room_list(t_mem *mem);
void				reverse_link_list(t_mem *mem);

/*
**valid.c
*/
int					ft_get_comment(char *line);
int					ft_valid_room(char *line);
int					ft_valid_link(char *line, t_room_l *room_lst, t_link_l *link_lst);

/*
**valid_info.c
*/
void				ft_validate_info(t_mem *mem);

/*
**make_links.c
*/
void				ft_make_links(t_mem *mem);

/*
**bit.c
*/
void				toggle_bit(char *arr, int i);
char				get_bit(char *arr, int i);
int					ft_trim(t_mem *mem);
void				print_bits(char *arr, t_mem *mem);

/*
**find_steps.c
*/
void				ft_find_steps(t_mem *mem);

/*
**set_steps.c
*/
int					ft_set_steps(t_mem *mem, int id, int parent);
void				ft_sort_room_link_arrs(t_mem *mem);

/*
**delete these
*/
void	print_steps(t_mem *mem);//set_steps.c
void    print_routes(t_mem *mem);//find_path.c
void    print_links(t_mem *mem);//find_path.c

/*
**solve.c
*/
void				ft_solve(t_mem *mem);

/*
**find_path.c
*/
int					ft_find_path(t_mem *mem, int id, int j);

#endif
