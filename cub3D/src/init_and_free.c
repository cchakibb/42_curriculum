/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:15:34 by stobin            #+#    #+#             */
/*   Updated: 2025/05/16 23:29:47 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Zero game struct memory and 
// initialize game struct default values
void	init_game(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->mlx = NULL;
	game->win = NULL;
	game->map.grid = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.dir_x = 0;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0;
	game->floor.r = -1;
	game->ceiling.r = -1;
}

void	free_map_n_paths(t_map *map, t_texture *textures)
{
	free_map(map);
	free_texture_paths(textures);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map || !map->grid)
		return ;
	i = 0;
	while (i < map->height)
	{
		free(map->grid[i]);
		map->grid[i] = NULL;
		i++;
	}
	free(map->grid);
	map->grid = NULL;
	map->height = 0;
	map->width = 0;
}

void	free_texture_paths(t_texture *textures)
{
	free(textures->north_path);
	textures->north_path = NULL;
	free(textures->east_path);
	textures->east_path = NULL;
	free(textures->south_path);
	textures->south_path = NULL;
	free(textures->west_path);
	textures->west_path = NULL;
}

void	free_textures(t_game *game)
{
	if (game->mlx)
	{
		if (game->textures.north.img)
			mlx_destroy_image(game->mlx, game->textures.north.img);
		if (game->textures.east.img)
			mlx_destroy_image(game->mlx, game->textures.east.img);
		if (game->textures.south.img)
			mlx_destroy_image(game->mlx, game->textures.south.img);
		if (game->textures.west.img)
			mlx_destroy_image(game->mlx, game->textures.west.img);
	}
	game->textures.north.img = NULL;
	game->textures.east.img = NULL;
	game->textures.south.img = NULL;
	game->textures.west.img = NULL;
}
