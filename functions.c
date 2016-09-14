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

int	is_not_known(t_pos *figure)
{
	int	value;

	value = get_value(figure);
	return (!(value == T_UP || value == T_RIGHT || value == T_LEFT\
			|| value == T_DOWN || value == LR_UP || value LR_DOWN));
}

int	get_value(t_pos *figure)
{
	int	i;
	int	value;

	i = 0;
	value = 0;
	while (!figure[i].is_last)
		value += cellval[figure[i].x, figure[i++].y];
	return (value);
}

int	get_min(char **grid)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	while (i != max && j != max && grid[i][j] == '0')
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
