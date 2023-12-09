/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakirog <ebakirog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 06:06:52 by ebakirog          #+#    #+#             */
/*   Updated: 2023/12/09 16:57:15 by ebakirog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define UNIT 64

typedef struct s_game
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		player_x;
	int		player_y;
	void	*player_img;
	char	**map;
	void	*floor_img;
	void	*wall_img;
	void	*collectible_img;
	void	*exit_img;
	int		collectibles_left;
	int		move_count;
}			t_game;

typedef struct s_path
{
	char	**map;
	int		x_index;
	int		y_index;
	int		collectibles;
	int		height;
	int		width;
}			t_path;

char		**read_map(char *file);
int			check_map_borders(char **map);
int			check_player_count(char **map);
int			check_exit_count(char **map);
int			check_map_characters(char **map);
int			check_map_rectangular(char **map);
int			check_file_extension(char *filename);
void		draw_background(t_game *data);
int			exitt(t_game *data);
int			key_handle(int key, t_game *data);
int			get_map_height(char **map);
int			get_map_width(char **map);
int			count_collectibles(char **map);
void		path_f_player(t_path *path);
void		path_f_collectiable(t_path *path);
void		ft_path_f(t_game data);
void		malloc_error(void);
#endif
