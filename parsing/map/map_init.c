#include "cub3d.h"

int	**map_init(t_data *s, char **copy)
{
	int	start;
	int	h;
	int	l;
	int	**map;

	map = map_zero(copy);
	start = map_first_line(copy);
	h = -1;
	while (++h < s->map_h)
	{
		l = -1;
		while (++l < s->map_l)
		{
			if (copy[start][l] == '1')
				map[h][l] = 1;
			else if (copy[start][l] == 'N')
				map[h][l] = 2;
			else if (copy[start][l] == 'S')
				map[h][l] = 3;
			else if (copy[start][l] == 'W')
				map[h][l] = 4;
			else if (copy[start][l] == 'E')
				map[h][l] = 5;
			printf("%d", map[h][l]);
		}
		start++;
		printf("\n");
	}
	return (map);
}
