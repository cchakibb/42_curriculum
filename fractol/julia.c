/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:53:45 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/24 13:49:39 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_julia(t_fractal *fractal)
{
	int	x;
	int y;

	y = -1;
	while (++y < SIZE)
	{
		x = -1;
		while (++x < SIZE)
			calculate_julia(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,0);
}

void	calculate_julia(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	int			iteration;

	z = pixel_to_complex(x, y, fractal);
	iteration = 0;
	while (iteration < fractal->max_fractal_iterations)
	{
		z = complex_square(z);
		z.real += fractal->julia_c_real;
		z.imaginary += fractal->julia_c_imaginary;
		if ( complex_magnitude_squared(z) > ESCAPE_VALUE)
		{
			color_pixel(x, y, fractal, fractal->color * (iteration % 256));
			return ;
		}
		iteration++;
	}
	color_pixel(x, y, fractal, BLACK);
}
