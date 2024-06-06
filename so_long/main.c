/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:52:29 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/06 14:52:30 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "so_long.h"

int	main(int ac, char **ar)
{
	t_pos		pos;
	t_vars		vars;
	t_mapdata	data;

	if (ac != 2)
		return (0);
	find_error (&vars, ar);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window (vars.mlx, vars.map.data.count * SIZE, \
			vars.map.data.num_nextline * SIZE, "so_long" );
	vars.img = mlx_new_image (vars.mlx, vars.map.data.count * SIZE, \
			vars.map.data.num_nextline * SIZE);
	vars.addr = mlx_get_data_addr (vars.img, &vars.bits_per_pixel, \
			&vars.line_length, &vars.endian);
	load_images (&vars);
	draw_background(&vars);
	draw_map(&vars);
	mlx_key_hook (vars.win, key_hook, &vars);
	mlx_hook (vars.win, 17, 1L << 0, close_window, &vars);
	mlx_loop (vars.mlx);
}

int	ft_strcmp(char *str)
{
	char	*str1;
	int		i;

	i = 0;
	str1 = ".ber";
	while (str[i])
	{
		if (str[i] != str1[i])
			error ("Error\n :please enter.ber file only\n", NULL, -1);
		i ++;
	}
	return (1);
}
