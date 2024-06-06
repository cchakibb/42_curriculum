/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:52:37 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/06 14:55:58 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_grid(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map.grid && vars->map.grid[i])
	{
		free(vars->map.grid[i]);
		vars->map.grid[i] = NULL;
		i ++;
	}
	free(vars->map.grid);
	vars->map.grid = NULL;
}

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_image(vars->mlx, vars->background.img);
	mlx_destroy_image(vars->mlx, vars->exit.img);
	mlx_destroy_image(vars->mlx, vars->wall.img);
	mlx_destroy_image(vars->mlx, vars->heart.img);
	mlx_destroy_image(vars->mlx, vars->player_up.img);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_grid(vars);
	exit(0);
}
