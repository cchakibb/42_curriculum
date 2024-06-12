/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:22:05 by lperez-h          #+#    #+#             */
/*   Updated: 2024/01/11 11:07:01 by lperez-h         ###   ########.fr       */
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
	else if (key_code == PSYCHEDELIC)
		fractal->color += MAGENTA_BURST;
	call_fractal(fractal, fractal->name);
	return (0);
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (fractal->left_click == 1 && ft_strncmp(fractal->name, "julia", 6) == 0)
	{
		fractal->julia_cx = x / RATIO * fractal->zoom + fractal->offset_x;
		fractal->julia_cy = -y / RATIO * fractal->zoom + fractal->offset_y;
		draw_julia(fractal);
	}
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
	if (keycode == ZOOM_IN)
		fractal->zoom *= 0.98;
	else if (keycode == ZOOM_OUT)
		fractal->zoom *= 1.1;
	else if (keycode == M_CLK_L)
		fractal->left_click = 1;
	else if (keycode == M_CLK_R)
		fractal->left_click = 0;
	else
		return (1);
	x_after = x / RATIO * fractal->zoom + fractal->offset_x;
	y_after = -y / RATIO * fractal->zoom + fractal->offset_y;
	fractal->offset_x += x_before - x_after;
	fractal->offset_y += y_before - y_after;
	call_fractal(fractal, fractal->name);
	return (0);
}
