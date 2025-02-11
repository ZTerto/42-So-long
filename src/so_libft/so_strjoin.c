/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar-c <ajodar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:40:14 by ajodar-c          #+#    #+#             */
/*   Updated: 2025/01/07 13:49:10 by ajodar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_libft.h"

char	*so_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;
	size_t	len;

	len1 = so_strlen(s1);
	len2 = so_strlen(s2);
	len = len1 + len2;
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	so_strlcpy(str, s1, len1 + 1);
	so_strlcat(str, s2, len + 1);
	return (str);
}
