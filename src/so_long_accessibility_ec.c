/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_floodfill_EC.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:31:39 by marvin            #+#    #+#             */
/*   Updated: 2025/01/12 09:31:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **map_copy, int x, int y, t_floodfill_ec *status)
{
	if (status->count >= 320)
		return ;
	status->count++;
	if (map_copy[y][x] == 'I' || map_copy[y][x] == '1' || map_copy[y][x] == 'V')
		return ;
	if (status->collectibles_found == true && status->exit_found == true)
		return ;
	if (map_copy[y][x] == 'C')
		status->collectibles_found = true;
	if (map_copy[y][x] == 'E')
		status->exit_found = true;
	map_copy[y][x] = 'V';
	flood_fill(map_copy, x + 1, y, status);
	flood_fill(map_copy, x - 1, y, status);
	flood_fill(map_copy, x, y + 1, status);
	flood_fill(map_copy, x, y - 1, status);
}

static bool	accesible_map(char **map_copy, int x, int y)
{
	t_floodfill_ec	status;

	status.collectibles_found = false;
	status.exit_found = false;
	status.count = 0;
	flood_fill(map_copy, x, y, &status);
	if (status.collectibles_found == true && status.exit_found == true)
		return (true);
	return (false);
}

bool	validate_map_accessibility(t_player *player, char *path_map)
{
	char	**map_copy;
	int		ini_x;
	int		ini_y;

	map_copy = load_map(path_map);
	if (map_copy == NULL)
	{
		ft_printf("Accesibility Error: No way to win or too big\n");
		free(path_map);
		return (false);
	}
	ini_x = player->x;
	ini_y = player->y;
	if (accesible_map(map_copy, ini_x, ini_y) == false)
	{
		ft_printf("Accesibility Error: No way to win or too big\n");
		free_map(map_copy);
		free(path_map);
		return (false);
	}
	free_map(map_copy);
	free(path_map);
	return (true);
}
