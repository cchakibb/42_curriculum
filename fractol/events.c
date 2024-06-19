/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:53:35 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/19 23:08:00 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int key, t_fractal *fractal)
{
	printf("Key pressed: %d\n", key);
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
	//render_fractals(fractal, fractal->name); //HERE
	return (0);
}

//int	mouse_hook(t_fractal *fractal)
