/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:40:50 by stobin            #+#    #+#             */
/*   Updated: 2025/05/17 00:19:47 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Process and load individual texture (image) from path
static int	load_texture(void *mlx, char *path, t_img *img)
{
	char	*clean_path;

	clean_path = ft_strtrim(path, " \n");
	if (!clean_path)
	{
		ft_putstr_fd("Error\nFailed to clean texture path: ", 2);
		ft_putstr_fd(path, 2);
		ft_putchar_fd('\n', 2);
		return (-1);
	}
	img->img = mlx_xpm_file_to_image(
			mlx, clean_path, &img->width, &img->height);
	if (!img->img)
	{
		ft_putstr_fd("Error\nFailed to load texture: ", 2);
		ft_putstr_fd(path, 2);
		ft_putchar_fd('\n', 2);
		free(clean_path);
		return (-1);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_length, &img->endian);
	free(clean_path);
	return (0);
}

// loads wall textures (North, South, East, West)
// from the file paths specified in the .cub
// and converts XPM files into MLX image objects.
int	load_textures(t_game *game)
{
	if (load_texture(game->mlx,
			game->textures.north_path, &game->textures.north) < 0)
		return (-1);
	if (load_texture(game->mlx,
			game->textures.east_path, &game->textures.east) < 0)
		return (-1);
	if (load_texture(game->mlx,
			game->textures.south_path, &game->textures.south) < 0)
		return (-1);
	if (load_texture(game->mlx,
			game->textures.west_path, &game->textures.west) < 0)
		return (-1);
	free_texture_paths(&game->textures);
	return (0);
}
