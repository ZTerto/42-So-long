/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_loadmap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar-c <ajodar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:50:19 by ajodar-c          #+#    #+#             */
/*   Updated: 2025/01/13 12:51:18 by ajodar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_len(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (map[i] != NULL)
		len = so_strlen(map[i]);
	return (len * 64);
}

int	map_long(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i * 64);
}

static int	count_lines(char *map_route)
{
	int			fd;
	int			count;
	char		*read;

	count = 0;
	fd = open(map_route, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("\nError load_map: Can't read map\n");
		close(fd);
		return (-1);
	}
	read = get_next_line(fd);
	while (read != NULL)
	{
		count++;
		free(read);
		read = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static char	**save_map_array(char *map_route, char **map)
{
	int			fd;
	size_t		len;
	int			i;
	char		*read;

	i = 0;
	fd = open(map_route, O_RDONLY);
	read = get_next_line(fd);
	while (read != NULL)
	{
		len = so_strlen(read);
		if (read[len - 1] == '\n')
			read[len - 1] = '\0';
		map[i] = read;
		i++;
		read = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

char	**load_map(char *map_route)
{
	char	**map;
	int		lines;

	lines = count_lines(map_route);
	if (lines == -1)
		return (NULL);
	map = malloc (sizeof(char *) * (lines + 1));
	if (map == NULL)
	{
		ft_printf("\nError load_map: Malloc failed\n");
		return (NULL);
	}
	map = save_map_array(map_route, map);
	if (check_map(map) != 0)
	{
		free(map);
		return (NULL);
	}
	return (map);
}
