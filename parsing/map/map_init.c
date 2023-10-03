#include "cub3d.h"


//wrong, need convert char_copy in int and lets go
int	**map_init(t_data *s, char **copy)
{
	int	h;
	int	l;
	int	**map;

	int	hauteur = hauteur_map(copy);
	int	largeur = largeur_map(copy);
	map = (int**)malloc(sizeof(int*) * hauteur);
	if (!map)
		return (NULL);
	h = -1;
	printf("/////////////////////////////\n");
	printf("test\n");
	while (++h < s->map_h)
	{
		l = -1;
		map[h] = (int*)malloc(sizeof(int*) * largeur);
	//	printf("test/////////////////////\n");
		while (copy[h][++l] && copy[h][++l] != '\n')
		{
			map[h][l] = ft_atoi(copy[h]);
			printf("%d", map[h][l]);
		}
		printf("\n");
	}
	return (map);
}
