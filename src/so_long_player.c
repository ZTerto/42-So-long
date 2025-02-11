/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:26:55 by marvin            #+#    #+#             */
/*   Updated: 2024/12/26 14:26:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_keys(char **map)
{
	int	y;
	int	x;
	int	keys;

	y = 0;
	keys = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'C')
				keys++;
			x++;
		}
		y++;
	}
	return (keys);
}

static void	find_player_position(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

t_player	*ini_player(mlx_t *mlx, char **map, \
t_textures_player *textures_player, t_textures_map *textures_map)
{
	int				x;
	int				y;
	mlx_image_t		*img;
	t_player		*player;

	player = malloc(sizeof(t_player));
	if (player == NULL)
		return (NULL);
	player->mlx = mlx;
	player->map = map;
	player->textures = textures_player;
	player->textures_map = textures_map;
	player->keys = count_keys(map);
	find_player_position(map, &x, &y);
	player->x = x;
	player->y = y;
	img = mlx_texture_to_image(mlx, textures_player->playerf1);
	player->active_image = img;
	mlx_image_to_window(mlx, img, x * 64, y * 64);
	return (player);
}
