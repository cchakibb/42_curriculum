/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:02:25 by stobin            #+#    #+#             */
/*   Updated: 2025/05/12 19:39:36 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static void	interpolate_ray(t_ray *ray, t_game *game)
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

void	cast_rays(t_game *game)
{
	t_ray	ray;
	t_img	*texture;
	int		x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		init_ray_variables(&ray, x, game);
		interpolate_ray(&ray, game);
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
