/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:46:37 by cgross            #+#    #+#             */
/*   Updated: 2023/10/03 17:10:33 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strdup(char *s1, int max_len)
{
	int	i;
	int	len;
	char	*dup;

	len = ft_strlen(s1);
	dup = malloc(sizeof(char) * max_len);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < max_len)
	{
		while (i < len && s1[i] != '\n' && s1[i])
		{
			if (s1[i] == ' ')
				dup[i] = '0';
			else
				dup[i] = s1[i];
			i++;
		}
		dup[i] = '0';
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
