/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 22:19:32 by nchampot          #+#    #+#             */
/*   Updated: 2016/09/14 05:50:14 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdio.h>
#include <stdlib.h>
#include "libft/inc/libft.h"

# define USAGE "usage: fillit file"
/*
** FIGURE VALUES
*/
# define T_UP 78
# define T_RIGHT 45


typedef struct	s_pos
{
	int	x;
	int	y;
}				t_pos;


char	**import_file(char *file_name);
int	fill_this(char	***grid, t_pos *figure);
int	get_min(char **grid);
t_pos	*import_fig(char *map);
t_pos	new_pos(int i, int j);

int	**g_cellval;

#endif
