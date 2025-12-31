/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 00:18:54 by amartel           #+#    #+#             */
/*   Updated: 2025/12/31 01:12:41 by amartel          ###   ########.fr       */
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
			free_before_err(map, "Error\n");
	}
	else if (c == 0 || p != 1 || e != 1)
		free_before_err(map, "Error\n");
}

static void	map_content_border(char **map, size_t rows)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (((i == 0 || i == rows) || (j == 0 || j == ft_strlen(map[i])))
				&& map[i][j] != '1')
				free_before_err(map, "Error\n");
			if (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'C'
				|| map[i][j] == 'E' || map[i][j] == 'P')
			{
				map_count_event(NULL, map[i][j]);
				++j;
			}
			else
				free_before_err(map, "Error\n");
		}
		j = 0;
		++i;
	}
	map_count_event(map, '\0');
}

static t_map	get_data_map(char **map)
{
	t_map	data;
	size_t	i;
	size_t	j;

	data.C = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				data.P.x = j;
				data.P.y = i;
			}
			else if (map[i][j] == 'C')
				++data.C;
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
	map_content_border(map, rows);
	cols = ft_strlen(map[0]);
	data = get_data_map(map);
	i = 0;
	temp_map = malloc(sizeof(char *) * (rows + 1));
	while (i < rows)
	{
		temp_map[i] = ft_strdup(map[i]);
		++i;
	}
	temp_map[i] = NULL;
	if (flood_fill(temp_map, data, rows, cols) == -1 || cols > 25)
		free_before_err(map, "Error");
}
