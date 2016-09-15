/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 22:15:33 by nchampot          #+#    #+#             */
/*   Updated: 2016/09/14 06:14:26 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check(char **grid, t_pos *figure, int i, int j)
{
	int	k;
	int	value;

	k = 0;
	value = 0;
	while (k < 4)
	{
		if (grid[i + figure[k].x][j + figure[k].y] != '0')
			return (-1);
		value += g_cellval[i + figure[k].x][j + figure[k].y];
		k++;
	}
	return (value);
}	

static t_pos	check_all(char **grid, t_pos *figure)
{
	int 	i;
	int 	j;
	int 	tmp;
	int		max;
	int	lower_val;
	t_pos	best_pos;

	i = get_min(grid);
	j = i;
	max = i + 10;
	while (i != max && j != max)
	{
		if ((tmp = check(grid, figure, i, j)) < lower_val && tmp >= 0)
		{
			lower_val = tmp;
			best_pos = new_pos(i, j);
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
	return (best_pos);
}

int	fill_this(char	***grid, t_pos *fig)
{
	static char	letter = 'A';
	int	i;
	t_pos pos;

	if (fig == NULL)
		return (0);
	ft_putendl("test300");
	pos = check_all(*grid, fig);
	ft_putendl("test301");
	while (i < 4)	
	{
		(*grid)[pos.x + fig[i].x][pos.y + fig[i].y] = letter;
		i++;
	}
	letter++;
	return (1);
}
