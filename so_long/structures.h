/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:52:05 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/06 14:56:15 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# define SIZE 32
# include <stddef.h>
# include <stdbool.h>

typedef struct s_sprite {
	int		px_w;
	int		px_h;
	void	*img;
}t_sprite;

typedef struct s_pos {
	int	px_x;
	int	px_y;
}	t_pos;

typedef struct s_mapdata
{
	int		count;
	int		collected;
	int		e;
	int		p;
	int		c;
	int		o;
	int		num_nextline;
	char	**map1;
}	t_mapdata;

typedef struct s_map {
	char		**grid;
	t_mapdata	data;
	size_t		g_h;
	size_t		g_w;
	int			fd;
	char		*filepath;
	int			collectibles;
}	t_map;

typedef struct s_vars {
	t_map		map;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	char		*relative_path;
	t_pos		player;
	t_sprite	background;
	t_sprite	heart;
	t_sprite	exit;
	t_sprite	player_up;
	t_sprite	wall;
	int			img_width;
	int			img_height;
	int			exits;
	int			player_moves;
	int			collected;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_vars;
#endif
