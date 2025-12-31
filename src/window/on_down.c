/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:44:05 by amartel           #+#    #+#             */
/*   Updated: 2025/12/31 19:59:14 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	on_down(t_m *mlx)
{
	char	**map;

	map = mlx->map;
	if (map[mlx->player->y + 1][mlx->player->x] != '1')
	{
		was_exit(mlx);
		mlx->player->y += 1;
		event(mlx);
		display_move(mlx);
		is_exit(mlx);
	}
}
