/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:30:40 by marvin            #+#    #+#             */
/*   Updated: 2024/12/30 10:30:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_image_t	*choose_animation(t_player *player)
{
	mlx_image_t	*img;

	img = NULL;
	if (player->active_image != NULL)
		mlx_delete_image(player->mlx, player->active_image);
	if (player->keyboard == 'd' && (player->steps % 2) != 0)
		img = mlx_texture_to_image(player->mlx, player->textures->playerrs);
	else if (player->keyboard == 'd' && (player->steps % 2) == 0)
		img = mlx_texture_to_image(player->mlx, player->textures->playerr1);
	else if (player->keyboard == 'a' && (player->steps % 2) != 0)
		img = mlx_texture_to_image(player->mlx, player->textures->playerls);
	else if (player->keyboard == 'a' && (player->steps % 2) == 0)
		img = mlx_texture_to_image(player->mlx, player->textures->playerl1);
	else if (player->keyboard == 's' && (player->steps % 2) != 0)
		img = mlx_texture_to_image(player->mlx, player->textures->playerfs);
	else if (player->keyboard == 's' && (player->steps % 2) == 0)
		img = mlx_texture_to_image(player->mlx, player->textures->playerf1);
	else if (player->keyboard == 'w' && (player->steps % 2) != 0)
		img = mlx_texture_to_image(player->mlx, player->textures->playerbs);
	else if (player->keyboard == 'w' && (player->steps % 2) == 0)
		img = mlx_texture_to_image(player->mlx, player->textures->playerb);
	return (img);
}

static void	animation_move(t_player *player)
{
	mlx_image_t		*img;
	clock_t			current_time;

	current_time = clock();
	if ((current_time - player->last_animation_time) < (CLOCKS_PER_SEC / 50))
		return ;
	img = choose_animation(player);
	if (img != NULL)
		mlx_image_to_window(player->mlx, img, player->x * 64, player->y * 64);
}

static void	open_exit(t_player *player)
{
	int			x;
	int			y;
	mlx_image_t	*img;

	y = 0;
	while (player->map[y] != NULL)
	{
		x = 0;
		while (player->map[y][x] != '\0')
		{
			if (player->map[y][x] == 'E')
			{
				img = mlx_texture_to_image(player->mlx, \
				player->textures_map->exit1);
				mlx_image_to_window(player->mlx, img, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
}

static void	render_pick_key(t_player *player)
{
	mlx_image_t	*img;

	img = mlx_texture_to_image(player->mlx, player->textures_map->floor2);
	mlx_image_to_window(player->mlx, img, player->x * 64, player->y * 64);
	img = mlx_texture_to_image(player->mlx, player->textures->playerkey);
	if (img != NULL)
	{
		player->active_image = img;
		mlx_image_to_window(player->mlx, img, player->x * 64, player->y * 64);
	}
	if (player->keys == 0)
		open_exit(player);
	player->last_animation_time = clock();
}

void	check_player_position(void *param)
{
	t_player		*player;
	char			position;

	player = (t_player *)param;
	position = player->map[player->y][player->x];
	if (position == 'C')
	{
		player->keys--;
		render_pick_key(player);
		player->map[player->y][player->x] = '0';
	}
	else if (position == '0')
	{
		animation_move(player);
	}
	else if (position == 'I')
	{
		ft_printf("You fall in a hole\nfinal step: %i\n", player->steps);
		end_game(player);
	}
	else if (position == 'E' && player->keys == 0)
	{
		ft_printf("YOU WIN!!!  FUCK YEAH!!!\nfinal step: %i\n", player->steps);
		end_game(player);
	}
}
