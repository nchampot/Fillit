/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 22:19:32 by nchampot          #+#    #+#             */
/*   Updated: 2016/09/16 05:48:06 by nchampot         ###   ########.fr       */
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
# define T_LEFT 142
# define T_DOWN 27
# define LR_DOWN 165
# define LL_DOWN 170
# define LL_UP 139
# define LR_UP 39
# define LR_LDOWN 23
# define LR_RDOWN 83
# define LR_LUP 92
# define LR_RUP 77
# define ZR_UP 75
# define ZL_UP 141
# define ZR_DOWN 30
# define ZL_DOWN 46
# define LINE_UP 531
# define LINE_DOWN 1061
# define SQUARE 15


typedef struct	s_pos
{
	int	x;
	int	y;
	char	l;
}				t_pos;


t_pos	**import_file(char *file_name);
t_pos	check_all(char **grid, t_pos *fig);
int	fill_this(char	***grid, t_pos *figure);
int	get_min(char **grid);
t_pos	*import_fig(int letter, char *map);
t_pos	new_pos(int i, int j, char letter);
void	show_grid(char **grid);
char	**get_grid(t_pos **tetriminos);
char	**init_grid();

int	**g_cellval;

#endif
