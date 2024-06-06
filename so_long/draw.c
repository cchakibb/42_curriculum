/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:52:44 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/06 14:52:48 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_vars *vars)
{
	vars->wall.img = mlx_xpm_file_to_image(vars->mlx, "textures/wall.xpm", \
			&vars->wall.px_w, &vars->wall.px_h);
	vars->background.img = mlx_xpm_file_to_image(vars->mlx, \
			"textures/background.xpm", \
			&vars->background.px_w, &vars->background.px_h);
	vars->heart.img = mlx_xpm_file_to_image(vars->mlx, "textures/heart.xpm", \
			&vars->heart.px_w, &vars->heart.px_h);
	vars->exit.img = mlx_xpm_file_to_image(vars->mlx, "textures/exit.xpm", \
			&vars->exit.px_w, &vars->exit.px_h);
	vars->player_up.img = mlx_xpm_file_to_image(vars->mlx, \
			"textures/player-up.xpm", \
			&vars->player_up.px_w, &vars->player_up.px_h);
}

void	draw_background(t_vars *vars)
{
	t_pos	pos;

	pos.px_x = 0;
	pos.px_y = 0;
	while (pos.px_y < vars->map.data.num_nextline * SIZE)
	{
		while (pos.px_x < vars->map.data.count * SIZE)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->background.img, pos.px_x, pos.px_y);
			pos.px_x = pos.px_x + SIZE;
		}
		pos.px_x = 0;
		pos.px_y = pos.px_y + SIZE;
	}
}

void	draw_map(t_vars *vars)
{
	t_pos	pos;

	pos.px_y = 0;
	while (pos.px_y < vars->map.data.num_nextline * SIZE)
	{
		pos.px_x = 0;
		while (pos.px_x < vars->map.data.count * SIZE)
		{
			if (vars->map.grid[pos.px_y / SIZE][pos.px_x / SIZE] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, \
						vars->heart.img, pos.px_x, pos.px_y);
			else if (vars->map.grid[pos.px_y / SIZE][pos.px_x / SIZE] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, \
						vars->exit.img, pos.px_x, pos.px_y);
			else if (vars->map.grid[pos.px_y / SIZE][pos.px_x / SIZE] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, \
						vars->wall.img, pos.px_x, pos.px_y);
			else if (vars->map.grid[pos.px_y / SIZE][pos.px_x / SIZE] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, \
						vars->player_up.img, vars->player.px_x * SIZE, \
						vars->player.px_y * SIZE);
			pos.px_x = pos.px_x + SIZE;
		}
		pos.px_y = pos.px_y + SIZE;
	}
}

void	draw_player(t_vars *vars, t_pos pos)
{
	if (vars->map.grid[vars->player.px_y] \
			[vars->player.px_x] == 'P')
		vars->map.grid[vars->player.px_y] \
				[vars->player.px_x] = '0';
	mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->background.img, \
			vars->player.px_x * SIZE, \
			vars->player.px_y * SIZE);
	mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->player_up.img, \
			pos.px_x * SIZE, \
			pos.px_y * SIZE);
}

int	key_hook(int key_code, t_vars *vars)
{
	if (key_code == 65364)
		update_playerposition(vars, (t_pos){vars->player.px_x, \
				vars->player.px_y + 1});
	else if (key_code == 65362)
		update_playerposition(vars, (t_pos){vars->player.px_x, \
				vars->player.px_y - 1});
	else if (key_code == 65361)
		update_playerposition(vars, (t_pos){vars->player.px_x - 1, \
				vars->player.px_y});
	else if (key_code == 65363)
		update_playerposition(vars, (t_pos){vars->player.px_x + 1, \
				vars->player.px_y});
	else if (key_code == 53 || key_code == 65307)
		close_window(vars);
	return (0);
}
