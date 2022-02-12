/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akitty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:17:08 by akitty            #+#    #+#             */
/*   Updated: 2022/02/02 14:17:09 by akitty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	enemy_sprites(t_game *game)
{
	if (game->enemy_exists == FALSE)
		return (1);
	game->enemy_imgs.img_0 = mlx_xpm_file_to_image(game->mlx,
			"sprites/enemy/enemy3.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->enemy_imgs.img_1 = mlx_xpm_file_to_image(game->mlx,
			"sprites/enemy/enemy1.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->enemy_imgs.img_2 = mlx_xpm_file_to_image(game->mlx,
			"sprites/enemy/enemy0.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->enemy_imgs.img_3 = mlx_xpm_file_to_image(game->mlx,
			"sprites/enemy/enemy2.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	if (!game->enemy_imgs.img_0
		|| !game->enemy_imgs.img_1
		|| !game->enemy_imgs.img_2
		|| !game->enemy_imgs.img_3)
		return (0);
	game->enemy_imgs.img_current = game->enemy_imgs.img_0;
	return (1);
}

static int	open_death_1(t_game *game)
{
	game->boom.img_0 = mlx_xpm_file_to_image(game->mlx,
			"sprites/boom/boom0.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->boom.img_1 = mlx_xpm_file_to_image(game->mlx,
			"sprites/boom/boom1.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->boom.img_2 = mlx_xpm_file_to_image(game->mlx,
			"sprites/boom/boom2.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->boom.img_3 = mlx_xpm_file_to_image(game->mlx,
			"sprites/boom/boom3.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	if (!game->boom.img_0
		|| !game->boom.img_1
		|| !game->boom.img_2
		|| !game->boom.img_3)
		return (0);
	return (1);
}

static int	open_death_2(t_game *game)
{
	game->boom.img_4 = mlx_xpm_file_to_image(game->mlx,
			"sprites/boom/boom4.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->boom.img_5 = mlx_xpm_file_to_image(game->mlx,
			"sprites/boom/boom5.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->boom.img_6 = mlx_xpm_file_to_image(game->mlx,
			"sprites/boom/boom6.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->boom.img_7 = mlx_xpm_file_to_image(game->mlx,
			"sprites/boom/boom7.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	if (!game->boom.img_4
		|| !game->boom.img_5
		|| !game->boom.img_6
		|| !game->boom.img_7)
		return (0);
	return (1);
}

static int	another_sprites(t_game *game)
{
	game->background.reference = mlx_xpm_file_to_image(game->mlx,
			"sprites/bg3.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->walls.reference = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall_small.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->exit.reference = mlx_xpm_file_to_image(game->mlx,
			"sprites/blackhole.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->open_exit.reference = mlx_xpm_file_to_image(game->mlx,
			"sprites/blackhole_green.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->gems.reference = mlx_xpm_file_to_image(game->mlx,
			"sprites/gem.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->exit_current = game->exit.reference;
	if (!game->background.reference
		|| !game->walls.reference
		|| !game->exit.reference
		|| !game->open_exit.reference
		|| !game->gems.reference)
		return (0);
	return (1);
}

void	open_sprites(t_game *game)
{
	if (!enemy_sprites(game)
		|| !open_death_1(game)
		|| !open_death_2(game)
		|| !another_sprites(game))
	{
		game->error_msg = "Error.\nFail during opening sprites. Arrivederci!\n";
		ft_close(game);
	}
	open_player_sprites(game);
}
