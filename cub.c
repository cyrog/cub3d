/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:43:30 by lobertho          #+#    #+#             */
/*   Updated: 2023/10/20 17:26:20 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initcub(t_data *s, char **copy)
{
	s->posX = 22;
	s->posY = 12;
	s->dirX = -1;
	s->dirY = 0;
	s->planeX = 0;
	s->planeY = 0.66;
	s->movespeed = 0.09;
	s->rotspeed = 0.03;
	s->a = 0;
	s->d = 0;
	s->w = 0;
	s->s = 0;
	s->l = 0;
	s->r = 0;
	s->map_h = hauteur_map(copy);
	s->map_l = largeur_map(copy);
}

void	filecub(t_data *s, char **copy)
{
	s->color_ciel = string_to_rgb(copy, 'C');
	s->h = HAUTEUR;
	s->largeur = LARGEUR;
	s->color_ciel = string_to_rgb(copy, 'C');
	s->color_floor = string_to_rgb(copy, 'F');
	s->color_wall = 0x00FF0000;
	s->no_wall = textures_path(copy, "NO");
	s->so_wall = textures_path(copy, "SO");
	s->ea_wall = textures_path(copy, "EA");
	s->we_wall = textures_path(copy, "WE");
	//valid texture ?
}

int	ft_refresh(t_data *s)
{
	ft_moove(s);
	cub(s);
	return (0);
}


void	cub(t_data *s)
{
	s->x = 0;
	while (s->x < s->map_l)
	{
		init_raycast(s);
		init_directions(s);
		dda_and_height(s);
		draw_walls(s);
		s->x++;
	}
	mlx_put_image_to_window(s->mlx, s->mlx_win,	s->img, 0, 0);
}
