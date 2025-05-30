/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:02:25 by stobin            #+#    #+#             */
/*   Updated: 2025/05/17 00:24:38 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Line segment to be drawn depends on proximity to wall
// so does extent of viewport/plane to be drawn on.
// Use & to efficiently wrap texture dim refs (modulo just for n^2).
static void	draw_vertical_line(t_game *game, int x, t_ray *ray, t_img *texture)
{
	double	step;
	double	tex_pos;
	int		y;
	int		tex_y;
	int		colour;

	step = 1.0 * texture->height / (ray->draw_end - ray->draw_start);
	tex_pos = 0;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex_y = (int)tex_pos & (texture->height - 1);
		tex_pos += step;
		colour = *(unsigned int *)(texture->addr + (tex_y * texture->line_length
					+ ray->tex_x * (texture->bpp / 8)));
		put_pixel(&game->frame, x, y, colour);
		y++;
	}
}

// Double x since the viewport (plane) ranges over [-1,1]: length = 2
// Normalize ray directions to the plane and its dimensions [-1,1]
// Map location (grid): truncated player pos. (simplifies wall search)
// Delta dist must be non-zero to avoid error (div zero)
// In case ray_dir is zero, make vector magnitude (dist) near-infinite:
// perpendicular walls will never be hit;
// else we find distance ray must travel to move 1 unit along x,y axis
// then the specific distance from the ray origin (player position)
// to the next (+1) or previous (-player.x/y) cell edge 
static void	init_ray_variables(t_ray *ray, int x, t_game *game)
{
	ray->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->ray_dir_x = game->player.dir_x + game->player.plane_x * ray->camera_x;
	ray->ray_dir_y = game->player.dir_y + game->player.plane_y * ray->camera_x;
	ray->map_x = (int)game->player.x;
	ray->map_y = (int)game->player.y;
	ray->delta_dist_x = 1e30;
	if (ray->ray_dir_x != 0)
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = 1e30;
	if (ray->ray_dir_y != 0)
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->step_x = 1;
	if (ray->ray_dir_x < 0)
		ray->step_x = -1;
	ray->step_y = 1;
	if (ray->ray_dir_y < 0)
		ray->step_y = -1;
	ray->side_dist_x = (ray->map_x + 1.0 - game->player.x) * ray->delta_dist_x;
	if (ray->step_x == -1)
		ray->side_dist_x = (game->player.x - ray->map_x) * ray->delta_dist_x;
	ray->side_dist_y = (ray->map_y + 1.0 - game->player.y) * ray->delta_dist_y;
	if (ray->step_y == -1)
		ray->side_dist_y = (game->player.y - ray->map_y) * ray->delta_dist_y;
}

// To find point where ray strikes wall, sequentially check every
// next closest grid cell edge, set side_dist to this edge location,
// until this edge turns out to be a wall.
static void	ray_strike_point(t_ray *ray, t_game *game)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->map.grid[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

// Calculate perpendicular distance from player-plane to relevant wall:
//     (grid-oriented): prevents distortion of view (bulging of center).
// Line segment of wall texture to be drawn depends on proximity to wall.
// Get specific point along wall segment that ray hits
static void	compute_wall_properties(t_ray *ray, t_game *game)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - game->player.x
				+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - game->player.y
				+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
	ray->line_height = (int)(SCREEN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw_end >= SCREEN_HEIGHT)
		ray->draw_end = SCREEN_HEIGHT - 1;
	ray->wall_x = game->player.x + ray->perp_wall_dist * ray->ray_dir_x;
	if (ray->side == 0)
		ray->wall_x = game->player.y + ray->perp_wall_dist * ray->ray_dir_y;
	ray->wall_x -= floor(ray->wall_x);
}

// Our raycasting logic: we iterate thru every vertical stripe (x-coordinate)
// of the screen, calculate ray direction, compute wall properties 
// (distance, height), and determine texture coordinates for rendering
// the 3D perspective. If ray travels horizontally (x, 0) then we hit a vertical
// (y, 1) wall and we need the y position that we hit. If ray travels vertically
// (y, 1) then we hit a horizontal (x, 0) wall and we need the x position
// that we hit.
void	cast_rays(t_game *game)
{
	t_ray	ray;
	t_img	*texture;
	int		x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		init_ray_variables(&ray, x, game);
		ray_strike_point(&ray, game);
		compute_wall_properties(&ray, game);
		texture = get_wall_texture(game, ray.side,
				ray.ray_dir_x, ray.ray_dir_y);
		ray.tex_x = (int)(ray.wall_x * (double)texture->width);
		if ((ray.side == 0 && ray.ray_dir_x > 0)
			|| (ray.side == 1 && ray.ray_dir_y < 0))
			ray.tex_x = texture->width - ray.tex_x - 1;
		draw_vertical_line(game, x, &ray, texture);
		x++;
	}
}
