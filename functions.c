/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 01:52:27 by nchampot          #+#    #+#             */
/*   Updated: 2016/09/14 06:14:27 by nchampot         ###   ########.fr       */
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
	return (!(value == T_UP || value == T_RIGHT));/* || value == T_LEFT\
			|| value == T_DOWN || value == LR_UP || value == LR_DOWN));*/
}

int	get_min(char **grid)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	while (i != 60 && j != 60 && grid[i][j] != '0')
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

t_pos	new_pos(int i, int j)
{
	t_pos pos;

	pos.x = i;
	pos.y = j;
	return (pos);
}

static t_pos	*push(t_pos *fig)
{
	t_pos	*new;
	int	i;
	int	min_x;
	int	min_y;

	i = 0;
	min_x = fig[0].x;
	min_y = fig[0].y;
	while (i < 4)
	{
		min_x = min_x < fig[i].x ? min_x : fig[i].x; 
		min_y = min_y < fig[i].y ? min_y : fig[i].y; 
		i++;
	}
	i = 0;
	while (i < 4)
	{
		fig[i].x = fig[i].x - min_x;
		fig[i].y = fig[i].y - min_y;
		i++;
	}
	ft_putendl("test30");
	return (is_known(fig) ? fig : NULL);
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
	while (i != 3 && j != 3 && n < 4)
	{
		k = 0;
		while (k < 4)
		{
			if (fig[k].x == i && fig[k].y == j)
				new[n++] = new_pos(i, j);
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

t_pos	*import_fig(char *map)
{
	int	i;
	int	j;
	int	x;
	int	k;
	int	tmp;
	int	is_correct;
	t_pos	*fig;

	i = 0;
	j = 0;
	k = 0;
	x = 0;
	ft_putendl("test200");
	is_correct = 0;
	fig = malloc(sizeof(t_pos) * 4);
	while (map[k])
	{
		if (map[k] != '.' && map[k] != '#' && map[k] != '\n')
			return (NULL);
		if ((k + 1) % 4 == 0)
		{
			j++;
			i = 0;
			k++;
			continue;
		}
		if (map[k] == '#')
		{
			fig[x++] = new_pos(i, j);
			if (!is_correct && (i == 0 || j == 0 || i == 4 ||  j == 4))
				is_correct++;
		}
		i++;
		k++;
	}
	return ((is_correct) ? re_order(fig) : NULL);
}
