/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_static_items.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akitty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:21:35 by akitty            #+#    #+#             */
/*   Updated: 2022/02/02 14:21:37 by akitty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	draw_background(t_game *game, int rows, int cols)
{
	int	temp;

	temp = cols;
	while (rows >= 0)
	{
		cols = temp;
		while (cols >= 0)
		{
			game->background.position.x = cols;
			game->background.position.y = rows;
			mlx_put_image_to_window(game->mlx, game->window.reference,
				game->background.reference,
				game->background.position.x, game->background.position.y);
			cols -= game->sprite_size.x;
		}
		rows -= game->sprite_size.y;
	}
	return (1);
}

static int	draw_walls(t_game *game, int rows, int cols)
{
	char	**map;
	int		temp;

	map = game->map_params->map_arr;
	temp = cols;
	while (--rows >= 0)
	{
		cols = temp;
		while (--cols >= 0)
		{
			if (map[rows][cols] == '1')
			{
				game->walls.position.x = cols * game->sprite_size.x;
				game->walls.position.y = rows * game->sprite_size.y;
				mlx_put_image_to_window(game->mlx, game->window.reference,
					game->walls.reference,
					game->walls.position.x, game->walls.position.y);
			}
		}
	}
	return (1);
}

static int	draw_exit(t_game *game, int rows, int cols)
{
	char	**map;
	int		temp;

	map = game->map_params->map_arr;
	temp = cols;
	while (--rows >= 0)
	{
		cols = temp;
		while (--cols >= 0)
		{
			if (map[rows][cols] == 'E')
			{
				game->exit.position.x = cols * game->sprite_size.x;
				game->exit.position.y = rows * game->sprite_size.y;
				mlx_put_image_to_window(game->mlx, game->window.reference,
					game->exit_current,
					game->exit.position.x, game->exit.position.y);
			}
		}
	}
	return (1);
}

static int	draw_gems(t_game *game, int rows, int cols)
{
	char	**map;
	int		temp;

	map = game->map_params->map_arr;
	temp = cols;
	while (--rows >= 0)
	{
		cols = temp;
		while (--cols >= 0)
		{
			if (map[rows][cols] == 'C')
			{
				game->gems.position.x = cols * game->sprite_size.x;
				game->gems.position.y = rows * game->sprite_size.y;
				mlx_put_image_to_window(game->mlx, game->window.reference,
					game->gems.reference,
					game->gems.position.x, game->gems.position.y);
			}
		}
	}
	return (1);
}

void	draw_static_items(t_game *game)
{
	int	rows;
	int	cols;
	int	res_bg;

	rows = game->map_params->rows;
	cols = game->map_params->cols;
	res_bg = draw_background(game,
			(rows - 1) * game->sprite_size.y,
			(cols - 1) * game->sprite_size.x);
	if (!res_bg
		|| !draw_walls(game, rows, cols)
		|| !draw_exit(game, rows, cols)
		|| !draw_gems(game, rows, cols))
	{
		printf("%s", "Error.\nFail during drawing STATIC items. Ciao!\n");
		ft_close(game);
	}
}
