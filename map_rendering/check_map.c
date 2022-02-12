/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akitty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:25:52 by akitty            #+#    #+#             */
/*   Updated: 2022/01/17 21:26:15 by akitty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*read_map(int fd)
{
	char	c;
	char	str[3000];
	char	*result;
	int		bytes;
	int		i;

	if (read(fd, 0, 0) == -1 || fd < 0)
		return (NULL);
	bytes = 1;
	i = 0;
	while (bytes)
	{
		bytes = read(fd, &c, 1);
		str[i++] = c;
	}
	result = (char *)malloc(i);
	if (!result)
		return (NULL);
	bytes = -1;
	while (++bytes < i)
		result[bytes] = str[bytes];
	result[bytes - 1] = '\0';
	return (result);
}

static int	check_fullness_map(char *str, t_map *map_params)
{
	int	i;
	int	check_cols;

	i = 0;
	check_cols = 0;
	map_params->rows = 1;
	map_params->cols = 0;
	while (str[check_cols] != '\n')
		check_cols++;
	while (str[i])
	{
		if (str[i] != '\n')
			map_params->cols++;
		else if (str[i] == '\n')
		{
			if (check_cols != map_params->cols)
				return (0);
			map_params->cols = 0;
			map_params->rows++;
		}
		i++;
	}
	if (check_cols != map_params->cols)
		return (0);
	return (1);
}

static int	check_chars_map(char *str)
{
	int	player_count;
	int	exit_count;

	player_count = 0;
	exit_count = 0;
	while (*str)
	{
		if (!(*str == '1' || *str == '0' || *str == 'P'
				|| *str == 'C' || *str == 'E' || *str == '\n'
				|| *str == 'e' ))
			return (0);
		if (*str == 'P')
			player_count++;
		if (*str == 'E')
			exit_count++;
		str++;
	}
	if (player_count != 1 || exit_count == 0)
		return (0);
	return (1);
}

static int	check_walls(char *str, t_map *map_params)
{
	int	cols;

	cols = map_params->cols;
	while (--cols >= 0)
	{
		if (str[cols] != '1')
			return (0);
	}
	while (*str)
	{
		if (*str == '\n')
		{
			if (*(str + 1) != '1' || *(str - 1) != '1')
				return (0);
		}
		str++;
	}
	str -= (map_params->cols - 1);
	while (*str)
	{
		if (*str++ != '1')
			return (0);
	}
	return (1);
}

t_map	*check_map(char *filename)
{
	t_map	*map_params;
	int		fd;

	fd = open(filename, O_RDONLY);
	map_params = (t_map *)malloc(sizeof(*map_params));
	if (!map_params)
		exit(0);
	map_params->map_str = read_map(fd);
	if (!map_params->map_str
		|| !check_fullness_map(map_params->map_str, map_params)
		|| !check_chars_map(map_params->map_str)
		|| !check_walls(map_params->map_str, map_params))
	{
		printf("%s", "Error.\nMap is wrong. Adiós!\n");
		perror("System error");
		free(map_params->map_str);
		free(map_params);
		close(fd);
		exit(0);
	}
	close(fd);
	return (map_params);
}
