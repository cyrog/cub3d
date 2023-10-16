/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:17:57 by lobertho          #+#    #+#             */
/*   Updated: 2023/10/16 16:28:34 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include "gnl/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include "./mlx/mlx.h"

# define ESC 53
# define W 13
# define S 1
# define A 0
# define D 2
# define LEFT 123
# define RIGHT 124
# define LARGEUR 1080
# define HAUTEUR 720
# define texWidth 64
# define texHeight 64
# define MAPL 24
# define MAPH 24
# define PI 3.1415926535


enum {
		ON_DESTROY = 17
};

static int	g_worldmap[MAPL][MAPH]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

typedef struct s_data {

	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color_floor;
	int		color_ciel;
	int		color_wall;
	int		drawstart;
	int		drawend;
	int		largeur; // LARGEUR
	int		x; // pixelsx
	int		w; //avancer
	int		s; //reculer
	int		a; //aller a gauche
	int		d; //aller a droite
	int		r; //tourner camera a gauche
	int		l; //tourner camera a droite
	int		lineHeight; // hauteur du mur
	int		hit; // si un mur est hit == 1 sinon 0
	int		hitside; // direction du mur touche
	int		mapX; //position du ray dans le square de la map en X
	int		mapY; //position du ray dans le square de la map en Y
	int		stepX; //direction ou aller en X
	int		stepY; //direction ou aller en Y
	int		texNum; //position du current square
	int		texnb; // numero de la texture
	double	step; // calcul augmentation coordonnee texture par pixel
	double	texpos; // coordonnees texure
	double	wallX; //position exact ou le mur est toucher
	double	texX; // position en X de la texture
	double	texY; // pos en Y texture
	double	posX; //position du joueur en X
	double	posY; //position du joueur en Y
	double	dirX; //direction du joueur en X
	double	dirY; //direction du joueur en Y
	double	planeX; //camera du joueur en X perpendiculaire a la direction
	double	planeY; //camera du joueur en Y perpendiculaire a la direction
	double	raydirX; //direction du ray en X
	double	raydirY; //direction du ray en Y
	double	cameraX; //position de la camera sur l'ecran
	double	sideDistX; //distance du ray jusqu au prochain square en X
	double	sideDistY; //distnace du ray jusqu'au prochain square en Y
	double	deltaDistX; //distance du ray pour traverser un square d'un X a l'autre
	double	deltaDistY; //distance du ray pour traverser un square d'un Y a l'autre
	double	WallDist; //distnace entre le mur et la camera joueur
	double	h; // hauteur de la fenetre
	double	movespeed; //vitesse de deplacement
	double	rotspeed; //vitesse de rotation de la camera
	int		map_h;
	int		map_l;
	int		**map;
	int		player_posX;
	int		player_posY;
	char	*no_wall;
	char	*so_wall;
	char	*we_wall;
	char	*ea_wall;
}	t_data;

int	ft_kpress(int key, t_data *img);
int	ft_krelease(int key, t_data *s);
int	ft_exit(void);
int	ft_refresh(t_data *s);
int	ft_moove(t_data *s);
int	mooverl(t_data *s);
int	moovead(t_data *s);
int	moovews(t_data *s);

void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
void	init_raycast(t_data *s);
void	cub(t_data *s);
void	initcub(t_data *s, char **copy);
void	filecub(t_data *s, char **copy);
void	init_directions(t_data *s);
void	dda_and_height(t_data *s);
void	draw_walls(t_data *s);


char	**copy_fd(int argc, char **argv);
int		open_fd(int argc, char **argv);
bool	check_validarg(int argc, char **argv);
bool	color_format(char **copy);
char	*color_strings(char **copy, char c);

int				ft_atoi(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			free_tab(char **str);
char			**ft_split(char const *str, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*get_next_line(int fd);
char			*gnl_custom(int fd);
int				parse_textures(char *file);
int				parse_color(char *file);
bool			get_to_firstline(char **copy);
int				return_check_args(char **copy);
unsigned int	string_to_rgb(char **copy, char flag);
bool			valid_value(char **color);

int		space_counter(char *str);
bool	is_space(char c);
bool	is_digit(char c);
bool	is_rgb(int rgb);
char	*space_remover(char *str);
int		ft_strcmp(char *str1, char *str2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1, int max_len);

int		map_first_line(char **copy);
int		hauteur_map(char **copy);
int		largeur_map(char **copy);
char	**map_copy(char **copy);
int		**map_init(t_data *data, char **copy);

char	*textures_path(char **copy, char *flag);
char	*get_path(char *line, int start);
bool	valid_texture(char *path);

bool	find_player(int **map, t_data *s);
void	rec_fill(int **map, t_data *s, int target, int h, int l);
void	fill_it(int **map, t_data *s);
#endif
