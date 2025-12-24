/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 00:19:22 by amartel           #+#    #+#             */
/*   Updated: 2025/12/24 01:20:26 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../MacroLibX/includes/mlx.h"
#include <unistd.h>

typedef struct
{
	mlx_context mlx;
	mlx_window win;
} mlx_t;

void key_hook(int key, void *param);
void window_hook(int event, void *param);
int	map(void);
int	checker(char **av);

# endif