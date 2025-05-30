/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:02:52 by stobin            #+#    #+#             */
/*   Updated: 2025/05/16 20:27:36 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_map_line(char *line)
{
	while (*line == ' ')
		line++;
	return (*line == '1' || *line == '0');
}

static int	parse_line(char *line, t_game *game)
{
	if (is_texture_line(line))
		return (parse_texture_line(line, game));
	else if (is_colour_line(line))
		return (parse_colour_line(line, game));
	else if (*line == '\0' || *line == '\n')
		return (0);
	else if (is_map_line(line))
		return (parse_map_line(line, game));
	else
	{
		ft_putstr_fd("Error\nInvalid line in file\n", 2);
		return (-1);
	}
}

int	is_map_ok(char *line, int new_line, int *map_started, int *gap)
{
	if (!*map_started)
		*map_started = is_map_line(line);
	if (*map_started && ((new_line && *gap)
			|| (!is_map_line(line) && *line != '\n')))
	{
		ft_putstr_fd("Error\nMap is not contiguous or non-final\n", 2);
		return (-1);
	}
	return (0);
}

int	line_loop(int fd, char *line, t_game *game)
{
	int	map_started;
	int	new_line;
	int	status;
	int	gap;

	map_started = 0;
	new_line = 0;
	gap = 0;
	while (line)
	{
		status = is_map_ok(line, new_line, &map_started, &gap);
		if (status != 0)
			return (dump_lines(fd, line));
		status = parse_line(line, game);
		new_line = (map_started && line[ft_strlen(line) - 1] == '\n');
		gap = map_has_gap(line, new_line);
		if (status < 0)
			return (dump_lines(fd, line));
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

// Main function to parse the .cub file.
// we open the file, read it line by line, dispatch parsing tasks
// for textures, colors, and the map. we also perform final validation checks.
int	parse_cub_file(char *filename, t_game *game)
{
	int		fd;
	int		len;
	char	*line;

	len = ft_strlen(filename);
	if (no_cub_extension(len, filename))
		return (-1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (perror("Error\nCould not open .cub file"), -1);
	line = get_next_line(fd);
	if (line_loop(fd, line, game))
	{
		free_map_n_paths(&game->map, &game->textures);
		free_textures(game);
		close(fd);
		return (-1);
	}
	close(fd);
	if (find_spawn(game) < 0 || val_map_closed(game) < 0 || def_err(game) != 0)
	{
		free_map_n_paths(&game->map, &game->textures);
		return (-1);
	}
	return (0);
}
