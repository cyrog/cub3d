#include "cub3d.h"

int	map_first_line(char **copy)
{
	int	i;
	int	j;

	i = 5;
	while (copy[++i])
	{
		j = -1;
		while (copy[i][++j])
		{
			while (is_space(copy[i][j]))
				j++;
			if (copy[i][j] == '1')
				return (i);
		}
	}
	printf("Error\nno map found\n");
	return (-1);
}

int	hauteur_map(char **copy)
{
	int start;
	int	end;

	start = map_first_line(copy);
	if (start < 6)
		return (-1);
	end = 0;
	while (copy[start++])
		end++;
	return (end);
}

int	largeur_map(char **copy)
{
	int	max_len;
	int	start;
	int	j;

	start = map_first_line(copy) - 1;
	if (start < 0)
		return (-1);
	max_len = 0;
	while (copy[++start])
	{
		j = -1;
		while (copy[start][++j])
			if (max_len < j)
				max_len = j;
	}
	return (max_len);
}

int	**map_zero(char **copy)
{
	int	**zero;
	int	largeur;
	int	hauteur;
	int	i;
	int	j;

	hauteur = hauteur_map(copy);
	largeur = largeur_map(copy);
	zero = (int**)malloc(sizeof(int*) * hauteur);
	if (!zero)
		return (NULL);
	i = -1;
	while (++i < hauteur)
	{
		j = -1;
		zero[i] = (int*)malloc(sizeof(int) * largeur);
		while (++j < largeur)
			zero[i][j] = 0;
	}
	return (zero);
}
