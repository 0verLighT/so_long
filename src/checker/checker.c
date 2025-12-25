/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 01:19:32 by amartel           #+#    #+#             */
/*   Updated: 2025/12/25 03:10:10 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*

- The file extention must be '.ber'
- You must verify if there is a valid path in the map. -> check if it's valid path (return code get_next_line)

- The map can only contain these 5 characters: '0', '1', 'C', 'E', 'P'.
- Any other character must trigger an error.

- Must contain at least 1 Collectible (C).
- Must contain exactly 1 Exit (E).
- Must contain exactly 1 Starting Position (P).
- Duplicates of E or P are forbidden.

- The map must be rectangular. all rows and colmun is exactaly same ( note : square is also accept)

- The map must be enclosed/surrounded by walls. If it is not, the program must
return an error. -> check [0][j] = 1 check [max][j] = 1 same for colmun.

- Flood fill -> check the map possibility.

*/

static int	count_row(char *pathfile)
{
	char	*line;
	size_t	count;
	int		fd;

	fd = open(pathfile, O_RDONLY);
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		++count;
		free(line);
	}
	close(fd);
	return (count);
}

char	**append_map(char *pathfile)
{
	int		fd;
	size_t	rows;
	char	**map;
	char	*line;
	size_t	i;

	rows = count_row(pathfile);
	if (rows <= 0)
		error("Invalid map : 0 rows detect");
	map = malloc(sizeof(char *) * (rows + 1));
	if (!map)
		error("malloc error");
	fd = open(pathfile, O_RDONLY);
	i = 0;
	while (i < rows)
	{
		line = get_next_line(fd);
		map[i] = ft_strdup(line);
		++i;
		free(line);
	}
	close(fd);
	map[i] = NULL;
	return (map);
}

static void	valid_path(char **av)
{
	int	fd;

	if (!ft_strnstr(av[1] + ft_strlen(av[1]) - 4, ".ber", 4))
		error("The file must be \".ber\" !\n");
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error("Error");
	close(fd);
}

int	checker(char **av)
{
	char		**map;
	size_t		i;

	valid_path(av);
	map = append_map(av[1]);
	i = 0;
	while (map[i])
	{
		printf("Rows %ld : %s", i, map[i]); // rows include '\n' TODO: rm him
		free(map[i]);
		++i;
	}
	free(map);
	return (0);
}
