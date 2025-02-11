/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar-c <ajodar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:40:30 by ajodar-c          #+#    #+#             */
/*   Updated: 2025/01/20 10:55:16 by ajodar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_t	*ini_map_and_window(char *path_map, \
char ***map, t_textures_map **textures_map, t_player *player)
{
	mlx_t	*mlx;

	*map = loading_map(path_map, textures_map);
	free (path_map);
	if (*map == NULL)
		return (NULL);
	mlx = mlx_init(map_len(*map), map_long(*map), "The legend of Terto", true);
	if (mlx == NULL)
		return (NULL);
	render_all(mlx, *map, *textures_map, player);
	return (mlx);
}

static t_player	*initialize_player(mlx_t *mlx, char ***map, \
t_textures_player **textures_player, t_textures_map *textures_map)
{
	t_player	*player;

	if (loading_player(map, textures_player, &player) == false)
	{
		mlx_terminate(mlx);
		return (NULL);
	}
	player = ini_player(mlx, *map, *textures_player, textures_map);
	return (player);
}

static void	process_key_input(mlx_key_data_t keydata, t_player *player, \
int *new_x, int *new_y)
{
	static clock_t	last_move_time = 0;
	clock_t			current_time;

	current_time = clock();
	if ((current_time - last_move_time) < (CLOCKS_PER_SEC / 49))
		return ;
	*new_x = player->x;
	*new_y = player->y;
	if (keydata.key == MLX_KEY_W)
		(*new_y)--;
	else if (keydata.key == MLX_KEY_S)
		(*new_y)++;
	else if (keydata.key == MLX_KEY_A)
		(*new_x)--;
	else if (keydata.key == MLX_KEY_D)
		(*new_x)++;
	else if (keydata.key == MLX_KEY_ESCAPE)
	{
		ft_printf("You escape the game\nfinal step: %i\n", player->steps);
		end_game(player);
	}
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S || \
		keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
		ft_printf("steps: %i\n", ++player->steps);
	last_move_time = clock();
}

static void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_player	*player;
	int			new_y;
	int			new_x;

	player = (t_player *)param;
	new_y = player->y;
	new_x = player->x;
	process_key_input(keydata, player, &new_x, &new_y);
	if (player->x < new_x)
		player->keyboard = 'd';
	else if (player->x > new_x)
		player->keyboard = 'a';
	else if (player->y < new_y)
		player->keyboard = 's';
	else if (player->y > new_y)
		player->keyboard = 'w';
	if (player->map[new_y][new_x] != '1')
	{
		player->y = new_y;
		player->x = new_x;
		player->active_image->instances[0].x = new_x * 64;
		player->active_image->instances[0].y = new_y * 64;
	}
}

//Path of maps:./assets/maps/xxx.ber
//Path of textures:./assets/textures/xxx.png
int	main(int argc, char *argv[])
{
	char				**map;
	mlx_t				*mlx;
	t_textures_map		*textures_map;
	t_textures_player	*textures_player;
	t_player			*player;

	player = NULL;
	if (argc < 2)
		return (1);
	mlx = ini_map_and_window(lookformap(argv[1]), &map, &textures_map, player);
	if (mlx == NULL)
		return (1);
	player = initialize_player(mlx, &map, &textures_player, textures_map);
	if (player == NULL)
		return (1);
	if (validate_map_accessibility(player, lookformap(argv[1])) == false)
		end_game(player);
	mlx_key_hook(mlx, key_hook, player);
	mlx_loop_hook(mlx, check_player_position, player);
	mlx_loop(mlx);
	return (0);
}
