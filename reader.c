#include "fillit.h"
#include "fcntl.h"

t_pos	**ft_puterror(char *msg)
{
	ft_putendl_fd(msg, 2);
	return (NULL);
}

static int	nb_line(char *file_name)
{
	char	*buf;
	int	i;
	int	fd;

	i = 1;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (1);
	while (get_next_line(fd, &buf))
		i++;
	close(fd);
	return (i);
}

t_pos	**transform(char **tetriminos)
{
	t_pos	**new;
	int	i;

	i = 0;
	while (tetriminos[i])
		i++;	
	new = malloc(sizeof(t_pos*) * i);
	i = 0;
	while (tetriminos[i])
	{
		new[i] = import_fig(i, tetriminos[i]);;	
		i++;
	}
	new[i] = NULL;
	return (new);
}

t_pos	**import_file(char *file_name)
{
	char	*buf;
	char	**tetriminos;
	int	i;
	int	fd;

	i = 0;
	tetriminos = malloc(sizeof(char*) * nb_line(file_name));
	*tetriminos = malloc(16);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (ft_puterror("ERROR: WRONG FILE NAME"));
	while (get_next_line(fd, &buf))
	{
		if (ft_strlen(buf) == 4)
		{
			tetriminos[i] = ft_strcat(tetriminos[i], buf);
			if (ft_strlen(tetriminos[i]) == 16)
			{
				if (!(get_next_line(fd, &buf)))
				{
					close(fd);
					return (transform(tetriminos));
				}
				else if (buf)
					tetriminos[++i] = malloc(16);
			}
			continue;
		}
		return (ft_puterror("ERROR: WRONG FILE FORMAT"));
	}
	return (ft_puterror("ERROR: EMPTY FILE"));
}


t_pos	get_max(char **grid)
{
	int	i;
	int	j;
	t_pos	max;

	i = 0;
	j = 0;
	max.x = 0;
	max.y = 0;
	while (i < 60)
	{
		j = 0;
		while (j < 60)
		{
			if (grid[i][j] != '0' && grid[i][j + 1] == '0' && grid[i][j + 2] == '0')
			{
				max.x = max.x > i ? max.x : i;
				max.y = max.y > j ? max.y : j;
			}
			j++;
		}
		i++;
	}
	return (max);
}

int	nb_colision(t_pos *tet, char **grid)
{
	t_pos	pos;
	int	nb_colision;
	int	x;
	int	y;
	int	i;

	pos = check_all(grid, tet);/////////////////////check_all renvoie la position de lautre algo	
	i = 0;
	nb_colision = 0;
	while (i < 4)
	{
		x = pos.x + tet[i].x;
		y = pos.y + tet[i].y;
		if (x == 0)
			nb_colision++;
		else if (grid[x - 1][y] != '0')
			nb_colision++;
		if (y == 0)
			nb_colision++;
		else if (grid[x][y - 1] != '0')
			nb_colision++;
		if (grid[x + 1][y] != '0')
			nb_colision++;
		if (grid[x][y + 1] != '0')
			nb_colision++;
		i++;
	}
	return (nb_colision);
}

char	**get_grid(t_pos **tetriminos)
{
	char	**grid;
	int	n;
	int	i;
	int	j;
	int	best_tet;
	int	highest_nbcol;;
	int	tmp;

	n = 0;
	grid = init_grid();
	while (tetriminos[n])
		n++;
	j = 0;
	while (j < n)
	{
		highest_nbcol = 0; 
		best_tet = -1; 
		i = 0;
		while (i < n)
		{
			//printf("%d\n",nb_colision(tetriminos[i], grid));
			if ((tmp = nb_colision(tetriminos[i], grid)) > highest_nbcol && tetriminos[i][0].l != 'r')
			{
				highest_nbcol = tmp; 
				best_tet = i;
			}
			i++;
		}
		j++;
		//new[j] = tetriminos[i];;
		if (best_tet != -1)
		{
			fill_this(&grid, tetriminos[best_tet]);
			tetriminos[best_tet][0].l = 'r';
		}
	}
	return (grid);
}
	
void	show_grid(char **grid)
{
	int	i;
	int	j;
	t_pos	max;

	i = 0;
	max = get_max(grid);
	while (i < max.x + 1)
	{
		j = 0;
		while (j < max.y + 1)
		{
			if (grid[i][j] == '0')
				ft_putchar('.');
			else
				ft_putchar(grid[i][j]);
			j++;
		}
		i++;
		if (i < max.x + 1)
			ft_putchar('\n');
	}
}
