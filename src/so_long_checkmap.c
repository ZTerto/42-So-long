/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_checkmap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:59:15 by marvin            #+#    #+#             */
/*   Updated: 2024/12/19 10:59:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_tokens(char **map, int i, int j)
{
	static int	p = 0;
	static int	c = 0;
	static int	e = 0;

	if (map[i][j] == 'P')
		p++;
	if (map[i][j] == 'E')
		e++;
	if (map[i][j] == 'C')
		c++;
	if (p > 0 && c > 0 && e > 0)
		return (0);
	return (-2);
}

static int	check_map_len(char **map)
{
	int			i;
	size_t		len;

	i = 1;
	if (map == NULL || map[0] == NULL)
		return (-1);
	len = so_strlen(map[0]);
	while (map[i] != NULL)
	{
		if (so_strlen(map[i]) != len)
			return (-1);
		i++;
	}
	return (0);
}

static int	check_map_updown(char **map, int lines)
{
	int		j;

	j = 0;
	while (map[0][j] != '\0')
	{
		if (map[0][j] == '1')
		{
			j++;
		}
		else
			return (-1);
	}
	j = 0;
	ft_printf("\n");
	while (map[lines - 1][j] != '\0')
	{
		if (map[lines - 1][j] == '1')
		{
			j++;
		}
		else
			return (-1);
	}
	return (0);
}

static int	check_map_mid(char **map, int lines)
{
	int		i;
	int		j;
	int		token;

	i = 1;
	token = -2;
	while (i < lines - 1)
	{
		if (map[i][0] != '1' || map[i][so_strlen(map[i]) - 1] != '1')
			return (-1);
		j = 0;
		while (map[i][j] != '\0')
		{
			token = check_tokens(map, i, j);
			if (map[i][j] == '0' || map[i][j] == '1' || \
			map[i][j] == 'P' || map[i][j] == 'E' || \
			map[i][j] == 'C' || map[i][j] == 'I')
				j++;
			else
				return (-1);
		}
		i++;
	}
	return (token);
}

int	check_map(char **map)
{
	int		mid_check;
	int		lines;

	if (check_map_len(map) != 0)
	{
		ft_printf("\nError check_map: Not a valid map (check_map_len)\n");
		return (-1);
	}
	lines = count_map_lines(map);
	if (check_map_updown(map, lines) != 0)
	{
		ft_printf("\nError check_map: Not a valid map (check_map_updown)\n");
		return (-1);
	}
	mid_check = check_map_mid(map, lines);
	if (mid_check != 0)
	{
		if (mid_check == -2)
			ft_printf("\nError check_map: Not a valid map (check_tokens)\n");
		if (mid_check == -1)
			ft_printf("\nError check_map: Not a valid map (check_map_mid)\n");
		return (-1);
	}
	return (0);
}
