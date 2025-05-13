/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 23:14:59 by stobin            #+#    #+#             */
/*   Updated: 2025/05/12 19:40:25 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h> // keycodes
#include "cub3d.h"

static int	is_wall(t_game *game, double x, double y)
{
	int	x_int;
	int	y_int;

	x_int = (int)x;
	y_int = (int)y;
	if (x_int < 0 || x_int >= game->map.width
		|| y_int < 0 || y_int >= game->map.height)
		return (1);
	return (game->map.grid[y_int][x_int] == '1');
}

static void	move(t_game *game, double dx, double dy)
{
	if (!is_wall(game, game->player.x + dx, game->player.y))
		game->player.x += dx;
	if (!is_wall(game, game->player.x, game->player.y + dy))
		game->player.y += dy;
}

static void	rotate(t_player *player, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	player->dir_x = old_dir_x * cos(angle) - player->dir_y * sin(angle);
	player->dir_y = old_dir_x * sin(angle) + player->dir_y * cos(angle);
	player->plane_x = old_plane_x * cos(angle) - player->plane_y * sin(angle);
	player->plane_y = old_plane_x * sin(angle) + player->plane_y * cos(angle);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		close_game(game);
	else if (keycode == XK_w || keycode == XK_W)
		move(game, game->player.dir_x * MOVE_SPEED,
			game->player.dir_y * MOVE_SPEED);
	else if (keycode == XK_s || keycode == XK_S)
		move(game, -game->player.dir_x * MOVE_SPEED,
			-game->player.dir_y * MOVE_SPEED);
	else if (keycode == XK_a || keycode == XK_A)
		move(game, -game->player.plane_x * MOVE_SPEED,
			-game->player.plane_y * MOVE_SPEED);
	else if (keycode == XK_d || keycode == XK_D)
		move(game, game->player.plane_x * MOVE_SPEED,
			game->player.plane_y * MOVE_SPEED);
	else if (keycode == XK_Left)
		rotate(&game->player, -ROT_SPEED);
	else if (keycode == XK_Right)
		rotate(&game->player, ROT_SPEED);
	return (0);
}
