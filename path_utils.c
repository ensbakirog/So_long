/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakirog <ebakirog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:54:12 by ebakirog          #+#    #+#             */
/*   Updated: 2023/12/09 17:11:49 by ebakirog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries/ft_printf/ft_printf.h"
#include "so_long.h"
#include <stdlib.h>

void	path_f_player(t_path *path)
{
	int	i;
	int	j;

	i = 0;
	while (path->map[i])
	{
		j = 0;
		while (path->map[i][j])
		{
			if (path->map[i][j] == 'P')
			{
				path->x_index = j;
				path->y_index = i;
			}
			j++;
		}
		i++;
	}
}

void	path_f_collectiable(t_path *path)
{
	int	i;
	int	j;

	i = 0;
	path->collectibles = 0;
	while (path->map[i])
	{
		j = 0;
		while (path->map[i][j])
		{
			if (path->map[i][j] == 'C')
				path->collectibles++;
			j++;
		}
		i++;
	}
}

void	malloc_error(void)
{
	ft_printf("Error\nMalloc error.\n");
	exit(1);
}
