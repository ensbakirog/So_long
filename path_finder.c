/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakirog <ebakirog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:58:16 by ebakirog          #+#    #+#             */
/*   Updated: 2023/12/09 16:58:18 by ebakirog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries/ft_printf/ft_printf.h"
#include "so_long.h"
#include <stdlib.h>

void	map_cpy(t_path *path, t_game *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			path->map[i][j] = data->map[i][j];
		}
	}
}

void	recursive_path_move(t_path *path, int x, int y)
{
	path->map[y][x] = 'X';
	if (x > 0 && path->map[y][x - 1] != '1' && path->map[y][x - 1] != 'X')
	{
		recursive_path_move(path, x - 1, y);
	}
	if (y < path->height - 1 && path->map[y + 1][x] != '1' && path->map[y
		+ 1][x] != 'X')
	{
		recursive_path_move(path, x, y + 1);
	}
	if (y > 0 && path->map[y - 1][x] != '1' && path->map[y - 1][x] != 'X')
	{
		recursive_path_move(path, x, y - 1);
	}
	if (x < path->width - 1 && path->map[y][x + 1] != '1' && path->map[y][x
		+ 1] != 'X')
	{
		recursive_path_move(path, x + 1, y);
	}
}

void	path_check(t_path *path, t_game *data)
{
	int	i;
	int	j;
	int	ce_count;

	ce_count = path->collectibles + 1;
	i = -1;
	while (path->map[++i])
	{
		j = -1;
		while (path->map[i][++j])
		{
			if ((data->map[i][j] == 'C' || data->map[i][j] == 'E')
				&& path->map[i][j] == 'X')
				ce_count--;
		}
	}
	if (ce_count == 0)
		return ;
	else
	{
		ft_printf("Error\nMap is not correct.\n");
		exit(1);
	}
}

void	ft_path_f(t_game data)
{
	t_path	path;
	int		i;

	i = -1;
	path.height = get_map_height(data.map);
	path.width = get_map_width(data.map);
	path.map = malloc(sizeof(char *) * (path.height + 1));
	if (!path.map)
		malloc_error();
	path.map[path.height] = NULL;
	while (++i < path.height)
	{
		path.map[i] = malloc(sizeof(char) * (path.width + 1));
		if (!path.map[i])
			malloc_error();
		path.map[i][path.width] = '\0';
	}
	map_cpy(&path, &data);
	path_f_player(&path);
	path_f_collectiable(&path);
	recursive_path_move(&path, path.x_index, path.y_index);
	path_check(&path, &data);
}
