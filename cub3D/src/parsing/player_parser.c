/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 22:13:01 by stobin            #+#    #+#             */
/*   Updated: 2025/05/16 20:48:04 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_north_south(t_player *player, char orientation)
{
	if (orientation == 'N')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -PLANE_LEN;
		player->plane_y = 0;
	}
	else if (orientation == 'S')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = PLANE_LEN;
		player->plane_y = 0;
	}
}

static void	set_east_west(t_player *player, char orientation)
{
	if (orientation == 'E')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -PLANE_LEN;
	}
	else if (orientation == 'W')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = PLANE_LEN;
	}
}

static void	set_direction(t_player *player, char orientation)
{
	if (orientation == 'N' || orientation == 'S')
		set_north_south(player, orientation);
	else if (orientation == 'E' || orientation == 'W')
		set_east_west(player, orientation);
}

int	spawn_search(t_game *game, int *found, int *x, int *y)
{
	char	c;

	*y = 0;
	while (*y < game->map.height)
	{
		*x = 0;
		while (*x < (int)ft_strlen(game->map.grid[*y]))
		{
			c = game->map.grid[*y][*x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				if (*found)
					return (ft_putstr_fd("Error\n2+ spawn points\n", 2), -1);
				*found = 1;
				game->player.x = *x + 0.5;
				game->player.y = *y + 0.5;
				set_direction(&game->player, c);
				game->map.grid[*y][*x] = '0';
			}
			(*x)++;
		}
		(*y)++;
	}
	return (0);
}

int	find_spawn(t_game *game)
{
	int		x;
	int		y;
	int		found;

	found = 0;
	if (spawn_search(game, &found, &x, &y) < 0)
		return (-1);
	if (!found)
		return (ft_putstr_fd("Error\nNo player found on map\n", 2), -1);
	return (0);
}
