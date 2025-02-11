/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:29:21 by marvin            #+#    #+#             */
/*   Updated: 2024/12/24 17:29:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_map_lines(char **map)
{
	int			count;

	count = 0;
	while (map[count] != NULL)
		count++;
	return (count);
}

static mlx_image_t	*get_walls(mlx_t *mlx, t_textures_map *textures_map, \
t_position position)
{
	mlx_image_t	*img;

	img = NULL;
	if (position.y == 0 && position.x == 0)
		img = mlx_texture_to_image(mlx, textures_map->wallc_tl);
	else if (position.y == 0 && \
	position.map[position.y][position.x + 1] == '\0')
		img = mlx_texture_to_image(mlx, textures_map->wallc_tr);
	else if (position.y == count_map_lines(position.map) - 1 && position.x == 0)
		img = mlx_texture_to_image(mlx, textures_map->wallc_bl);
	else if (position.y == count_map_lines(position.map) - 1 && \
	position.map[position.y][position.x + 1] == '\0')
		img = mlx_texture_to_image(mlx, textures_map->wallc_br);
	else if (position.y == 0)
		img = mlx_texture_to_image(mlx, textures_map->wallt);
	else if (position.x == 0)
		img = mlx_texture_to_image(mlx, textures_map->walll);
	else if (position.map[position.y][position.x + 1] == '\0')
		img = mlx_texture_to_image(mlx, textures_map->wallr);
	else if (position.y == count_map_lines(position.map) - 1)
		img = mlx_texture_to_image(mlx, textures_map->wallb);
	else
		img = mlx_texture_to_image(mlx, textures_map->wall);
	return (img);
}

static mlx_image_t	*get_random_floor(mlx_t *mlx, \
t_textures_map *textures_map, t_position position)
{
	int				floor_index;
	mlx_image_t		*img;

	img = NULL;
	floor_index = ((position.y * 17) + (position.x * 21)) % 5;
	if (floor_index == 1)
		img = mlx_texture_to_image(mlx, textures_map->floor1);
	else if (floor_index == 2)
		img = mlx_texture_to_image(mlx, textures_map->floor2);
	else if (floor_index == 3)
		img = mlx_texture_to_image(mlx, textures_map->floor3);
	else if (floor_index == 4)
		img = mlx_texture_to_image(mlx, textures_map->floor4);
	else
		img = mlx_texture_to_image(mlx, textures_map->floor5);
	return (img);
}

static void	render_wke(mlx_t *mlx, t_textures_map *textures_map, \
t_position position, t_player *player)
{
	mlx_image_t	*img;
	int			render_x;
	int			render_y;

	(void)player;
	render_x = position.x * 64;
	render_y = position.y * 64;
	img = NULL;
	if (position.map[position.y][position.x] == '1')
		img = get_walls(mlx, textures_map, position);
	else if (position.map[position.y][position.x] == 'C')
		img = mlx_texture_to_image(mlx, textures_map->key);
	else if (position.map[position.y][position.x] == 'E')
		img = mlx_texture_to_image(mlx, textures_map->exit0);
	else if (position.map[position.y][position.x] == 'I')
		img = mlx_texture_to_image(mlx, textures_map->trap);
	else
		img = get_random_floor(mlx, textures_map, position);
	mlx_image_to_window(mlx, img, render_x, render_y);
}

void	render_all(mlx_t *mlx, char **map, \
t_textures_map *textures_map, t_player *player)
{
	int			y;
	int			x;
	t_position	position;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			position.map = map;
			position.x = x;
			position.y = y;
			render_wke(mlx, textures_map, position, player);
			x++;
		}
		y++;
	}
}
