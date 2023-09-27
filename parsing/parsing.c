/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:46:52 by cgross            #+#    #+#             */
/*   Updated: 2023/09/27 15:50:26 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (true);
	return (false);
}

bool	line_isspace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' || str[i] != '\t')
			return (false);
	}
	return (true);

}

char	*color_strings(char **copy, char c)
{
	int	i;
	int	j;
	int	flag;
	char *colorstr;

	i = 0;
	while (copy[i++])
	{
		j = 0;
		if (line_isspace(copy[i]) == true)
			i++;
		while (copy[i][j++])
		{
			if (copy[i][j] == c)
			{
				while (is_space(copy[i][j++]) == true)
					flag = j;
				if (is_space(copy[i][j]) == false)
				{
					colorstr = ft_substr(copy[i], j, j - flag);
					return (colorstr);
				}
			}
		}
	}
	printf("test\n");
	return (NULL);
}
