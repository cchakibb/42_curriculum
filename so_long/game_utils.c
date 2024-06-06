/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:52:33 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/06 14:56:03 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update_playerposition(t_vars *vars, t_pos pos)
{
	ft_printf("player moves: %d\n", ++vars->player_moves);
	if (vars->map.grid[pos.px_y][pos.px_x] == '1')
		return (0);
	else if (vars->map.grid[pos.px_y][pos.px_x] == 'C')
	{
		vars->map.data.collected ++;
		vars->map.grid[pos.px_y][pos.px_x] = '0';
		draw_player(vars, pos);
	}
	else if (vars->map.grid[pos.px_y][pos.px_x] == 'E' \
			&& (vars->map.data.c == vars->map.data.collected))
		close_window(vars);
	else if (vars->map.grid[pos.px_y][pos.px_x] != '1' \
			&& vars->map.grid[pos.px_y][pos.px_x] != 'E')
		draw_player(vars, pos);
	else
		return (0);
	vars->player.px_x = pos.px_x;
	vars->player.px_y = pos.px_y;
	return (0);
}
