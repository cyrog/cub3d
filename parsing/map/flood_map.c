#include "cub3d.h"

bool	find_player(int **map, t_data *s)
{
	int	h;
	int	l;

	h = -1;
	while (++h < s->map_h)
	{
		l = -1;
		while (++l < s->map_l)
		{
			if (map[h][l] > 1)
			{
				s->player_posX = l;
				s->player_posY = h;
				return (true);
			}
		}
	}
	return (false);
}

void	rec_fill(int **map, t_data *s, int target, int h, int l)
{
	if (h < 0 || l < 0 ||  h > s->map_h || l > s->map_l)
		return ;
	if (map[h][l] != target)
		return ;
	map[h][l] = 8;
	printf("%d\n", h);
	printf("%d\n", l);
	rec_fill(map, s, target, h + 1, l);
	rec_fill(map, s, target, h - 1, l);
	rec_fill(map, s, target, h, l - 1);
	rec_fill(map, s, target, h, l + 1);
}

void	flood_it(int **map, t_data *s)
{
	int	target;

	target = map[s->player_posY][s->player_posX];
	rec_fill(map, s, target, s->player_posY, s->player_posX);
}

void	fill_it(int **map, t_data *s)
{
	int	i;
	int	j;
	
	if (!find_player(map, s))
	{
		printf("no player found\n");
		return ;
	}
	flood_it(map, s);
	i = -1;
	printf("///////////////////\n");
	while (++i < s->map_h)
	{
		j = -1;
		while (++j < s->map_l)
			printf("%d", map[i][j]);
		printf("\n");
	}
}
