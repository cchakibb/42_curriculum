/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definition_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:44:11 by stobin            #+#    #+#             */
/*   Updated: 2025/05/14 23:11:07 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	def_err(t_game *game)
{
	if (!game->textures.north_path || !game->textures.south_path
		|| !game->textures.west_path || !game->textures.east_path
		|| game->floor.r == -1 || game->ceiling.r == -1)
	{
		if (!game->textures.north_path)
			ft_putstr_fd("Error\nMissing North texture (NO) definition\n", 2);
		else if (!game->textures.south_path)
			ft_putstr_fd("Error\nMissing South texture (SO) definition\n", 2);
		else if (!game->textures.west_path)
			ft_putstr_fd("Error\nMissing West texture (WE) definition\n", 2);
		else if (!game->textures.east_path)
			ft_putstr_fd("Error\nMissing East texture (EA) definition\n", 2);
		else if (game->floor.r == -1)
			ft_putstr_fd("Error\nMissing Floor color (F) definition\n", 2);
		else if (game->ceiling.r == -1)
			ft_putstr_fd("Error\nMissing Ceiling color (C) definition\n", 2);
		else
			ft_putstr_fd("Error\nOne or more mandatory configs missing.\n", 2);
		free_map_n_paths(&game->map, &game->textures);
		return (-1);
	}
	return (0);
}
