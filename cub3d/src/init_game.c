/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:15:34 by stobin            #+#    #+#             */
/*   Updated: 2025/05/12 19:40:20 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub3d.h"

// zero game struct memory and 
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
