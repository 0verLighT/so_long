/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 01:36:53 by amartel           #+#    #+#             */
/*   Updated: 2025/12/31 19:59:14 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	img(t_m *m, size_t i, size_t j, char **map)
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
}

void	update(void *param)
{
	t_m	*m;
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	m = (t_m *)param;
	map = m->map;
	mlx_clear_window(m->mlx, m->win, (mlx_color){.rgba = 0x000000FF});
	while (map[i])
	{
		while (map[i][j])
		{
			img(m, i, j, map);
			++j;
		}
		j = 0;
		++i;
	}
}

void	display_move(t_m *mlx)
{
	++mlx->move;
	ft_putstr_fd("Move : ", 1);
	ft_putnbr_fd(mlx->move, 1);
	write(1, "\n", 1);
}
