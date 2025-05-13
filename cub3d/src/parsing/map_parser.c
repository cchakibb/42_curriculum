/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:44:53 by stobin            #+#    #+#             */
/*   Updated: 2025/05/12 19:37:54 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_has_gap(char *line, int new_line)
{
	if (new_line && *line == '\n')
		return (1);
	return (0);
}

static int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == '\n'
		|| c == 'N' || c == 'E' || c == 'S' || c == 'W' || c == ' ');
}

static int	validate_line_chars(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!is_valid_map_char(line[i]))
		{
			ft_putstr_fd("Error\nInvalid character in map\n", 2);
			return (-1);
		}
		i++;
	}
	return (0);
}

static int	append_line_to_map(char ***map_lines, char *line, int *map_height)
{
	int		i;
	char	*copy;
	char	**new_map;

	new_map = malloc(sizeof(char *) * (*map_height + 2));
	if (!new_map)
		return (0);
	i = 0;
	while (i < *map_height)
	{
		new_map[i] = (*map_lines)[i];
		i++;
	}
	copy = ft_strdup(line);
	if (!copy)
	{
		free(new_map);
		return (0);
	}
	new_map[*map_height] = copy;
	new_map[*map_height + 1] = NULL;
	free(*map_lines);
	*map_lines = new_map;
	(*map_height)++;
	return (1);
}

int	parse_map_line(char *line, t_game *game)
{
	if (validate_line_chars(line) < 0)
		return (-1);
	if (!append_line_to_map(&game->map.grid, line, &game->map.height))
		return (ft_putstr_fd("Error\nFailed to allocate map memory\n", 2), -1);
	if ((int)ft_strlen(line) > game->map.width)
		game->map.width = ft_strlen(line);
	return (0);
}
