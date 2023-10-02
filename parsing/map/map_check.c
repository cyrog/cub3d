/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:48:30 by cgross            #+#    #+#             */
/*   Updated: 2023/10/01 00:04:36 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	first_line_check(char *copy)
{
	int	i;

	i = -1;
	while (copy[++i])
	{
		printf("copy[i] : [%s] ", copy);
		while (is_space(copy[i]))
			++i;
		if (copy[i] != '1' || copy[i] != ' ' || copy[i] == '\n')
		{
			printf("i :[%d]\n", i);
			printf("[%c]", copy[i]);
			return (false);
		}
	}
	return (true);
}

int		return_check_args(char **copy)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	flag = 0;
	while (copy[++i] && flag < 6)
	{
		j = -1;
		while (copy[i][++j])
		{
			while (is_space(copy[i][j]))
				j++;
			if ((copy[i][j] == 'N' && copy[i][++j] == 'O')
				|| (copy[i][j] == 'S' && copy[i][++j] == 'O')
				|| (copy[i][j] == 'W' && copy[i][++j] == 'E')
				|| (copy[i][j] == 'E' && copy[i][++j] == 'A')
				|| (copy[i][j] == 'F' || copy[i][j] == 'C'))
				flag++;
		}
	}
	if (flag != 6)
		printf("Error\nneed 6 map elements before map\n");
	return (i);
}

bool	get_to_firstline(char **copy)
{
	int	i;	//line
	int	j;	//line len
	int	start;

	i = return_check_args(copy);
	printf("i = [%d]\n", i);
	if (i < 6)
		return (false);
	while (copy[++i])
	{
		j = -1;
		while (copy[i][++j] && copy[i][++j] != '\n')
		{
			if (copy[i][j] == '1')
			{
				start = i;
				printf("%d\n", start);
				//printf("[%s][%d]", copy[start], start);
				//printf("test[%c][%d]", copy[start][j], start);
				if (!first_line_check(copy[start]))
					return (false);
			}
		}
	}
	printf("test\n");
	return (true);
}
