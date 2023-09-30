/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:48:30 by cgross            #+#    #+#             */
/*   Updated: 2023/09/30 14:20:22 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	map_check(char **copy)
{
	int	i;	//line
	int	j;	//line len

	i = -1;
	while (copy[++i])
	{
		j = -1;
		while (copy[i][++j])
		{
			while (is_space(copy[i][j])
				j++;
			if (copy[i][j] == '1' || copy[i][j] == '0'))

	}
}
