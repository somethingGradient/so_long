/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akitty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 21:28:52 by akitty            #+#    #+#             */
/*   Updated: 2022/01/17 21:28:53 by akitty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	write_in_array(char ***map, char *str)
{
	int	coins;
	int	k;
	int	j;

	coins = 0;
	k = 0;
	j = 0;
	while (*str)
	{
		if (*str == '\n')
		{
			j = 0;
			k++;
			str++;
		}
		if (*str == 'C')
			coins++;
		(*map)[k][j++] = *str;
		str++;
	}
	(*map)[k + 1] = 0;
	return (coins);
}

static int	create_arr(t_map *map_params)
{
	char	**map;
	int		rows;
	int		cols;

	rows = map_params->rows;
	cols = map_params->cols;
	map = (char **)malloc((rows + 1) * cols);
	if (!map)
		return (0);
	while (rows-- > 0)
	{
		map[rows] = (char *)malloc(cols);
		map[rows][cols] = '\0';
		if (!map[rows])
			return (0);
	}
	map_params->coins = write_in_array(&map, map_params->map_str);
	free(map_params->map_str);
	map_params->map_str = NULL;
	map_params->map_arr = map;
	return (1);
}

static int	check_enemies(t_game *game)
{
	t_enemies	*enemies;
	int			x;
	int			y;
	int			id;

	x = -1;
	y = -1;
	id = 0;
	enemies = NULL;
	while (game->map_params->map_arr[++y])
	{
		x = -1;
		while (game->map_params->map_arr[y][++x])
		{
			if (game->map_params->map_arr[y][x] == 'e')
			{
				enemies = add_enemy(enemies, ++id, x, y);
				if (enemies == NULL)
					return (0);
				game->enemy_exists = TRUE;
			}
		}
	}
	game->enemy_list = enemies;
	return (1);
}

static void	player_setup(t_game *game)
{
	int		x;
	int		y;

	game->moves = 0;
	game->hero.collected = 0;
	game->game_over = FALSE;
	y = -1;
	while (game->map_params->map_arr[++y])
	{
		x = -1;
		while (game->map_params->map_arr[y][++x])
		{
			if (game->map_params->map_arr[y][x] == 'P')
			{
				game->hero.position.x = x * game->sprite_size.x;
				game->hero.position.y = y * game->sprite_size.y;
				return ;
			}
		}
	}
}

void	map_options(t_game *game, char *filename)
{
	t_map	*map_options;

	map_options = NULL;
	game->enemy_list = NULL;
	game->enemy_exists = FALSE;
	game->death_timer = 0;
	game->anime_timer = 0;
	game->error_msg = "Normal closure. Good bye!\n";
	map_options = check_map(filename);
	if (!map_options
		|| !create_arr(map_options))
	{
		game->error_msg = "Error.\nFail during setting map. Ciao!\n";
		perror("System error");
		ft_close(game);
	}
	game->map_params = map_options;
	player_setup(game);
	if (!check_enemies(game))
	{
		game->error_msg = "Error.\nFail during setting enemies. Ciao!\n";
		ft_close(game);
	}
}
