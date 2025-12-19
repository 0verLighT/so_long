/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 21:55:08 by amartel           #+#    #+#             */
/*   Updated: 2025/12/19 23:22:03 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MacroLibX/includes/mlx.h"

int main(void)
{
	mlx_context mlx = mlx_init();

	mlx_window_create_info info = {0};
	info.title = "Hello World!";
	info.width = 400;
	info.height = 400;
	mlx_window win = mlx_new_window(mlx, &info);

	while (1)
		pause();
	mlx_destroy_window(mlx, win);
	mlx_destroy_context(mlx);
}