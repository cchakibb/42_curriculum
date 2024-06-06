/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:52:12 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/06 14:52:13 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "so_long.h"

void	find_error(t_vars *vars, char **ar)
{
	char	*next_line;
	char	**temp;
	int		fd;

	fd = open(ar[1], O_RDONLY);
	if (fd < 0)
		error("Error : No such map\n", NULL, -1);
	ft_strcmp(ar[1] + (ft_strlen(ar[1]) - 4));
	vars->map.data.c = 0;
	vars->map.data.e = 0;
	vars->map.data.p = 0;
	vars->map.data.o = 0;
	vars->map.data.collected = 0;
	vars->map.data.count = 0;
	vars->map.data.num_nextline = 0;
	vars->player_moves = 0;
	next_line = get_next_line(fd);
	while (!next_line)
		error("Error : Map is empty", next_line, -1);
	check_rectangle(&vars->map, next_line, fd);
	if (vars->map.data.count * SIZE >= 1920 || \
			vars->map.data.num_nextline * SIZE >= 1080)
		error("Error\n : Map size is big\n", NULL, -1);
	makemap(ar, &vars->map.data, vars);
	path_check(vars);
}

void	position_player(int x, int y, t_vars *vars, char *line)
{
	vars->map.grid[y][x] = line[x];
	if (vars->map.grid[y][x] == 'P')
	{
		vars->player.px_x = x;
		vars->player.px_y = y;
	}
}

void	makemap(char **ar, t_mapdata *data, t_vars *vars)
{
	int		i;
	int		j;
	int		fd;
	char	*line;

	j = 0;
	fd = open(ar[1], O_RDONLY);
	line = get_next_line(fd);
	vars->map.grid = malloc((data->num_nextline + 1) * sizeof(char *));
	vars->map.grid[data->num_nextline] = NULL;
	while (line)
	{
		i = 0;
		vars->map.grid[j] = malloc((data->count + 1) * sizeof(char));
		while (line[i] != '\n' && line[i] != '\0')
		{
			position_player(i, j, vars, line);
			i ++;
		}
		vars->map.grid[j][i] = '\0';
		free(line);
		line = get_next_line(fd);
		j ++;
	}
	close(fd);
}

void	check_rectangle(t_map *map, char *next_line, int fd)
{
	char	*temp;
	int		i;

	while (next_line)
	{
		check_recterror(map, next_line, fd);
		temp = get_next_line(fd);
		i = 0;
		while (!temp && next_line[i] != '\0' && next_line[i] != '\n')
		{
			if (next_line[i] != '1')
				error("Error: map should be walled properly", next_line, fd);
			i ++;
		}
		free(next_line);
		next_line = temp;
		map->data.num_nextline ++;
	}
	if (map->data.e != 1 || map->data.p != 1 || \
			map->data.c < 1 || map->data.o > 0)
		error("Error\n : map(1-E,1-P,C>1,1,0 no other char) )\n", next_line, fd);
}

void	check_recterror(t_map *map, char *next, int fd)
{
	int	i;

	i = 0;
	while (next[i] != '\n' && next[i] != '\0')
	{
		if (next[0] != '1' || (map->data.num_nextline == 0 && next[i] != '1'))
			error ("Error: Map is not walled", next, fd);
		if (next[i] == 'E')
			map->data.e ++;
		if (next[i] == 'P')
			map->data.p ++;
		if (next[i] == 'C')
			map->data.c ++;
		if (next[i] != 'E' && next[i] != 'P' && next[i] != 'C' && \
				next[i] != '1' && next[i] != '0')
			map->data.o ++;
		i ++;
	}
	if (next[i - 1] != '1')
		error("Error: Map is not walled", next, fd);
	if (map->data.count == 0)
		map->data.count = i;
	if (map->data.count != i)
		error("Error: Map is not rectangle", next, fd);
}
