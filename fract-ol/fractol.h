/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:16:34 by chbachir          #+#    #+#             */
/*   Updated: 2024/05/27 14:22:26 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> //TODO debugging
# include <stdlib.h> //malloc free
# include <unistd.h> // write
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"

# define WIDTH	800
# define HEIGHT	800

# define BLACK	0x000000  // RGB(0, 0, 0)
# define WHITE	0xFFFFFF  // RGB(255, 255, 255)
# define RED		0xFF0000  // RGB(255, 0, 0)
# define GREEN	0x00FF00  // RGB(0, 255, 0)
# define BLUE	0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
# define MAGENTA_BURST   0xFF00FF
# define LIME_SHOCK      0xCCFF00
# define NEON_ORANGE     0xFF6600
# define PSYCHEDELIC_PURPLE 0x660066
# define AQUA_DREAM      0x33CCCC
# define HOT_PINK        0xFF66B2
# define ELECTRIC_BLUE   0x0066FF
# define LAVA_RED        0xFF3300


typedef struct s_complex
{
	//		real
	double	x;
	//		i
	double	y;
}				t_complex;

/*
 * IMAGE
 * This is basically a pixels buffer
 * values from mlx_get_data_addr()
*/
typedef struct s_img
{
	void	*img_ptr; //pointer to image struct
	char	*pixels_ptr; //points to the actual pixels
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;


typedef struct s_fractal
{
	char		*name;
	void		*mlx_connection;
	void		*mlx_window;
	t_img		img;
	double		escape_value;
	int			iterations_definition;
}				t_fractal;





// strings utils
int				ft_strncmp(char *s1, char *s2, int n);
void			ft_putstr_fd(char *s, int fd);

// init
void			fractal_init(t_fractal *fractal);

// render
void			fractal_render(t_fractal *fractal);

// math
double			map(double unscaled_num, double new_min, double new_max, \
				double old_max);
t_complex		sum_complex(t_complex z1, t_complex z2);
t_complex		square_comlpex(t_complex z);


#endif
