/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:46:30 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/18 14:21:18 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define SIZE 8005


typedef struct s_fractal
{
	char		*name;
	void		*mlx;
	void		*window;
	void		*image;
	void		*pixl_addr;
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

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	start_mlx(t_fractal *fractal, char **av);
void	fill_other_data(t_fractal *fractal, char **av);

#endif
