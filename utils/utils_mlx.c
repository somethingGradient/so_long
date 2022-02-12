/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akitty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:27:18 by akitty            #+#    #+#             */
/*   Updated: 2022/02/02 14:27:19 by akitty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_destroy_window(t_game *game)
{
	if (game->window.reference)
	{
		mlx_clear_window(game->mlx, game->window.reference);
		mlx_destroy_window(game->mlx, game->window.reference);
	}
}

int	ft_new_window(t_game *game)
{
	int	width;
	int	height;

	width = game->map_params->cols * game->sprite_size.x;
	height = game->map_params->rows * game->sprite_size.y + 30;
	game->window.reference = mlx_new_window(game->mlx,
			width, height, "so_long");
	game->window.size.x = width;
	game->window.size.y = height;
	mlx_hook(game->window.reference, 17, 1L << 0, ft_close, game);
	return (1);
}

t_image	ft_new_image(void *mlx, int width, int height)
{
	t_image	img;

	img.reference = mlx_new_image(mlx, width, height);
	img.size.x = width;
	img.size.y = height;
	img.pixels = mlx_get_data_addr(img.reference,
			&img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels = mlx_get_data_addr(img.reference,
			&img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}
