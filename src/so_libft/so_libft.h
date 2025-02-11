/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:18:24 by ajodar-c          #+#    #+#             */
/*   Updated: 2025/01/12 12:29:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LIBFT_H
# define SO_LIBFT_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

size_t	so_strlen(const char *s);
char	*so_strdup(const char *s);
char	*so_strjoin(char const *s1, char const *s2);
size_t	so_strlcpy(char *dst, const char *src, size_t size);
size_t	so_strlcat(char *dst, const char *src, size_t size);

#endif