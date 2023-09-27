/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:46:52 by cgross            #+#    #+#             */
/*   Updated: 2023/09/27 18:42:02 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	valid_value(char **color)
{
	int	i;
	int	j;
	int	rgb[3];

	i = -1;
	while (color[++i])
	{
		rgb[i] = ft_atoi(color[i]);
		if (is_rgb(rgb[i]) != true)
		{
			printf("error: ///////////incorrect rgb color values\n");
			return (false);
		}
		j = -1;
		while (color[i][++j])
		{
			if (is_digit(color[i][j] == false))
			{
				printf("error: incorrect rgb color values\n");
				return (false);
			}
		}
	}
	return (true);
}

char	*space_remover(char *str)
{
	char	*trimmed;
	int		i;
	int		j;

	i = 0;
	j = 0;
	trimmed = malloc(sizeof(char) * (ft_strlen(str) - space_counter(str)));
	if (!trimmed)
		exit(-1);
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		trimmed[j] = str[i];
		i++;
		j++;
	}
	trimmed[j] = '\0';
	return (trimmed);
}

char	*color_strings(char **copy, char c)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	while (copy[++i])
	{
		j = -1;
		while (copy[i][++j])
		{
			if (copy[i][j] == c)
			{
				j++;
				while (is_space(copy[i][j]) == true)
					j++;
				flag = j;
				while (is_space(copy[i][j]) == true || copy[i][j] != '\n')
					j++;
				return (ft_substr(copy[i], flag, j - flag));
			}
		}
	}
	return (NULL);
}

unsigned int	string_to_rgb(char **copy, char flag)
{
	char			*cleanstring;
	char			**color;
	int				rgb[3];
	unsigned int	vrairgb;
	int				i;

	cleanstring = space_remover(color_strings(copy, flag));
	color = ft_split(cleanstring, ',');
	if (valid_value(color) != true)
		exit(-1);
	i = -1;
	while (color[++i])
		rgb[i] = ft_atoi(color[i]);
	vrairgb = 0;
	vrairgb = (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	printf("[%u]\n", vrairgb);
	return (vrairgb);
}
