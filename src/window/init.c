/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 23:55:45 by amartel           #+#    #+#             */
/*   Updated: 2025/12/31 23:31:39 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_textures(t_m *mlx)
{
	int			i;
	static char	*texture[] = {
		"asset/textures/blue.png",
		"asset/textures/black.png",
		"asset/textures/grey.png",
		"asset/textures/green.png",
		"asset/textures/red.png",
		NULL
	};

	mlx->bla = mlx_new_image_from_file(mlx->mlx, (char *)texture[1], &i, &i);
	mlx->blu = mlx_new_image_from_file(mlx->mlx, (char *)texture[0], &i, &i);
	mlx->red = mlx_new_image_from_file(mlx->mlx, (char *)texture[4], &i, &i);
	mlx->gen = mlx_new_image_from_file(mlx->mlx, (char *)texture[3], &i, &i);
	mlx->gey = mlx_new_image_from_file(mlx->mlx, (char *)texture[2], &i, &i);
}

static void	destroy_mlx(t_m *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->bla);
	mlx_destroy_image(mlx->mlx, mlx->red);
	mlx_destroy_image(mlx->mlx, mlx->blu);
	mlx_destroy_image(mlx->mlx, mlx->gen);
	mlx_destroy_image(mlx->mlx, mlx->gey);
	if (mlx->player)
		free(mlx->player);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_context(mlx->mlx);
}

static t_point	*get_player(char **map, t_point *player)
{
	size_t	i;
	size_t	j;

	player->x = 0;
	player->y = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				player->x = j;
				player->y = i;
				break ;
			}
			++j;
		}
		j = 0;
		++i;
	}
	return (player);
}

static size_t	get_c(char **map)
{
	size_t	i;
	size_t	j;
	size_t	c;

	i = 0;
	j = 0;
	c = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				++c;
			++j;
		}
		j = 0;
		++i;
	}
	return (c);
}

void	window_init(char **map)
{
	t_m	mlx;

	mlx.mlx = mlx_init();
	mlx.map = map;
	mlx.size = get_size(mlx.map);
	mlx.info = (mlx_window_create_info){
		.height = mlx.size.y,
		.width = mlx.size.x,
		.title = "so_long"
	};
	mlx.win = mlx_new_window(mlx.mlx, &mlx.info);
	mlx.player = malloc(sizeof(t_point));
	mlx.move = 0;
	get_player(map, mlx.player);
	mlx.c = get_c(mlx.map);
	mlx_set_fps_goal(mlx.mlx, 60);
	init_textures(&mlx);
	mlx_add_loop_hook(mlx.mlx, update, &mlx);
	mlx_on_event(mlx.mlx, mlx.win, MLX_KEYDOWN, key_hook, &mlx);
	mlx_on_event(mlx.mlx, mlx.win, MLX_WINDOW_EVENT, window_hook, mlx.mlx);
	mlx_loop(mlx.mlx);
	destroy_mlx(&mlx);
}
