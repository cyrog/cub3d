#include "cub3d.h"

int	convert(char c)
{
	if (c == 'N')
		return (2);
	else if (c == 'S')
		return (3);
	else if (c == 'E')
		return (4);
	else if (c == 'W')
		return (5);
	return (0);

}

//wrong, need convert char_copy in int and lets go
int	**map_init(t_data *s, char **map_c)
{
	int	h;
	int	l;
	int	**map;

	map = (int**)malloc(sizeof(int*) * s->map_h);
	if (!map)
		return (NULL);
	h = -1;
	while (++h < s->map_h)
	{
		l = -1;
		map[h] = (int*)malloc(sizeof(int*) * s->map_l);
		while (++l < s->map_l && map_c[h][l] != '\n')
		{
			if (map_c[h][l] == '1')
				map[h][l] = 1;
			else if (map_c[h][l] == '0')
				map[h][l] = 0;
			else
			{
			   map[h][l] = convert(map_c[h][l]);
	//		   s->posx = h;
	//		   s->posx = l;
			}
			printf("%d", map[h][l]);
		}
		printf("\n");
	}
	return (map);
}
