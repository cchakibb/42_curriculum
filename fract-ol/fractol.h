/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:16:34 by chbachir          #+#    #+#             */
/*   Updated: 2024/05/22 13:31:52 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> //TODO Debugging
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx-linux/mlx.h"

#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\""

typedef struct 	s_img
{
	void	*img_ptr;
	char	*pixls_ptr;
	int		bpp;
	int		endian; //No need, remove
	int		line_len;
}				t_img;


typedef struct 	s_fractal
{
	void		*mlx_connection;
	void		*mlx_window;
	t_img		img;
}				t_fractal;





// strings utils
int		ft_strncmp(char *s1, char *s2, int n);
void	ft_putstr_fd(char *s, int fd);


#endif
