/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:23:11 by stobin            #+#    #+#             */
/*   Updated: 2025/05/14 23:11:07 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_colour_line(char *line)
{
	return (line[0] == 'F' || line[0] == 'C');
}

static int	parse_rgb_component(char *comp)
{
	char	*clean;
	int		value;
	int		i;

	i = 0;
	clean = ft_strtrim(comp, " \t\n\v\f\r");
	while (clean[i])
	{
		if (!ft_isdigit(clean[i]))
		{
			free(clean);
			return (-1);
		}
		i++;
	}
	value = ft_atoi(clean);
	free(clean);
	if (value < 0 || value > 255)
		return (-1);
	return (value);
}

static int	store_colour(char *line, t_colour *colour)
{
	char	*pure_col;
	char	**rgb;

	pure_col = ft_strtrim(line + 1, " \n");
	if (!pure_col)
		return (ft_putstr_fd("Error\nmalloc failed\n", 2), -1);
	rgb = ft_split(pure_col, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
	{
		free(pure_col);
		ft_free_strarr(rgb);
		return (ft_putstr_fd("Error\nInvalid RGB format\n", 2), -1);
	}
	colour->r = parse_rgb_component(rgb[0]);
	colour->g = parse_rgb_component(rgb[1]);
	colour->b = parse_rgb_component(rgb[2]);
	free(pure_col);
	ft_free_strarr(rgb);
	if (colour->r < 0 || colour->g < 0 || colour->b < 0)
		return (ft_putstr_fd("Error\nRGB values must be 0-255\n", 2), -1);
	return (0);
}

int	parse_colour_line(char *line, t_game *game)
{
	if (line[0] == 'F')
	{
		if (game->floor.r != -1)
			return (ft_putstr_fd("Error\nMultiple floor colours\n", 2), -1);
		return (store_colour(line, &game->floor));
	}
	else if (line[0] == 'C')
	{
		if (game->ceiling.r != -1)
			return (ft_putstr_fd("Error\nMultiple ceiling colours\n", 2), -1);
		return (store_colour(line, &game->ceiling));
	}
	ft_putstr_fd("Error\nUnknown colour identifier\n", 2);
	return (-1);
}
