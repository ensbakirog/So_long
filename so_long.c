/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakirog <ebakirog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 06:07:00 by ebakirog          #+#    #+#             */
/*   Updated: 2023/12/09 17:06:26 by ebakirog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libraries/ft_printf/ft_printf.h"
#include "./minilibx/mlx.h"
#include "so_long.h"
#include <stdlib.h>

void	check_if(t_game *data)
{
	if (!data->map || !check_map_characters(data->map)
		|| !check_map_rectangular(data->map) || !check_map_borders(data->map)
		|| !check_player_count(data->map) || !check_exit_count(data->map))
		exit(1);
}

void	find_player_position(t_game *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->player_x = x * UNIT;
				data->player_y = y * UNIT;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	player(t_game *data)
{
	int	img_width;
	int	img_height;

	img_width = UNIT;
	img_height = UNIT;
	data->player_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/IMG-0062_1_.xpm", &img_width, &img_height);
	if (!data->player_img)
	{
		ft_printf("Error\nLoading player image.\n");
		exitt(data);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->player_img,
		data->player_x, data->player_y);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	data;
	int		map_width;
	int		map_height;

	data.move_count = 0;
	if (ac == 2)
	{
		check_file_extension(av[1]);
		data.map = read_map(av[1]);
		check_if(&data);
		ft_path_f(data);
		map_width = get_map_width(data.map);
		map_height = get_map_height(data.map);
		data.mlx_ptr = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx_ptr, UNIT * map_width, UNIT
					* map_height, "So_long");
		draw_background(&data);
		find_player_position(&data);
		player(&data);
		mlx_hook(data.mlx_win, 17, 0, exitt, &data);
		mlx_hook(data.mlx_win, 2, 0, key_handle, &data);
		mlx_loop(&data);
	}
	return (ft_printf("Error\nWrong arguman number.\n"), 0);
}
