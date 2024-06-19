/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:00:37 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/14 12:00:38 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_julia(int x, int y, t_fractal *fractal);

void	draw_julia(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < SIZE)
	{
		x = -1;
		while (++x < SIZE)
			calculate_julia(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx,
		fractal->window,
		fractal->image, 0, 0);
}

void	calculate_julia(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	double		temp_x;
	int			i;

	z.x = x / RATIO * fractal->zoom + fractal->offset_x;
	z.y = -y / RATIO * fractal->zoom + fractal->offset_y;
	i = 0;
	while (i++ < fractal->max_iter)
	{
		temp_x = z.x * z.x - z.y * z.y + fractal->julia_cx;
		z.y = 2 * z.x * z.y + fractal->julia_cy;
		z.x = temp_x;
		if ((z.x * z.x + z.y * z.y) > ESCAPE)
		{
			change_pxl_color(x, y, fractal, fractal->color * (i % 256));
			return ;
		}
	}
	change_pxl_color(x, y, fractal, BLACK);
}
