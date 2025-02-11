/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_lookmap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:48:08 by ajodar-c          #+#    #+#             */
/*   Updated: 2025/01/18 11:22:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*lookformap(char *argv)
{
	char	*prefix;
	char	*path;

	prefix = "./assets/maps/";
	path = so_strjoin(prefix, argv);
	return (path);
}
