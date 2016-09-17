/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 01:52:27 by nchampot          #+#    #+#             */
/*   Updated: 2016/09/16 05:48:55 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <math.h>

static int	get_value(t_pos *figure)
{
	int	i;
	int	value;

	i = 0;
	value = 0;
	while (i < 4)
	{
		value += pow(2, g_cellval[figure[i].x][figure[i].y]);
		i++;
	}
	return (value);
}

static int	is_known(t_pos *figure)
{
	int	value;

	value = get_value(figure);
	return (value == T_UP || value == T_RIGHT || value == T_LEFT ||\
			value == T_DOWN || value == LR_UP || value == LR_DOWN ||\
			value == LL_DOWN || value == LL_UP || value == ZR_DOWN ||\
			value == SQUARE || value == ZR_UP || value == LINE_UP ||\
			value == LINE_DOWN || value == LR_RDOWN ||\
			value == LR_LDOWN || value == LR_RUP || value == LR_LUP\
			|| value == ZL_DOWN || value == ZL_UP);
}

int	get_min(char **grid)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	while (i != 60 && j != 60 && grid[i][j] == '0')
	{
		if (i == j)
		{
			i = 0;
			j++;
		}
		else if (j > i)
		{
			tmp = j;
			j = i;
			i = tmp;
		}
		else
		{
			j++;
			if (j != i)
			{
				tmp = i;
				i = j;
				j = tmp;
			}
		}
	}
	return (i > j ? j : i);
}

t_pos	new_pos(int i, int j, char letter)
{
	t_pos pos;

	pos.x = i;
	pos.y = j;
	pos.l = letter;
	return (pos);
}

static t_pos	*push(t_pos *fig)
{
	t_pos	*new;
	int	i;
	int	min_x;
	int	min_y;

	new = malloc(sizeof(t_pos) * 4);
	min_x = fig[0].x;
	min_y = fig[0].y;
	i = 1;
	while (i < 4)
	{
		min_x = min_x < fig[i].x ? min_x : fig[i].x; 
		min_y = min_y < fig[i].y ? min_y : fig[i].y; 
		i++;
	}
	i = 0;
	while (i < 4)
	{
		new[i].x = fig[i].x - min_x;
		new[i].y = fig[i].y - min_y;
		new[i].l = fig[i].l;
		i++;
	}
	return (is_known(new) ? new : NULL);
}

static t_pos	*re_order(t_pos *fig)
{
	t_pos	*new;
	int	i;
	int	j;
	int	k;
	int	n;
	int	tmp;

	n = 0;
	i = 0;
	k = 0;
	j = 0;
	new = malloc(sizeof(t_pos) * 4);
	while (i < 4 && j < 4)
	{
		k = 0;
		while (k < 4)
		{
			if (fig[k].x == i && fig[k].y == j)
			{
				new[n++] = new_pos(fig[k].x, fig[k].y, fig[k].l);
				fig[k].x = -1;
				fig[k].y = -1;
			}
			k++;
		}
		if (i == j)
		{
			i = 0;
			j++;
		}
		else if (j > i)
		{
			tmp = j;
			j = i;
			i = tmp;
		}
		else
		{
			j++;
			if (j != i)
			{
				tmp = i;
				i = j;
				j = tmp;
			}
		}
	}
	return (push(new));
}

t_pos	*import_fig(int letter, char *map)
{
	int	i;
	int	j;
	int	x;
	int	k;
	int	tmp;
	t_pos	*fig;

	i = 0;
	j = 0;
	k = 0;
	x = 0;
	fig = malloc(sizeof(t_pos) * 4);
	while (map[k])
	{
		if (map[k] != '.' && map[k] != '#' && map[k] != '\n')
			return (NULL);
		if (map[k] == '#')
			fig[x++] = new_pos(j, i, (char)(letter + 65));
		if ((k + 1) % 4 == 0)
		{
			j++;
			i = 0;
		}
		else
			i++;
		k++;
	}
	return (re_order(fig));
}
