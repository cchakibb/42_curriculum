/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:52:08 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/06 14:52:09 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef SO_LONG_H
# define SO_LONG_H

# include "structures.h"
# include "Libft/ft_printf.h"
# include "Libft/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h> 
# include <X11/keysym.h>
# include <fcntl.h>

void	position_player(int x, int y, t_vars *vars, char *line);
void	find_error(t_vars *vars, char **ar);
void	makemap(char **ar, t_mapdata *data, t_vars *vars);
void	check_rectangle(t_map *map, char *next_line, int fd);
void	check_recterror(t_map *map, char *next, int fd);
void	error(char *str, char *next_line, int fd);
void	path_check(t_vars *vars);
void	error_notplayable(char *str, char **temp, char **grid);
char	**create_copymap(t_vars *vars);
void	path_exist(int px_y, int px_x, t_vars *vars, char **temp);
void	path_exist(int px_y, int px_x, t_vars *vars, char **temp);
int		ft_strcmp(char *str);
void	load_images(t_vars *vars);
int		key_hook(int key_code, t_vars *vars);
void	draw_background(t_vars *vars);
int		update_playerposition(t_vars *vars, t_pos pos);
void	draw_map(t_vars *vars);
void	draw_player(t_vars *vars, t_pos pos);
int		close_window(t_vars *vars);
#endif
