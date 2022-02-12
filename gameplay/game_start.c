/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akitty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:08:23 by akitty            #+#    #+#             */
/*   Updated: 2022/02/02 14:08:29 by akitty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	game_start(char *filename)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->sprite_size.x = 60;
	game->sprite_size.y = 60;
	map_options(game, filename);
	game->mlx = mlx_init();
	open_sprites(game);
	ft_new_window(game);
	mlx_key_hook(game->window.reference, keys_hook, game);
	mlx_loop_hook(game->mlx, animations, game);
	mlx_loop(game->mlx);
	return (1);
}

static int	check_argv(int argc, char **argv)
{
	int	len;

	if (argc == 2)
	{
		len = ft_strlen(argv[1]);
		if (argv[1][len - 1] == 'r' || argv[1][len - 2] == 'e'
			|| argv[1][len - 3] == 'b' || argv[1][len - 4] == '.')
			return (1);
	}
	printf("Error.\nWrite correct map.\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	if (check_argv(argc, argv))
		game_start(argv[1]);
	return (0);
}
