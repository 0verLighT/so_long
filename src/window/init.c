/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 23:55:45 by amartel           #+#    #+#             */
/*   Updated: 2025/12/30 14:11:11 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



static void	init_textures(mlx_t *mlx)
{
	int	dummy;
	static char *textures[] = {
		"asset/textures/blue.png",
		"asset/textures/black.png",
		"asset/textures/grey.png",
		"asset/textures/green.png",
		"asset/textures/red.png",
		NULL
	};
	mlx->blue = mlx_new_image_from_file(mlx->mlx, (char *)textures[0], &dummy, &dummy);
	mlx->black = mlx_new_image_from_file(mlx->mlx, (char *)textures[1], &dummy, &dummy);
	mlx->red = mlx_new_image_from_file(mlx->mlx, (char *)textures[4], &dummy, &dummy);
	mlx->green = mlx_new_image_from_file(mlx->mlx, (char *)textures[3], &dummy, &dummy);
	mlx->grey = mlx_new_image_from_file(mlx->mlx, (char *)textures[2], &dummy, &dummy);
}

void	window_init(void)
{
	mlx_t		mlx;

	mlx.mlx = mlx_init();
	mlx.info = (mlx_window_create_info){
		.height = 400,
		.width = 400,
		.title = "so_long"
	};
	mlx.win = mlx_new_window(mlx.mlx, &mlx.info);
	mlx_set_fps_goal(mlx.mlx, 60);
	mlx_on_event(mlx.mlx, mlx.win, MLX_KEYDOWN, key_hook, mlx.mlx);
	mlx_on_event(mlx.mlx, mlx.win, MLX_WINDOW_EVENT, window_hook, mlx.mlx);
	init_textures(&mlx);
	
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.blue, 0, 0);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.black, 16, 0);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.red, 0, 16);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.green, 32, 32);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.grey, 48, 32);
	mlx_loop(mlx.mlx);
	mlx_destroy_window(mlx.mlx, mlx.win);
	mlx_destroy_context(mlx.mlx);
}
