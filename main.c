/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:03:03 by lobertho          #+#    #+#             */
/*   Updated: 2023/10/20 16:38:51 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data *img;

	img = (t_data *)malloc(sizeof(t_data));
	if (!img)
		return (-1);
/*	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, LARGEUR, HAUTEUR, "cub3d");
	img->img = mlx_new_image(img->mlx, LARGEUR, HAUTEUR);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
					&img->line_length, &img->endian);
					*/
	char **copy = copy_fd(argc, argv);
	initcub(img, copy);
	filecub(img, copy);
	int	**map_int;
	char **map;
	map = map_copy(copy);
	map_int = map_init(img, map);
	//map_int = map_init(img, map);
//	fill_it(map, img);
	/*
	cub(img);
	mlx_hook(img->mlx_win, 2, (1L << 0), ft_kpress, img);
	mlx_hook(img->mlx_win, 3, (1L << 1), ft_krelease, img);
	mlx_hook(img->mlx_win, ON_DESTROY, 0, ft_exit, img);
	mlx_loop_hook(img->mlx, ft_refresh, img);
	mlx_loop(img->mlx);
	*/
}
