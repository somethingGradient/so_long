/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akitty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:19:52 by akitty            #+#    #+#             */
/*   Updated: 2022/02/02 14:19:53 by akitty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	death(t_game *game)
{
	if (game->death_timer == 0)
		game->hero.img_current = game->boom.img_0;
	else if (game->death_timer == 10)
		game->hero.img_current = game->boom.img_1;
	else if (game->death_timer == 20)
		game->hero.img_current = game->boom.img_2;
	else if (game->death_timer == 30)
		game->hero.img_current = game->boom.img_3;
	else if (game->death_timer == 40)
		game->hero.img_current = game->boom.img_4;
	else if (game->death_timer == 50)
		game->hero.img_current = game->boom.img_5;
	else if (game->death_timer == 60)
		game->hero.img_current = game->boom.img_6;
	game->death_timer++;
}

static int	player_animation(t_game *game, int x, int y)
{
	show_moves(game);
	if (game->game_over == TRUE)
		death(game);
	else
	{
		if (game->anime_timer % 3 == 0)
			game->hero.img_current = game->hero.refs_current->img_0;
		else if (game->anime_timer % 5 == 0)
			game->hero.img_current = game->hero.refs_current->img_1;
		else if (game->anime_timer % 7 == 0)
			game->hero.img_current = game->hero.refs_current->img_2;
		else if (game->anime_timer % 9 == 0)
			game->hero.img_current = game->hero.refs_current->img_3;
	}
	mlx_put_image_to_window(game->mlx, game->window.reference,
		game->hero.img_current, x, y);
	if (game->death_timer == 70)
		ft_close(game);
	return (1);
}

static int	enemy_animation(t_game *game, int x, int y)
{
	if (game->anime_timer % 30 == 0)
		game->enemy_imgs.img_current = game->enemy_imgs.img_2;
	else if (game->anime_timer % 50 == 0)
		game->enemy_imgs.img_current = game->enemy_imgs.img_1;
	else if (game->anime_timer % 70 == 0)
		game->enemy_imgs.img_current = game->enemy_imgs.img_3;
	else if (game->anime_timer % 90 == 0)
		game->enemy_imgs.img_current = game->enemy_imgs.img_0;
	mlx_put_image_to_window(game->mlx, game->window.reference,
		game->enemy_imgs.img_current, x, y);
	return (1);
}

static int	enemy_moving(t_game *game, t_enemies *enemy, char ***map, int *y)
{
	if (enemy->anime_timer % 90 == 0)
	{
		if ((*map)[*y][(enemy->position.x) + 1] != '0' && enemy->vector == 1)
			enemy->vector = -1;
		else if ((*map)[*y][(enemy->position.x) - 1]
			!= '0' && enemy->vector == -1)
			enemy->vector = 1;
		if (enemy->vector == 1)
		{
			(*map)[*y][(enemy->position.x) + 1] = 'e';
			(*map)[*y][(enemy->position.x)++] = '0';
		}
		else
		{
			(*map)[*y][(enemy->position.x) - 1] = 'e';
			(*map)[*y][(enemy->position.x)--] = '0';
		}
	}
	if ((*map)[game->hero.position.y / 60][game->hero.position.x / 60]
		== (*map)[*y][enemy->position.x])
	{
		game->error_msg = "YOU DIED\n";
		game->game_over = TRUE;
	}
	return (1);
}

int	animations(t_game *game)
{
	t_enemies	*lst;
	char		**map;

	mlx_clear_window(game->mlx, game->window.reference);
	draw_static_items(game);
	player_animation(game, game->hero.position.x, game->hero.position.y);
	if (game->enemy_exists == TRUE)
	{
		lst = game->enemy_list;
		while (lst)
		{
			map = game->map_params->map_arr;
			enemy_animation(game, lst->position.x * game->sprite_size.x,
				lst->position.y * game->sprite_size.y);
			enemy_moving(game, lst, &map, &lst->position.y);
			lst->anime_timer++;
			lst = lst->next;
		}
	}
	game->anime_timer++;
	if (game->anime_timer == 2000000000)
		game->anime_timer = 0;
	return (1);
}
