/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_player_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akitty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:17:16 by akitty            #+#    #+#             */
/*   Updated: 2022/02/02 14:17:18 by akitty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	up_sprites(t_game *game)
{
	game->hero.up_sprites.img_0 = mlx_xpm_file_to_image(game->mlx,
			"sprites/ship/up/ship0.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->hero.up_sprites.img_1 = mlx_xpm_file_to_image(game->mlx,
			"sprites/ship/up/ship1.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->hero.up_sprites.img_2 = mlx_xpm_file_to_image(game->mlx,
			"sprites/ship/up/ship2.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->hero.up_sprites.img_3 = mlx_xpm_file_to_image(game->mlx,
			"sprites/ship/up/ship3.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	if (!game->hero.up_sprites.img_0
		|| !game->hero.up_sprites.img_1
		|| !game->hero.up_sprites.img_2
		|| !game->hero.up_sprites.img_3)
		return (0);
	return (1);
}

static int	down_sprites(t_game *game)
{
	game->hero.down_sprites.img_0 = mlx_xpm_file_to_image(game->mlx,
			"sprites/ship/down/down0.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->hero.down_sprites.img_1 = mlx_xpm_file_to_image(game->mlx,
			"sprites/ship/down/down1.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->hero.down_sprites.img_2 = mlx_xpm_file_to_image(game->mlx,
			"sprites/ship/down/down2.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->hero.down_sprites.img_3 = mlx_xpm_file_to_image(game->mlx,
			"sprites/ship/down/down3.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	if (!game->hero.down_sprites.img_0
		|| !game->hero.down_sprites.img_1
		|| !game->hero.down_sprites.img_2
		|| !game->hero.down_sprites.img_3)
		return (0);
	return (1);
}

static int	right_sprites(t_game *game)
{
	game->hero.right_sprites.img_0 = mlx_xpm_file_to_image(game->mlx,
			"sprites/ship/right/right0.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->hero.right_sprites.img_1 = mlx_xpm_file_to_image(game->mlx,
			"sprites/ship/right/right1.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->hero.right_sprites.img_2 = mlx_xpm_file_to_image(game->mlx,
			"sprites/ship/right/right2.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->hero.right_sprites.img_3 = mlx_xpm_file_to_image(game->mlx,
			"sprites/ship/right/right3.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	if (!game->hero.right_sprites.img_0
		|| !game->hero.right_sprites.img_1
		|| !game->hero.right_sprites.img_2
		|| !game->hero.right_sprites.img_3)
		return (0);
	return (1);
}

static int	left_sprites(t_game *game)
{
	game->hero.left_sprites.img_0 = mlx_xpm_file_to_image(game->mlx,
			"sprites/ship/left/left0.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->hero.left_sprites.img_1 = mlx_xpm_file_to_image(game->mlx,
			"sprites/ship/left/left1.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->hero.left_sprites.img_2 = mlx_xpm_file_to_image(game->mlx,
			"sprites/ship/left/left2.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	game->hero.left_sprites.img_3 = mlx_xpm_file_to_image(game->mlx,
			"sprites/ship/left/left3.xpm",
			&(game->sprite_size.x), &(game->sprite_size.y));
	if (!game->hero.left_sprites.img_0
		|| !game->hero.left_sprites.img_1
		|| !game->hero.left_sprites.img_2
		|| !game->hero.left_sprites.img_3)
		return (0);
	return (1);
}

void	open_player_sprites(t_game *game)
{
	if (!up_sprites(game)
		|| !down_sprites(game)
		|| !right_sprites(game)
		|| !left_sprites(game))
	{
		game->error_msg
			= "Error.\nFail during opening player's sprites. Arrivederci!\n";
		ft_close(game);
	}
	game->hero.refs_current = &game->hero.up_sprites;
	game->hero.img_current = game->hero.up_sprites.img_0;
}
