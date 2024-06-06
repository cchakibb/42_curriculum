/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:52:20 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/06 14:52:21 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




void	path_check(t_vars *vars)
{
	char	**temp;
	int		j;
	int		i;

	j = 0;
	temp = create_copymap(vars);
	path_exist(vars->player.px_y, vars->player.px_y, vars, temp);
	while (j < vars->map.data.num_nextline)
	{
		i = 0;
		while (i < vars->map.data.count)
		{
			if (temp[j][i] != '0' && temp[j][i] != '1') 
				error_notplayable("Error : Not playable", temp, vars->map.grid);
			i ++;
		}
		j ++;
	}
	j = 0;
	while (temp[j])
	{
		free(temp[j]);
		j ++;
	}
	free(temp);
}

void	error_notplayable(char *str, char **temp, char **grid)
{
	int	j;

	j = 0;
	write (1, str, ft_strlen(str));
	while (temp && temp[j])
		free(temp[j++]);
	free(temp);
	j = 0;
	while (grid && grid[j])
		free(grid[j++]);
	free(grid);
	exit (1);
}

char	**create_copymap(t_vars *vars)
{
	char	**temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = malloc ((vars->map.data.num_nextline + 1) * sizeof(char *));
	temp[vars->map.data.num_nextline] = NULL;
	while (j < vars->map.data.num_nextline)
	{
		i = 0;
		temp[j] = malloc ((vars->map.data.count + 1) * sizeof(char));
		while (i < vars->map.data.count)
		{
			temp[j][i] = vars->map.grid[j][i];
			i++;
		}
		temp[j][i] = '\0';
		j ++;
	}
	return (temp);
}

void	path_exist(int px_y, int px_x, t_vars *vars, char **temp)
{
	if ((px_y > vars->map.data.num_nextline - 1) || \
			(px_x > vars->map.data.count - 1) \
			|| (px_x < 0) || (px_y < 0) || \
			(vars->map.grid[px_y][px_x] == '1') || \
			(vars->map.grid[px_y][px_x] == '1') || \
			(temp[px_y][px_x] == '1'))
		return ;
	temp[px_y][px_x] = '1';
	path_exist(px_y, px_x + 1, vars, temp);
	path_exist(px_y, px_x - 1, vars, temp);
	path_exist(px_y + 1, px_x, vars, temp);
	path_exist(px_y - 1, px_x, vars, temp);
}

void	error(char *str, char *next_line, int fd)
{
	write(1, str, ft_strlen(str));
	while (next_line && fd > -1)
	{
		free(next_line);
		next_line = get_next_line(fd);
	}
	if (fd > -1)
		close (fd);
	exit(1);
}
