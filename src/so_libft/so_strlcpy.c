/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar-c <ajodar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:40:49 by ajodar-c          #+#    #+#             */
/*   Updated: 2025/01/07 13:49:16 by ajodar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_libft.h"

size_t	so_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = so_strlen(src);
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}
