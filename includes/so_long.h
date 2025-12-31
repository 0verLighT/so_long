/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 00:19:22 by amartel           #+#    #+#             */
/*   Updated: 2025/12/31 02:18:20 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MacroLibX/includes/mlx.h"
# include <unistd.h>
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <errno.h>
# include <string.h>
#include <stdio.h>

typedef struct s_point
{
	size_t	x;
	size_t	y;
} t_point;

typedef struct s_mlx
{
	mlx_context mlx;
	mlx_window win;
	mlx_window_create_info	info;
	mlx_image blu;
	mlx_image bla;
	mlx_image gen;
	mlx_image red;
	mlx_image gey;
	char **map;
	t_point *player;
} mlx_t;

typedef struct s_map
{
	t_point	P;
	size_t	C;
} t_map;

void	key_hook(int key, void *param);
void	window_hook(int event, void *param);
char	**checker(char **av, char **map);
void	error(char *msg);
void	free_before_err(char **map, char *msg);
void	free_gnl_err(char **map, char *msg);
void	map_content_checker(char **map);
int		flood_fill(char **map, t_map data, size_t rows, size_t cols);
void	window_init(char **map);
void	update(void *param);

# endif