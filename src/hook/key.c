/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 00:17:56 by amartel           #+#    #+#             */
/*   Updated: 2025/12/31 03:14:35 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Code key usefull

'w' -> 26;
's' -> 22;
'd' -> 7;
'a' -> 4;
*/
void	key_hook(int key, void *param)
{
	mlx_t *m;
	char **map;

	m = (mlx_t *)param;
	map = m->map;
	if (key == 41)
		mlx_loop_end(m->mlx);
	if (key == 26)
	{
		map[m->player->y][m->player->x] = '0';
		//mlx_put_image_to_window(m->mlx, m->win, m->bla,  m->player->x * 16, m->player->y * 16);
		m->player->y -= 1;
		map[m->player->y][m->player->x] = 'P';
		// mlx_put_image_to_window(m->mlx, m->win, m->blu,  m->player->x * 16, m->player->y * 16);
	}
	if (key == 22)
	{
		map[m->player->y][m->player->x] = '0';
		// mlx_put_image_to_window(m->mlx, m->win, m->bla,  m->player->x * 16, m->player->y * 16);
		m->player->y += 1;
		map[m->player->y][m->player->x] = 'P';
		// mlx_put_image_to_window(m->mlx, m->win, m->blu,  m->player->x * 16, m->player->y * 16);
	}
	if (key == 7)
	{
		map[m->player->y][m->player->x] = '0';
		// mlx_put_image_to_window(m->mlx, m->win, m->bla,  m->player->x * 16, m->player->y * 16);
		m->player->x += 1;
		map[m->player->y][m->player->x] = 'P';
		// mlx_put_image_to_window(m->mlx, m->win, m->bla,  m->player->x * 16, m->player->y * 16);
	}
	if (key == 4)
	{
		map[m->player->y][m->player->x] = '0';
		//mlx_put_image_to_window(m->mlx, m->win, m->bla,  m->player->x * 16, m->player->y * 16);
		m->player->x -= 1;
		map[m->player->y][m->player->x] = 'P';
		//mlx_put_image_to_window(m->mlx, m->win, m->bla,  m->player->x * 16, m->player->y * 16);
	}
}
