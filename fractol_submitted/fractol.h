/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:00:41 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/14 12:04:29 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>

# define SIZE 800
# define RATIO 200.0

# define BLACK 0x000000
# define YELLOW 0xFCBE11
# define ORANGE 0xFFA500
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define PURPLE 0x800080

# define ESCAPE 4.0

# define ESC 65307
# define INCREASE 105
# define DECREASE 100
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define CHANGE 99
# define ZOOM_IN 5
# define ZOOM_OUT 4
# define BACK 98

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct S_fractal
{
	char	*name;
	void	*mlx;
	void	*window;
	void	*image;
	char	*pixel_addr;
	int		bpp;
	int		size_len;
	int		endian;
	int		max_iter;
	int		color;
	double	offset_x;
	double	offset_y;
	double	julia_cx;
	double	julia_cy;
	double	zoom;
}				t_fractal;

void	change_pxl_color(int x, int y, t_fractal *fractal, int color);
void	draw_fractal(t_fractal *fractal, char *name);
void	draw_mandelbrot(t_fractal *fractal);
void	draw_julia(t_fractal *fractal);
int		exit_fractal(t_fractal *fractal);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		key_hook(int key_code, t_fractal *fractal);
int		mouse_hook(int keycode, int x, int y, t_fractal *fractal);
double	atodb(char *s);

#endif
