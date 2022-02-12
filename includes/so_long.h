/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akitty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:14:33 by akitty            #+#    #+#             */
/*   Updated: 2022/02/02 14:14:34 by akitty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h> 
# include <fcntl.h>
# include <stdio.h>

# include "../mlx_folder/mlx.h"

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_window {
	void		*reference;
	t_vector	size;
}	t_window;

typedef struct s_image {
	void		*reference;
	t_vector	size;

	t_vector	position;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}	t_image;

typedef struct map_params
{
	int		coins;
	int		rows;
	int		cols;
	char	*map_str;
	char	**map_arr;
}	t_map;

typedef struct s_enemies
{
	int			anime_timer;
	int			id;
	int			vector;
	t_vector	position;
	void		*next;
}	t_enemies;

typedef struct img_refs
{
	void	*img_0;
	void	*img_1;
	void	*img_2;
	void	*img_3;
	void	*img_4;
	void	*img_5;
	void	*img_6;
	void	*img_7;
	void	*img_current;
}	t_refs;

typedef struct s_hero
{
	t_refs		up_sprites;
	t_refs		down_sprites;
	t_refs		right_sprites;
	t_refs		left_sprites;
	t_refs		*refs_current;
	void		*img_current;
	int			collected;
	int			exit_available;
	t_vector	position;
	t_vector	reset_coords;
}	t_hero;

typedef struct s_game {
	int			time_code;
	char		*error_msg;
	void		*mlx;
	t_map		*map_params;
	t_window	window;
	t_vector	sprite_size;
	t_image		background;
	t_image		exit;
	t_image		open_exit;
	void		*exit_current;
	t_image		walls;
	t_image		gems;
	t_hero		hero;
	int			moves;
	int			enemy_exists;
	t_enemies	*enemy_list;
	t_refs		enemy_imgs;
	int			anime_timer;
	t_refs		boom;
	int			game_over;
	int			death_timer;
}	t_game;

void		free_map(t_map *map_params);
int			ft_close(t_game *game);
t_enemies	*add_enemy(t_enemies *ex, int id, int pos_x, int pos_y);
void		show_moves(t_game *game);
t_map		*check_map(char *filename);
void		map_options(t_game *game, char *filename);

void		open_sprites(t_game *game);
void		open_player_sprites(t_game *game);
char		*ft_strchr(char *s, int c);

void		ft_destroy_window(t_game *game);
int			ft_new_window(t_game *game);
t_image		ft_new_image(void *mlx, int width, int height);
t_image		ft_new_sprite(void *mlx, char *path);

char		*ft_itoa(int n);
void		ft_putstr(char *str);
int			ft_strlen(const char *str);

void		draw_static_items(t_game *game);
int			animations(t_game *game);
int			keys_hook(int keycode, t_game *game);
int			handler_moves(t_game *game, char *next_pos);

enum e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	RESET = 15,
	ESC = 53
};

enum e_bool
{
	TRUE = 1,
	FALSE = 0
};

#endif
