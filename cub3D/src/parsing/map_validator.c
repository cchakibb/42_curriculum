/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:32:09 by stobin            #+#    #+#             */
/*   Updated: 2025/05/16 20:28:03 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_inside_bounds(t_map *map, int x, int y)
{
	if (y < 0 || y >= map->height)
		return (0);
	if (x < 0 || x >= (int)ft_strlen(map->grid[y]))
		return (0);
	return (1);
}

int	check_tile_loc(t_map *map, int *x, int *y, char *tile)
{
	char	*str;

	if (!is_inside_bounds(map, *x, *y))
	{
		printf("Error: Out of map bounds at x=%d y=%d\n", *x, *y);
		return (0);
	}
	*tile = map->grid[*y][*x];
	if (*tile == ' ' || *tile == '\n' || *tile == '\0'
		|| (*tile == '\n' && *x > 0 && map->grid[*y][*x - 1] == 0))
	{
		str = tile;
		if (*tile == '\n')
			str = "\\n";
		printf("Error: Invalid tile '%s' at x=%d y=%d\n", str, *x, *y);
		return (0);
	}
	return (1);
}

// Recursive filling of map cells from spawn point
static int	flood_fill(t_map *map, char **visited, int x, int y)
{
	char	tile;

	if (!check_tile_loc(map, &x, &y, &tile))
		return (0);
	if (visited[y][x])
		return (1);
	if (tile == '1')
		return (1);
	if (tile != '0')
	{
		printf("Error: Unexpected tile '%c' at x=%d y=%d\n", tile, x, y);
		return (0);
	}
	visited[y][x] = 1;
	if (!flood_fill(map, visited, x + 1, y))
		return (0);
	if (!flood_fill(map, visited, x - 1, y))
		return (0);
	if (!flood_fill(map, visited, x, y + 1))
		return (0);
	if (!flood_fill(map, visited, x, y - 1))
		return (0);
	return (1);
}

static char	**create_visited_map(t_map *map)
{
	char	**visited;
	int		i;

	visited = malloc(sizeof(char *) * map->height);
	if (!visited)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		visited[i] = ft_calloc(ft_strlen(map->grid[i]) + 1, sizeof(char));
		if (!visited[i])
		{
			while (--i >= 0)
				free(visited[i]);
			free(visited);
			return (NULL);
		}
		i++;
	}
	return (visited);
}

// we validate if the parsed map is enclosed by walls using a 
// flood-fill algorithm. we start from the player's position 
// and ensure all reachable empty spaces ('0')
// are surrounded by walls ('1') or other visited empty spaces.
int	val_map_closed(t_game *game)
{
	char	**visited;
	int		valid;
	int		i;

	visited = create_visited_map(&game->map);
	if (!visited)
		return (ft_putstr_fd("Error\nmalloc failed\n", 2), -1);
	valid = flood_fill(&game->map, visited, game->player.x, game->player.y);
	i = 0;
	while (i < game->map.height)
		free(visited[i++]);
	free(visited);
	if (!valid)
		return (ft_putstr_fd("Error\nmap not closed\n", 2), -1);
	return (0);
}
