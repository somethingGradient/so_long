/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akitty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:13:33 by akitty            #+#    #+#             */
/*   Updated: 2022/02/02 14:13:38 by akitty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	move_down(t_game *game, int y, int x)
{
	char	**map;

	game->hero.refs_current = &game->hero.down_sprites;
	map = game->map_params->map_arr;
	if (!handler_moves(game, &(map[y + 1][x])))
		return ;
	game->hero.position.y += game->sprite_size.y;
}

static void	move_up(t_game *game, int y, int x)
{
	char	**map;

	map = game->map_params->map_arr;
	game->hero.refs_current = &game->hero.up_sprites;
	if (!handler_moves(game, &(map[y - 1][x])))
		return ;
	game->hero.position.y -= game->sprite_size.y;
}

static void	move_right(t_game *game, int y, int x)
{
	char	**map;

	map = game->map_params->map_arr;
	game->hero.refs_current = &game->hero.right_sprites;
	if (!handler_moves(game, &(map[y][x + 1])))
		return ;
	game->hero.position.x += game->sprite_size.x;
}

static void	move_left(t_game *game, int y, int x)
{
	char	**map;

	map = game->map_params->map_arr;
	game->hero.refs_current = &game->hero.left_sprites;
	if (!handler_moves(game, &(map[y][x - 1])))
		return ;
	game->hero.position.x -= game->sprite_size.x;
}

int	keys_hook(int keycode, t_game *game)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->hero.position.x / 60;
	pos_y = game->hero.position.y / 60;
	if (game->game_over == TRUE)
		return (0);
	if (keycode == ESC)
		ft_close(game);
	else if (keycode == KEY_DOWN)
		move_down(game, pos_y, pos_x);
	else if (keycode == KEY_UP)
		move_up(game, pos_y, pos_x);
	else if (keycode == KEY_RIGHT)
		move_right(game, pos_y, pos_x);
	else if (keycode == KEY_LEFT)
		move_left(game, pos_y, pos_x);
	return (1);
}
