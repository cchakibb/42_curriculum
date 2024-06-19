/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:46:30 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/19 23:50:49 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define SIZE 800
# define RATIO 200.0
# define ESCAPE_VALUE 4.0

# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ZOOM_IN 5
# define ZOOM_OUT 4

// colors
# define BLACK 0x000000
# define SALMON 0xffbf72
# define YELLOW 0xFCBE11

typedef struct s_fractal
{
	char		*name;
	void		*mlx;
	void		*window;
	void		*image;
	char		*pixl_addr;
	int			bpp;
	int			line_size_bytes; //represents the size of a line in the image in bytes
	int			endian;
	double		zoom;
	int			color;
	double		x_offset;
	double		y_offset;
	double		julia_c_real;
	double		julia_c_imaginary;
	int			max_fractal_iterations;
}				t_fractal;

typedef struct s_complex
{
	double	real;
	double	imaginary;
}				t_complex;

// utils
int			ft_strncmp(const char *s1, const char *s2, size_t n);
double		atodb(char *s);

// MLX
void		start_mlx(t_fractal *fractal, char **av);
void		fill_other_data(t_fractal *fractal, char **av);
int			close_fractal(t_fractal *fractal);
int			key_hook(int key, t_fractal *fractal);

//drawing
void		render_fractals(t_fractal *fractal, char *fractal_name);
void		render_mandelbrot(t_fractal *fractal);
void		color_pixel(int x, int y, t_fractal *fractal, int color);

// calculation
void		calculate_mandelbrot(int x, int y, t_fractal *fractal);
t_complex	complex_square(t_complex z);
double		complex_magnitude_squared(t_complex z);
t_complex	pixel_to_complex(int x, int y, t_fractal *fractal);
int			calculate_pixel_position(int x, int y, t_fractal *fractal);


#endif
