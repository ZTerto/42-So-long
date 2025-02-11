/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_strdupp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar-c <ajodar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:39:41 by ajodar-c          #+#    #+#             */
/*   Updated: 2025/01/07 13:49:06 by ajodar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_libft.h"

char	*so_strdup(const char *s)
{
	size_t	len;
	char	*str;

	len = so_strlen(s) + 1;
	str = malloc(len);
	if (str == NULL)
		return (NULL);
	so_strlcpy(str, s, len);
	return (str);
}
