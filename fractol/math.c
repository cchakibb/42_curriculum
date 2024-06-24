/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:26:25 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/24 14:26:31 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	complex_magnitude_squared(t_complex z)
{
	return (z.real * z.real + z.imaginary * z.imaginary);
}

t_complex	complex_square(t_complex z)
{
	t_complex	result;

	result.real = z.real * z.real - z.imaginary * z.imaginary;
	result.imaginary = 2 * z.real * z.imaginary;
	return (result);
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
