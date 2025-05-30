/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:22:18 by stobin            #+#    #+#             */
/*   Updated: 2025/05/16 20:52:25 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// we exit the game, free all allocated MLX resources,
// game textures, map data, and then terminate the program
int	close_game(t_game *game)
{
	if (game->mlx)
	{
		if (game->frame.img)
		{
			mlx_destroy_image(game->mlx, game->frame.img);
			game->frame.img = NULL;
		}
		free_textures(game);
		if (game->win)
		{
			mlx_destroy_window(game->mlx, game->win);
			game->win = NULL;
		}
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	free_map_n_paths(&game->map, &game->textures);
	exit(EXIT_SUCCESS);
	return (0);
}

// mlx_hook: bit_mask needed for window to listen for keypress event
// when sending keypress (2); BUT no mask needed when destroying window.
// N.B. bpp, line_length, endian get filled/set during the function call :D
// we initialize and run the main game logic.
// we load textures, create the window, set up event hooks 
// (keyboard, mouse, close),
// create the main image buffer, and start the MLX render loop.
int	play_game(t_game *game)
{
	if (load_textures(game) < 0)
		return (close_game(game));
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	if (!game->win)
		return (close_game(game));
	mlx_hook(game->win, 2, 1, handle_keypress, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	game->frame.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->frame.addr = mlx_get_data_addr(game->frame.img, &game->frame.bpp,
			&game->frame.line_length, &game->frame.endian);
	mlx_loop_hook(game->mlx, render_frame, game);
	mlx_loop(game->mlx);
	return (0);
}

// we handle argument parsing, initialize game structures,
// parse the map file, set up MLX, and start the game loop.
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Error\n1 input argument! Usage: ./cub3d <map.cub>\n", 2);
		return (EXIT_FAILURE);
	}
	init_game(&game);
	if (parse_cub_file(argv[1], &game) != 0)
	{
		ft_putstr_fd("Error\nFailed to parse a .cub file\n", 2);
		free_map_n_paths(&game.map, &game.textures);
		free_textures(&game);
		return (EXIT_FAILURE);
	}
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		ft_putstr_fd("Error\nFailed to initialize minilibx\n", 2);
		free_map_n_paths(&game.map, &game.textures);
		free_textures(&game);
		return (EXIT_FAILURE);
	}
	play_game(&game);
	return (0);
}
