/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:00:25 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/14 12:08:14 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	atodb(char *s)
{
	double	int_part;
	double	double_part;
	int		sign;
	double	div;

	int_part = 0;
	double_part = 0;
	sign = 1;
	div = 1.0;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s != '.' && *s)
		int_part = (int_part * 10.0) + (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s)
	{
		div /= 10;
		double_part = double_part + (*s++ - '0') * div;
	}
	return (sign * (int_part + double_part));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && (*s1 == *s2) && --n)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	change_pxl_color(int x, int y, t_fractal *fractal, int color)
{
	int		pos;
	char	*temp;

	pos = y * fractal->size_len + x * (fractal->bpp / 8);
	temp = fractal->pixel_addr + pos;
	*(unsigned int *)temp = color;
}

int	exit_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(0);
	return (1);
}

void	draw_fractal(t_fractal *fractal, char *name)
{
	if (ft_strncmp(name, "mandelbrot", 11) == 0)
		draw_mandelbrot(fractal);
	else if (ft_strncmp(name, "julia", 6) == 0)
		draw_julia(fractal);
}
