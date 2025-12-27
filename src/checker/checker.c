/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 01:19:32 by amartel           #+#    #+#             */
/*   Updated: 2025/12/27 23:32:38 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*

- [x] The file extention must be '.ber'
- [x] You must verify if there is a valid path in the map. -> check if it's 
	valid path (return code get_next_line)
- [x] The map must be rectangular. all rows and colmun is exactaly same
	( note : square is also accept)
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
// test with frist line \n
static char	*line_checker(char *line)
{
	char			*newline;
	static size_t	prev_len = 0;
	size_t			len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		--len;
	if ((prev_len && prev_len != len) || !len)
		return (NULL);
	newline = ft_strndup(line, len);
	if (!prev_len)
		ft_strlen(newline);
	prev_len = len;
	return (newline);
	
}

static char	**append_map(char *pathfile)
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
		map[i] = line_checker(line);
		free(line);
		if (!map[i++])
			free_gnl_err(map, "Error\n");
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

void	checker(char **av, char **map)
{
	size_t		i;

	valid_path(av);
	map = append_map(av[1]);
	i = 0;
	map_content_checker(map);
	while (map[i])
	{
		printf("Rows %ld : %s\n", i, map[i]);
		free(map[i]);
		++i;
	}
	free(map);
}
