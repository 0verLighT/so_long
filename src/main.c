/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 21:55:08 by amartel           #+#    #+#             */
/*   Updated: 2026/01/01 01:52:18 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	**map;
	size_t	i;

	map = NULL;
	if (ac != 2)
	{
		write(2, "./so_long <map.ber>\n", 21);
		return (-1);
	}
	map = checker(av, map);
	window_init(map);
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	return (0);
}
