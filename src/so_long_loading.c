/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_loading.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:03:57 by marvin            #+#    #+#             */
/*   Updated: 2025/01/12 10:03:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**loading_map(char *path_map, t_textures_map **textures_map)
{
	char	**map;

	map = NULL;
	*textures_map = load_textures_map();
	if (*textures_map == NULL || check_textures_map(*textures_map) == -1)
	{
		unload_textures_map(*textures_map);
		free_map(map);
		return (NULL);
	}
	map = load_map(path_map);
	if (map == NULL || check_map(map) == -1)
	{
		unload_textures_map(*textures_map);
		free_map(map);
		return (NULL);
	}
	return (map);
}

bool	loading_player(char ***map, \
t_textures_player **textures_player, t_player **player)
{
	*textures_player = load_textures_player();
	if (*textures_player == NULL || \
	check_textures_player(*textures_player) == -1)
	{
		ft_printf("Error loading_player\n");
		free_map(*map);
		return (false);
	}
	if (*player == NULL)
	{
		ft_printf("Error loading_player\n");
		unload_textures_player(*textures_player);
		free_map(*map);
		return (false);
	}
	return (true);
}
