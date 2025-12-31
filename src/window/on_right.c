/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_right.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:44:33 by amartel           #+#    #+#             */
/*   Updated: 2025/12/31 19:12:24 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void on_right(mlx_t *mlx)
{
	char **map;

	map = mlx->map;
	if (map[mlx->player->y][mlx->player->x + 1] != '1')
	{
		was_exit(mlx);
		mlx->player->x += 1;
		event(mlx);
		display_move(mlx);
		is_exit(mlx);
	}
}
