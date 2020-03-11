/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nex_line.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:14:33 by jhakala           #+#    #+#             */
/*   Updated: 2019/11/24 20:56:04 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include "libft.h"
# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 17

int		get_next_line(const int fd, char **line);

#endif
