/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 01:36:53 by amartel           #+#    #+#             */
/*   Updated: 2025/12/31 03:11:58 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update(void *param)
{
	mlx_t *m;
	char **map;
	int	i;
	int	j;

	i = 0;
	j = 0;
	m = (mlx_t *)param;
	map = m->map;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '0')
				mlx_put_image_to_window(m->mlx, m->win, m->bla, j * 16, i * 16);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(m->mlx, m->win, m->gen, j * 16, i * 16);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(m->mlx, m->win, m->red, j * 16, i * 16);
			else if (map[i][j] == '1')
				mlx_put_image_to_window(m->mlx, m->win, m->gey, j * 16, i * 16);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(m->mlx, m->win, m->blu, j * 16, i * 16);
			++j;
		}
		j = 0;
		++i;
	}
}
