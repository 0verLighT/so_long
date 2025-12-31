/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 01:25:59 by amartel           #+#    #+#             */
/*   Updated: 2025/12/31 01:20:33 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// - Flood fill -> check the map possibility.
// checker if E and P is possible and all C

int	check_flood_fill(char **map)
{
	size_t	i;
	size_t	j;
	int		return_code;

	i = 0;
	j = 0;
	return_code = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				return_code = -1;
				break ;
			}
			++j;
		}
		j = 0;
		++i;
	}
	return (return_code);
}

static void	fill(char **map, t_point size, size_t row, size_t col)
{
	if (row >= size.y || col >= size.x)
		return ;
	if (map[row][col] == 'X' || map[row][col] == '1')
		return ;
	map[row][col] = 'X';
	fill(map, size, row - 1, col);
	fill(map, size, row + 1, col);
	fill(map, size, row, col - 1);
	fill(map, size, row, col + 1);
}

int	flood_fill(char **map, t_map data, size_t rows, size_t cols)
{
	t_point	size;
	int		return_code;
	size_t	i;

	size.x = cols;
	size.y = rows;
	fill(map, size, data.P.y, data.P.x);
	return_code = check_flood_fill(map);
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	return (return_code);
}
