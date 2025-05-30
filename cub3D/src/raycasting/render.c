/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:39:00 by stobin            #+#    #+#             */
/*   Updated: 2025/05/16 23:29:35 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// shift bits to easily format colour as mlx requires
static int	rgb_to_int(t_colour colour)
{
	return ((colour.r << 16) | (colour.g << 8) | colour.b);
}

// Declaring as (char *) allows us to shift the right number of bytes;
// casting to unsigned int ensures that we assign all 3 bytes of colour code
// with 2^2 = 4 bytes being the minimum segment that can hold them.
// cf. alpha, not used here, but 4 bytes ==> compatible/ready
void	put_pixel(t_img *img, int x, int y, int colour)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = colour;
}

t_img	*get_wall_texture(t_game *game, int side,
	double ray_dir_x, double ray_dir_y)
{
	if (side == 0)
	{
		if (ray_dir_x > 0)
			return (&game->textures.west);
		else
			return (&game->textures.east);
	}
	else
	{
		if (ray_dir_y > 0)
			return (&game->textures.north);
		else
			return (&game->textures.south);
	}
}

// First fill screen with floor/ceiling (then draw the walls over this)
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

// rendering function called in a loop by MLX (mlx_loop_hook)
// it clears the previous frame (draws background), then calls cast_rays
// to render the 3D scene, then puts the completed image to the window
int	render_frame(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	draw_background(game);
	cast_rays(game);
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);
	return (0);
}
