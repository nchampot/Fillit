#include "fillit.h"
#include "fcntl.h"

char	**ft_puterror(char *msg)
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

char	**import_file(char *file_name)
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
					return (tetriminos);
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
