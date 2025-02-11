/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:41:03 by ajodar-c          #+#    #+#             */
/*   Updated: 2025/01/18 11:40:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PATH_PREFIX ".assets/map/"
# define MAX_PATH_LENGTH 256

// standar libs
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

// my libs
# include "../src/ft_printf/ft_printf.h"
# include "../src/get_next_line/get_next_line.h"
# include "../src/so_libft/so_libft.h"

// MLX42 y GLFW
# include "../libs/MLX42-master/include/MLX42/MLX42.h"
# include <GLFW/glfw3.h>

//textures list
typedef struct textures_player
{
	mlx_texture_t	*playerf1;
	mlx_texture_t	*playerfs;
	mlx_texture_t	*playerl1;
	mlx_texture_t	*playerls;
	mlx_texture_t	*playerr1;
	mlx_texture_t	*playerrs;
	mlx_texture_t	*playerb;
	mlx_texture_t	*playerbs;
	mlx_texture_t	*playerkey;
}	t_textures_player;

typedef struct textures_map
{
	mlx_texture_t	*wallt;
	mlx_texture_t	*walll;
	mlx_texture_t	*wallr;
	mlx_texture_t	*wallb;
	mlx_texture_t	*wall;
	mlx_texture_t	*wallc_tl;
	mlx_texture_t	*wallc_tr;
	mlx_texture_t	*wallc_bl;
	mlx_texture_t	*wallc_br;
	mlx_texture_t	*floor1;
	mlx_texture_t	*floor2;
	mlx_texture_t	*floor3;
	mlx_texture_t	*floor4;
	mlx_texture_t	*floor5;
	mlx_texture_t	*key;
	mlx_texture_t	*exit0;
	mlx_texture_t	*exit1;
	mlx_texture_t	*trap;
	char			**map;
}	t_textures_map;

//struct of the player
typedef struct s_player
{
	int					x;
	int					y;
	int					keys;
	int					steps;
	char				keyboard;
	t_textures_player	*textures;
	t_textures_map		*textures_map;
	mlx_image_t			*active_image;
	mlx_t				*mlx;
	char				**map;
	clock_t				last_animation_time;
}	t_player;

typedef struct s_position
{
	char	**map;
	int		x;
	int		y;
}	t_position;

typedef struct s_floodfill
{
	bool	collectibles_found;
	bool	exit_found;
	int		count;
}	t_floodfill_ec;

//load and check map
char				**loading_map(char *path_map, \
t_textures_map **textures_map);
char				*lookformap(char *argv);
char				**load_map(char *map_route);
int					check_map(char **map);
int					map_long(char **map);
int					map_len(char **map);
bool				validate_map_accessibility(t_player \
*player, char *path_map);

//load textures
t_textures_player	*load_textures_player(void);
t_textures_map		*load_textures_map(void);
int					check_textures_player(t_textures_player *textures_player);
int					check_textures_map(t_textures_map *textures_map);
void				unload_textures_player(t_textures_player *textures_player);
void				unload_textures_map(t_textures_map *textures_map);

//render map and player
bool				loading_player(char ***map, \
t_textures_player **textures_player, t_player **player);
void				render_all(mlx_t *mlx, char **map, \
t_textures_map *textures_map, t_player *player);
int					count_map_lines(char **map);
t_player			*ini_player(mlx_t *mlx, char **map, \
t_textures_player *textures_player, t_textures_map *textures_map);
void				free_map(char **map);
void				check_player_position(void *param);

//end game
void				end_game(t_player *player);

#endif