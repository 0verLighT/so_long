/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 00:18:54 by amartel           #+#    #+#             */
/*   Updated: 2026/01/01 16:04:17 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
- [x] The map can only contain these 5 characters: '0', '1', 'C', 'E', 'P'.
- [x] Any other character must trigger an error.

- [x] Must contain at least 1 Collectible (C).
- [x] Must contain exactly 1 Exit (E).
- [x] Must contain exactly 1 Starting Position (P).
- [x] Duplicates of E or P are forbidden.

- [x] The map must be enclosed/surrounded by walls. If it is not, the program 
 must return an error. -> check [0][j] = 1 check [max][j] = 1 same for colmun.
*/

static void	map_count_event(char **map, int character)
{
	static size_t	c = 0;
	static size_t	e = 0;
	static size_t	p = 0;

	if (!map)
	{
		if (character == 'C')
			++c;
		else if (character == 'E')
			++e;
		else if (character == 'P')
			++p;
		else if (character == '1' || character == '0')
			return ;
		else
			free_before_err(map, "Error");
	}
	else if (c == 0 || p != 1 || e != 1)
		free_before_err(map, "Error");
}

static void	map_content_border(char **m, size_t rows)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (m[i])
	{
		while (m[i][j])
		{
			if (((i == 0 || i == rows) || (j == 0 || j == ft_strlen(m[i]) - 1))
				&& m[i][j] != '1')
				free_before_err(m, "Error");
			if (m[i][j] == '0' || m[i][j] == '1' || m[i][j] == 'C'
				|| m[i][j] == 'E' || m[i][j] == 'P')
			{
				map_count_event(NULL, m[i][j]);
				++j;
			}
			else
				free_before_err(m, "Error");
		}
		j = 0;
		++i;
	}
	map_count_event(m, '\0');
}

static t_map	get_data_map(char **map)
{
	t_map	data;
	size_t	i;
	size_t	j;

	data.c = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				data.p.x = j;
				data.p.y = i;
			}
			else if (map[i][j] == 'C')
				++data.c;
			++j;
		}
		j = 0;
		++i;
	}
	return (data);
}

void	map_content_checker(char **map)
{
	size_t		rows;
	size_t		cols;
	t_map		data;
	char		**temp_map;
	size_t		i;

	rows = 0;
	while (map[rows])
		++rows;
	map_content_border(map, rows - 1);
	cols = ft_strlen(map[0]);
	if (cols > 25)
		free_before_err(map, "Invalid size map");
	data = get_data_map(map);
	i = 0;
	temp_map = malloc(sizeof(char *) * (rows + 1));
	while (i < rows)
	{
		temp_map[i] = ft_strdup(map[i]);
		++i;
	}
	temp_map[i] = NULL;
	if (flood_fill(temp_map, data, rows, cols) == -1)
		free_before_err(map, "Error");
}
