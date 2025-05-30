/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:27:02 by stobin            #+#    #+#             */
/*   Updated: 2025/05/15 22:38:30 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_texture_line(char *line)
{
	return (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0);
}

static char	*extract_path(char *line)
{
	char	**parts;
	char	*path;

	parts = ft_split(line, ' ');
	if (!parts || !parts[0] || !parts[1])
		return (NULL);
	path = ft_strdup(parts[1]);
	ft_free_strarr(parts);
	return (path);
}

static int	load_texture_path(char **dest, char *line)
{
	if (*dest)
	{
		ft_putstr_fd("Error\nTexture identifier appears multiple times\n", 2);
		return (-1);
	}
	*dest = extract_path(line);
	if (!*dest)
	{
		ft_putstr_fd("Error\nFailed to extract texture path\n", 2);
		return (-1);
	}
	return (0);
}

int	parse_texture_line(char *line, t_game *game)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (load_texture_path(&game->textures.north_path, line));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (load_texture_path(&game->textures.east_path, line));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (load_texture_path(&game->textures.south_path, line));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (load_texture_path(&game->textures.west_path, line));
	ft_putstr_fd("Error\nUnknown texture type identifier\n", 2);
	return (-1);
}
