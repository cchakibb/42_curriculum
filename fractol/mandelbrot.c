/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:53:43 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/19 23:50:42 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_mandelbrot(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < SIZE)
	{
		x = -1;
		while (++x < SIZE)
			calculate_mandelbrot(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx,
		fractal->window,
		fractal->image, 0, 0);
}

void	calculate_mandelbrot(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			iterations;

	z = (t_complex){.real = 0.0, .imaginary = 0.0};
	c = pixel_to_complex(x, y, fractal);
	iterations = 0;
	while (iterations < fractal->max_fractal_iterations)
	{
		z = complex_square(z);
		z.real += c.real;
		z.imaginary += c.imaginary;
		if (complex_magnitude_squared(z) > ESCAPE_VALUE)
		{
			color_pixel(x, y, fractal, fractal->color * (iterations % 256));
			return ;
		}
		iterations++;
	}
	color_pixel(x, y, fractal, BLACK);
}

t_complex	complex_square(t_complex z)
{
	t_complex	result;

	result.real = z.real * z.real - z.imaginary * z.imaginary;
	result.imaginary = 2 * z.real * z.imaginary;
	return (result);
}

double	complex_magnitude_squared(t_complex z)
{
	return (z.real * z.real + z.imaginary * z.imaginary);
}

t_complex	pixel_to_complex(int x, int y, t_fractal *fractal)
{
	t_complex	c;

	c.real = x / RATIO * fractal->zoom + fractal->x_offset;
	c.imaginary = -y / RATIO * fractal->zoom + fractal->y_offset;
	return (c);
}

int	calculate_pixel_position(int x, int y, t_fractal *fractal)
{
	return ((y * fractal->line_size_bytes) + x * (fractal->bpp / 8));
}

void	color_pixel(int x, int y, t_fractal *fractal, int color)
{
	int		pixel_position;
	char	*pixel_address;

	pixel_position = calculate_pixel_position(x, y, fractal);
	pixel_address = fractal->pixl_addr + pixel_position;
	*(unsigned int *)pixel_address = color;
}

