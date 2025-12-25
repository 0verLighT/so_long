/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 21:55:08 by amartel           #+#    #+#             */
/*   Updated: 2025/12/24 23:51:46 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void window_init(void)
{
	mlx_context mlx = mlx_init();

	mlx_window_create_info info = {0};
	info.title = "so_long";
	info.width = 400;
	info.height = 400;
	mlx_window win = mlx_new_window(mlx, &info);

	mlx_set_fps_goal(mlx, 60);
	mlx_on_event(mlx, win, MLX_KEYDOWN, key_hook, mlx);
	mlx_on_event(mlx, win, MLX_WINDOW_EVENT, window_hook, mlx);
	mlx_loop(mlx);

	mlx_destroy_window(mlx, win);
	mlx_destroy_context(mlx);
}
int main(int ac, char **av)
{
	if (ac != 2)
		return (-1);
	if (checker(av) == 1)
		return (-1);
	return (0);
}
