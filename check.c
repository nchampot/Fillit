/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchampot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 22:15:33 by nchampot          #+#    #+#             */
/*   Updated: 2016/09/14 00:21:40 by nchampot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_pos	check(char **grid, t_pos *figure, int i, int j)
{
	if (is_not_known(figure))
		return (NULL);
}	

t_pos	check_all(char **grid, t_pos *figure)
{
	unsigned int 	i;
	unsigned int 	j;
	unsigned int 	tmp;
	unsigned int	max;
	t_pos			best_pos;

	i = 0;
	j = 0;
	max = get_max(grid);
	while (i != max || j != max)
	{
		best_pos = checK(grid, figure, i, j);
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
