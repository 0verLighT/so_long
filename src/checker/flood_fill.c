/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 01:25:59 by amartel           #+#    #+#             */
/*   Updated: 2025/12/27 17:08:21 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// - Flood fill -> check the map possibility.
// checker if E and P is possible and all C

static void fill(char **map, t_point size, char start, size_t row, size_t col)
{
	if (row >= size.y || col >= size.x)
		return ;
	if (map[row][col] == 'X' || map[row][col] == '1')
		return ;
	map[row][col] = 'X';
	fill(map, size, start, row - 1, col);
	fill(map, size, start, row + 1, col);
	fill(map, size, start, row, col - 1);
	fill(map, size, start, row, col + 1);
}

void	flood_fill(char **map, t_map data, size_t rows, size_t cols)
{
	char start;
	t_point	size;

	size.x = cols;
	size.y = rows;
	start = map[data.P.x][data.P.y];
	fill(map, size, start, data.P.x, data.P.y);
}