/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:53:35 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/25 13:34:39 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int key, t_fractal *fractal)
{
	if (key == ESC)
		close_fractal(fractal);
	else if (key == UP)
		fractal->y_offset += 0.3 * fractal->zoom;
	else if (key == DOWN)
		fractal->y_offset -= 0.3 * fractal->zoom;
	else if (key == RIGHT)
		fractal->x_offset += 0.3 * fractal->zoom;
	else if (key == LEFT)
		fractal->x_offset -= 0.3 * fractal->zoom;
	render_fractals(fractal, fractal->name);
	return (0);
}

int	mouse_hook(int key, int x, int y, t_fractal *fractal)
{
	t_complex	before_zoom;
	t_complex	after_zoom;

	before_zoom = pixel_to_complex(x, y, fractal);
	if (key == ZOOM_IN)
		fractal->zoom *= 1.3;
	else if (key == ZOOM_OUT)
		fractal->zoom *= 0.90;
	after_zoom = pixel_to_complex(x, y, fractal);
	fractal->x_offset += before_zoom.real - after_zoom.real;
	fractal->y_offset += before_zoom.imaginary - after_zoom.imaginary;
	render_fractals(fractal, fractal->name);
	return (0);
}
