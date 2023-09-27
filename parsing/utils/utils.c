/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:58:20 by cgross            #+#    #+#             */
/*   Updated: 2023/09/27 17:58:30 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (true);
	return (false);
}

int		space_counter(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			count++;
		i++;
	}
	return (count);
}
