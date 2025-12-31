/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:19:39 by amartel           #+#    #+#             */
/*   Updated: 2025/12/31 20:08:05 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	event_c(t_m *mlx)
{
	char	**map;

	map = mlx->map;
	if (map[mlx->player->y][mlx->player->x] == 'C')
		--mlx->c;
}

static void	event_e(t_m *mlx)
{
	char	**map;

	map = mlx->map;
	if (mlx->c == 0 && map[mlx->player->y][mlx->player->x] == 'E')
		mlx_loop_end(mlx->mlx);
}

void	is_exit(t_m *mlx)
{
	char	**map;

	map = mlx->map;
	if (map[mlx->player->y][mlx->player->x] == 'E' && mlx->c != 0)
		map[mlx->player->y][mlx->player->x] = 'E';
	else
		map[mlx->player->y][mlx->player->x] = 'P';
}

void	was_exit(t_m *mlx)
{
	char	**map;

	map = mlx->map;
	if (map[mlx->player->y][mlx->player->x] == 'E' && mlx->c != 0)
		map[mlx->player->y][mlx->player->x] = 'E';
	else
		map[mlx->player->y][mlx->player->x] = '0';
}

void	event(t_m *mlx)
{
	event_c(mlx);
	event_e(mlx);
}
