/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:19:39 by amartel           #+#    #+#             */
/*   Updated: 2025/12/31 18:57:57 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



static void	event_c(mlx_t *mlx)
{
	char **map;
	
	map = mlx->map;
	if (map[mlx->player->y][mlx->player->x] == 'C')
		--mlx->C;
}

static void	event_e(mlx_t *mlx)
{
	char **map;

	map = mlx->map;
	if (mlx->C == 0 && map[mlx->player->y][mlx->player->x] == 'E')
		mlx_loop_end(mlx->mlx);
}

void	is_exit(mlx_t *mlx)
{
	char **map;

	map = mlx->map;
	if (map[mlx->player->y][mlx->player->x] == 'E' && mlx->C != 0)
		map[mlx->player->y][mlx->player->x] = 'E';
	else
		map[mlx->player->y][mlx->player->x] = 'P';
}

void	was_exit(mlx_t *mlx)
{
	char **map;

	map = mlx->map;
	if (map[mlx->player->y][mlx->player->x] == 'E' && mlx->C != 0)
		map[mlx->player->y][mlx->player->x] = 'E';
	else
		map[mlx->player->y][mlx->player->x] = '0';
}
void	event(mlx_t *mlx)
{
	event_c(mlx);
	event_e(mlx);
}
