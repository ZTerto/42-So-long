/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:38:01 by ajodar-c          #+#    #+#             */
/*   Updated: 2025/01/12 11:51:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_textures_player	*load_textures_player(void)
{
	t_textures_player	*textures_p;

	textures_p = malloc(sizeof(t_textures_player));
	if (textures_p == NULL)
		return (NULL);
	textures_p->playerf1 = mlx_load_png("./assets/textures/player_front_1.png");
	textures_p->playerfs = mlx_load_png("./assets/textures/player_front_s.png");
	textures_p->playerl1 = mlx_load_png("./assets/textures/player_left_1.png");
	textures_p->playerls = mlx_load_png("./assets/textures/player_left_s.png");
	textures_p->playerr1 = mlx_load_png("./assets/textures/player_rigth_1.png");
	textures_p->playerrs = mlx_load_png("./assets/textures/player_rigth_s.png");
	textures_p->playerbs = mlx_load_png("./assets/textures/player_back_s.png");
	textures_p->playerb = mlx_load_png("./assets/textures/player_back.png");
	textures_p->playerkey = mlx_load_png("./assets/textures/player_key.png");
	return (textures_p);
}

t_textures_map	*load_textures_map(void)
{
	t_textures_map	*textures_m;

	textures_m = malloc(sizeof(t_textures_map));
	if (textures_m == NULL)
		return (NULL);
	textures_m->wall = mlx_load_png("./assets/textures/wall.png");
	textures_m->wallt = mlx_load_png("./assets/textures/wallT.png");
	textures_m->walll = mlx_load_png("./assets/textures/wallL.png");
	textures_m->wallr = mlx_load_png("./assets/textures/wallR.png");
	textures_m->wallb = mlx_load_png("./assets/textures/wallB.png");
	textures_m->wallc_tl = mlx_load_png("./assets/textures/end0.png");
	textures_m->wallc_tr = mlx_load_png("./assets/textures/end1.png");
	textures_m->wallc_bl = mlx_load_png("./assets/textures/end2.png");
	textures_m->wallc_br = mlx_load_png("./assets/textures/end3.png");
	textures_m->floor1 = mlx_load_png("./assets/textures/floor1.png");
	textures_m->floor2 = mlx_load_png("./assets/textures/floor2.png");
	textures_m->floor3 = mlx_load_png("./assets/textures/floor3.png");
	textures_m->floor4 = mlx_load_png("./assets/textures/floor4.png");
	textures_m->floor5 = mlx_load_png("./assets/textures/floor5.png");
	textures_m->key = mlx_load_png("./assets/textures/key.png");
	textures_m->exit0 = mlx_load_png("./assets/textures/exit0.png");
	textures_m->exit1 = mlx_load_png("./assets/textures/exit1.png");
	textures_m->trap = mlx_load_png("./assets/textures/trap.png");
	return (textures_m);
}

int	check_textures_player(t_textures_player *textures)
{
	if (textures->playerf1 == NULL || textures->playerfs == NULL)
		return (free(textures), -1);
	if (textures->playerl1 == NULL || textures->playerls == NULL)
		return (free(textures), -1);
	if (textures->playerr1 == NULL || textures->playerrs == NULL)
		return (free(textures), -1);
	if (textures->playerb == NULL || textures->playerbs == NULL || \
	textures->playerkey == NULL)
		return (free(textures), -1);
	return (0);
}

int	check_textures_map(t_textures_map *textures)
{
	if (textures->exit0 == NULL || textures->exit1 == NULL)
		return (free(textures), -1);
	if (textures->wallt == NULL || textures->walll == NULL || \
	textures->wallr == NULL || textures->wallb == NULL || \
	textures->key == NULL)
		return (free(textures), -1);
	if (textures->floor1 == NULL || textures->floor2 == NULL || \
	textures->floor3 == NULL || textures->floor4 == NULL || \
	textures->floor5 == NULL)
		return (free(textures), -1);
	return (0);
}
