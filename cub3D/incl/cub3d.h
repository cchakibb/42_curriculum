/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:12:44 by stobin            #+#    #+#             */
/*   Updated: 2025/05/14 22:54:23 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <X11/keysym.h> // keycodes
# include "libft.h"
# include "get_next_line.h"

# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 768
# define MOVE_SPEED 0.2
# define ROT_SPEED 0.075
# define PLANE_LEN 0.66

// image struct (bits per pixel; endian L/R)
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_texture
{
	char	*north_path;
	char	*east_path;
	char	*south_path;
	char	*west_path;
	t_img	north;
	t_img	south;
	t_img	east;
	t_img	west;
}	t_texture;

typedef struct s_colour
{
	int	r;
	int	g;
	int	b;
}	t_colour;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		frame;
	t_texture	textures;
	t_colour	floor;
	t_colour	ceiling;
	t_map		map;
	t_player	player;
}	t_game;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	double	perp_wall_dist;
	double	wall_x;
	int		tex_x;
	int		draw_start;
	int		draw_end;
	int		line_height;
}	t_ray;

// Function Signatures
int		parse_cub_file(char *filename, t_game *game);
int		load_textures(t_game *game);
t_img	*get_wall_texture(t_game *game, int side,
			double ray_dir_x, double ray_dir_y);
int		is_texture_line(char *line);
int		parse_texture_line(char *line, t_game *game);
int		parse_colour_line(char *line, t_game *game);
int		is_colour_line(char *line);
int		parse_map_line(char *line, t_game *game);
int		no_cub_extension(int len, char *filename);
int		dump_lines(int fd, char *line);
int		map_has_gap(char *line, int newline);
int		val_map_closed(t_game *game);
int		def_err(t_game *game);
int		find_spawn(t_game *game);
void	init_game(t_game *game);
int		render_frame(void *param);
void	put_pixel(t_img *img, int x, int y, int colour);
int		handle_keypress(int keycode, t_game *game);
void	cast_rays(t_game *game);
void	free_map(t_map *map);
void	free_textures(t_game *game);
void	free_texture_paths(t_texture *textures);
void	free_map_n_paths(t_map *map, t_texture *textures);
int		close_game(t_game *game);

#endif
