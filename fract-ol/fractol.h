/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:28:42 by chbachir          #+#    #+#             */
/*   Updated: 2024/05/30 12:58:41 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define SIZE 800
# define RATIO 200.0//800/4
//color
# define BLACK 0x000000
# define YELLOW 0xFCBE11
# define BLUE 0x0000FF
# define MAGENTA_BURST 0xFF00FF  // A vibrant magenta
//RED FF0000
//GRE 00FF00
//BLU 0000FF

# define ESCAPE 4.0

# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define INCREASE 105 //i
# define DECREASE 100 //d
# define CHANGE 99 //c:change color
# define ZOOM_IN 4
# define ZOOM_OUT 5
# define MOUSEMOVE 6
# define PSYCHEDELIC 112
# define BACK 98 //b: back to previous color
# define M_CLK_L 1// click to move mouse
# define M_CLK_R 3//stop moving mouse

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
	char	*pixel;
	int		bpp;
	int		size_len;
	int		endian;
	int		max_iter;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	double	julia_cx;
	double	julia_cy;
	int		left_click;
}				t_fractal;

void	put_color_to_pix(int x, int y, t_fractal *fractal, int color);
int		exit_fractal(t_fractal *fractal);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
double	atodb(char *s);
void	draw_fractal(t_fractal *fractal, char *name);
void	draw_mandelbrot(t_fractal *fractal);
void	draw_julia(t_fractal *fractal);
//void	draw_ship(t_fractal *fractal);
int		julia_track(int x, int y, t_fractal *fractal);
int		key_hook(int key_code, t_fractal *fractal);
int		mouse_hook(int keycode, int x, int y, t_fractal *fractal);
//void	draw_newton(t_fractal *fractal);

#endif
