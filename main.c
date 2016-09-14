/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 23:15:57 by nchampot          #+#    #+#             */
/*   Updated: 2016/09/14 06:14:29 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int	**create_int_tab(int rows, int cols)
{
	int **tab;
	int i;

	tab = malloc(rows * sizeof(int*) + rows * cols * sizeof(int));
	i = 0;
	while (i < rows)
	{
		tab[i] = (int*)(tab + rows) + (i * cols);
		i++;
	}
	return (tab);
}

int	**init_values(void)
{
	int	i;
	int	j;
	int	value;
	int	tmp;
	int	**tab;

	i = 0;
	j = 0;
	value = 1;
	tab = create_int_tab(60, 60);
	while (i != 60 && j != 60)
	{
		tab[i][j] = value;
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
		value++;
	}
	return (tab);
}

char	**init_grid()
{
	int		i;
	int		j;
	char	**grid;

	i = 0;
	grid = malloc(sizeof(char*) * 60);
	*grid = malloc(sizeof(char) * 60);
	while (i < 60)
	{
		j = 0;
		while (j < 60)
		{
			grid[i][j] = '0';
			j++;
		}
		i++;
	}
	return (grid);
}

int	main(void)
{
	int		**cellval;
	char	**grid;
	int		i;
	int		j;

	i = 0;
	cellval = init_values();
	grid = init_grid();
	return (0);
}
