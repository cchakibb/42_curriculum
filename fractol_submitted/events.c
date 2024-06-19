/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:00:45 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/14 12:00:46 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int key_code, t_fractal *fractal)
{
	if (key_code == ESC)
		exit_fractal(fractal);
	else if (key_code == UP)
		fractal->offset_y += 0.2 * fractal->zoom;
	else if (key_code == DOWN)
		fractal->offset_y -= 0.2 * fractal->zoom;
	else if (key_code == LEFT)
		fractal->offset_x -= 0.2 * fractal->zoom;
	else if (key_code == RIGHT)
		fractal->offset_x += 0.2 * fractal->zoom;
	else if (key_code == INCREASE)
		fractal->max_iter += 10;
	else if (key_code == DECREASE)
		fractal->max_iter -= 10;
	else if (key_code == CHANGE)
		fractal->color += 0xFFFFFF / 100;
	else if (key_code == BACK)
		fractal->color -= 0xFFFFFF / 100;
	draw_fractal(fractal, fractal->name);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_fractal *fractal)
{
	double	x_before;
	double	y_before;
	double	x_after;
	double	y_after;

	x_before = x / RATIO * fractal->zoom + fractal->offset_x;
	y_before = -y / RATIO * fractal->zoom + fractal->offset_y;
	if (keycode == ZOOM_OUT)
		fractal->zoom *= 0.90;
	else if (keycode == ZOOM_IN)
		fractal->zoom *= 1.3;
	x_after = x / RATIO * fractal->zoom + fractal->offset_x;
	y_after = -y / RATIO * fractal->zoom + fractal->offset_y;
	fractal->offset_x += x_before - x_after;
	fractal->offset_y += y_before - y_after;
	draw_fractal(fractal, fractal->name);
	return (0);
}
