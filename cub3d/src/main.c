/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:22:18 by stobin            #+#    #+#             */
/*   Updated: 2025/05/12 19:40:27 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_textures(t_game *game)
{
	free(game->textures.north.img);
	game->textures.north.img = NULL;
	free(game->textures.east.img);
	game->textures.east.img = NULL;
	free(game->textures.south.img);
	game->textures.south.img = NULL;
	free(game->textures.west.img);
	game->textures.west.img = NULL;
}

int	close_game(t_game *game)
{
	if (game->frame.img)
		mlx_destroy_image(game->mlx, game->frame.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_textures(game);
	free_map(&game->map);
	exit(EXIT_SUCCESS);
	return (0);
}

int	play_game(t_game *game)
{
	if (load_textures(game) < 0)
		return (close_game(game));
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	if (!game->win)
		return (close_game(game));
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	game->frame.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->frame.addr = mlx_get_data_addr(game->frame.img, &game->frame.bpp,
			&game->frame.line_length, &game->frame.endian);
	mlx_loop_hook(game->mlx, render_frame, game);
	mlx_loop(game->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./cub3d <map.cub>\n", 2);
		return (EXIT_FAILURE);
	}
	init_game(&game);
	if (parse_cub_file(argv[1], &game) != 0)
	{
		ft_putstr_fd("Error\nFailed to parse a .cub file\n", 2);
		return (EXIT_FAILURE);
	}
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		ft_putstr_fd("Error\nFailed to initialize MiniLibX\n", 2);
		return (EXIT_FAILURE);
	}
	play_game(&game);
	return (0);
}
