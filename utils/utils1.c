/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akitty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:27:11 by akitty            #+#    #+#             */
/*   Updated: 2022/02/02 14:27:14 by akitty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_map *map_params)
{
	int	rows;

	rows = map_params->rows;
	if (map_params->map_str)
		free(map_params->map_str);
	if (map_params->map_arr)
	{
		while (--rows >= 0)
			free(map_params->map_arr[rows]);
		free(map_params->map_arr);
	}
}

static void	free_enemies(t_enemies **enemy)
{
	t_enemies	*ex;

	while (*enemy)
	{
		ex = *enemy;
		*enemy = ex->next;
		free(ex);
	}
	*enemy = NULL;
}

int	ft_close(t_game *game)
{
	if (game->enemy_exists == TRUE)
		free_enemies(&game->enemy_list);
	if (game)
	{
		if (game->map_params)
		{
			if (game->map_params)
				free_map(game->map_params);
			free(game->map_params);
		}
	}
	ft_destroy_window(game);
	printf("%s", game->error_msg);
	exit(0);
	return (0);
}

t_enemies	*add_enemy(t_enemies *ex, int id, int pos_x, int pos_y)
{
	t_enemies	*new;

	new = (t_enemies *)malloc(sizeof(*new));
	if (!new)
	{
		free_enemies(&ex);
		return (NULL);
	}
	new->id = id;
	new->position.x = pos_x;
	new->position.y = pos_y;
	new->vector = 1;
	new->anime_timer = 0;
	new->next = ex;
	return (new);
}

void	show_moves(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->moves);
	if (!moves)
		ft_close(game);
	mlx_string_put(game->mlx, game->window.reference, 10,
		game->window.size.y - 30, 0xccccff, "Moves: ");
	mlx_string_put(game->mlx, game->window.reference, 90,
		game->window.size.y - 30, 0xccccff, moves);
	free(moves);
}
