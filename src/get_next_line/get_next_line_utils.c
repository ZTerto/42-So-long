/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar-c <ajodar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:22:20 by ajodar-c          #+#    #+#             */
/*   Updated: 2024/12/17 15:31:33 by ajodar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t num, size_t size)
{
	size_t			i;
	size_t			total;
	unsigned char	*ptr;

	i = 0;
	total = num * size;
	ptr = malloc(total);
	while (i < total)
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*sptr;

	i = 0;
	sptr = (char *)str;
	if (!str)
		return (NULL);
	while (sptr[i] != '\0')
	{
		if ((char)sptr[i] == (char)c)
			return (&sptr[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&sptr[i]);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	e;
	char	*set;

	i = start;
	e = 0;
	if (s == NULL || s[0] == '\0' || len == 0 || start > ft_strlen(s))
	{
		set = ft_calloc(1, sizeof(char));
		return (set);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	set = malloc(sizeof(char ) * (len + 1));
	if (set == NULL)
		return (NULL);
	while (e < len && s[i] != '\0')
	{
		set[e] = s[i];
		i++;
		e++;
	}
	set [e] = '\0';
	return (set);
}

char	*ft_join(char *buffer, char *nread)
{
	char	*nbuffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (buffer == NULL)
		return (ft_substr(nread, 0, ft_strlen(nread)));
	nbuffer = ft_calloc(ft_strlen(buffer) + ft_strlen(nread) + 1, sizeof(char));
	if (nbuffer == NULL)
		return (NULL);
	while (buffer[i] != '\0')
	{
		nbuffer[i] = buffer[i];
		i++;
	}
	while (nread[j] != '\0')
	{
		nbuffer[i + j] = nread[j];
		j++;
	}
	nbuffer[i + j] = '\0';
	free(buffer);
	return (nbuffer);
}
