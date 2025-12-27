/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 00:19:22 by amartel           #+#    #+#             */
/*   Updated: 2025/12/26 20:52:56 by amartel          ###   ########.fr       */
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


typedef struct
{
	mlx_context mlx;
	mlx_window win;
} mlx_t;

typedef struct s_point
{
	size_t	x;
	size_t	y;
} t_point;

typedef struct s_map
{
	t_point	P;
	size_t	C;
} t_map;

void	key_hook(int key, void *param);
void	window_hook(int event, void *param);
int		checker(char **av);
void	error(char *msg);
void	free_before_err(char **map, char *msg);
void	free_gnl_err(char **map, char *msg);
void	map_content_checker(char **map);

# endif