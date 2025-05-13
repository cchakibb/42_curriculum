/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:58:08 by stobin            #+#    #+#             */
/*   Updated: 2025/05/12 19:38:23 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	dump_lines(int fd, char *line)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	return (-1);
}

int	no_cub_extension(int len, char *filename)
{
	if (len < 5 || filename[len - 4] != '.' || filename[len - 3] != 'c'
		|| filename[len - 2] != 'u' || filename[len - 1] != 'b')
	{
		errno = 22;
		return (perror("Error\nOnly a .cub file can be an input"), -1);
	}
	return (0);
}

void	free_map_n_paths(t_map *map, t_texture *textures)
{
	free_map(map);
	free_texture_paths(textures);
}
