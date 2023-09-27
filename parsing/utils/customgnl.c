/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customgnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:51:17 by cgross            #+#    #+#             */
/*   Updated: 2023/09/27 15:49:22 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*gnl_custom(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL && ft_strcmp(line, "\n") == 0)
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}
