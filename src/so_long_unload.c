/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_texturesunload.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:13:52 by marvin            #+#    #+#             */
/*   Updated: 2024/12/25 17:13:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	unload_textures_player(t_textures_player *textures_player)
{
	if (textures_player == NULL)
		return ;
	if (textures_player->playerf1)
		mlx_delete_texture(textures_player->playerf1);
	if (textures_player->playerfs)
		mlx_delete_texture(textures_player->playerfs);
	if (textures_player->playerl1)
		mlx_delete_texture(textures_player->playerl1);
	if (textures_player->playerls)
		mlx_delete_texture(textures_player->playerls);
	if (textures_player->playerr1)
		mlx_delete_texture(textures_player->playerr1);
	if (textures_player->playerrs)
		mlx_delete_texture(textures_player->playerrs);
	if (textures_player->playerb)
		mlx_delete_texture(textures_player->playerb);
	if (textures_player->playerbs)
		mlx_delete_texture(textures_player->playerbs);
	if (textures_player->playerkey)
		mlx_delete_texture(textures_player->playerkey);
	free(textures_player);
}

void	unload_textures_map(t_textures_map *textures_map)
{
	if (textures_map == NULL)
		return ;
	mlx_delete_texture(textures_map->wallt);
	mlx_delete_texture(textures_map->walll);
	mlx_delete_texture(textures_map->wallr);
	mlx_delete_texture(textures_map->wallb);
	mlx_delete_texture(textures_map->wallc_tl);
	mlx_delete_texture(textures_map->wallc_tr);
	mlx_delete_texture(textures_map->wallc_bl);
	mlx_delete_texture(textures_map->wallc_br);
	mlx_delete_texture(textures_map->key);
	mlx_delete_texture(textures_map->exit0);
	mlx_delete_texture(textures_map->exit1);
	free(textures_map);
}

void	free_map(char **map)
{
	int	i;

	if (map == NULL)
		return ;
	i = 0;
	if (map != NULL)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
	}
	free(map);
}

void	end_game(t_player *player)
{
	mlx_terminate(player->mlx);
	free_map(player->map);
	free(player);
	exit (0);
}
