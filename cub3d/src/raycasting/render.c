/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:39:00 by stobin            #+#    #+#             */
/*   Updated: 2025/05/12 19:39:37 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	rgb_to_int(t_colour colour)
{
	return ((colour.r << 16) | (colour.g << 8) | colour.b);
}

void	put_pixel(t_img *img, int x, int y, int colour)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = colour;
}

static void	draw_background(t_game *game)
{
	int		y;
	int		x;
	int		floor_colour;
	int		ceiling_colour;

	ceiling_colour = rgb_to_int(game->ceiling);
	floor_colour = rgb_to_int(game->floor);
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			if (y < SCREEN_HEIGHT / 2)
				put_pixel(&game->frame, x, y, ceiling_colour);
			else
				put_pixel(&game->frame, x, y, floor_colour);
			x++;
		}
		y++;
	}
}

int	render_frame(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	draw_background(game);
	cast_rays(game);
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);
	return (0);
}
