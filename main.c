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

#include "fillit.h"

static int	**create_int_tab(int rows, int cols)
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

static int	**init_values(void)
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

static char	**init_grid()
{
	int		i;
	int		j;
	char	**grid;

	i = 0;
	grid = malloc(sizeof(char*) * 60);
	while (i < 60)
	{
		grid[i] = malloc(sizeof(char) * 60);
		i++;
	}
	i = 0;
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


int	main(int ac, char **av)
{
	char	**grid;
	int		i;
	int		j;
	char	**tetriminos;

	i = 0;
	if (ac != 2)
	{
		ft_putendl_fd(USAGE, 2);
		return (0);
	}
	g_cellval = init_values();
	grid = init_grid();
	if ((tetriminos = import_file(av[1])) == NULL)
		return (0);
	while (tetriminos[i])
	{
	ft_putendl("test0");
		if (fill_this(&grid, import_fig(tetriminos[i])) == 0)
		{
			ft_putendl_fd("an error occured while filling tretriminos GL HF XD", 2);
			return (0);
		}
		i++;
	}
	return (0);
}
