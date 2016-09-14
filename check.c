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

int		check(char **grid, t_pos *figure, int i, int j, int lower_val)
{
	int	k;
	int	value;

	k = 0;
	value = 0;
	while (!figure[k].is_last && value < lower_val)
	{
		if (grid[i + figure[k].x][j + figure[k].y] != '0')
			return (-1);
		value += cellval[i + figure[k].x][j + figure[k].y];
		k++;
	}
	return (value < lower_val ? value : -1);
}	

t_pos	check_all(char **grid, t_pos *figure)
{
	int 	i;
	int 	j;
	int 	tmp;
	int		max;

	i = get_min(grid);
	j = i;
	max = i + 10;
	while (i != max && j != max)
	{
		best_pos = checK(grid, figure, i, j, lower_val) != -1 ? new_pos(i, j) : best_pos;
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
			j++;
	}
	return (best_pos);
}

void	fill_this(char	***grid, t_pos *figure)
{
	static char	letter = 'A';
	int	i;
	t_pos best_pos;

	best_pos = check_all(*grid, figure);
	while (!figure[i].is_last)	
	{
		(*grid)[pos.x][pos.y] = letter;
		i++;
	}
	letter++;
}
