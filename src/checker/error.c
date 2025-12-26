/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:44:00 by amartel           #+#    #+#             */
/*   Updated: 2025/12/25 19:02:22 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *msg)
{
	if (errno)
	{
		perror(msg);
		exit(1);
	}
	else
	{
		write(2, msg, ft_strlen(msg));
		exit(1);
	}
}

void	free_before_err(char **map, char *msg)
{
	size_t	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	get_next_line(-1);
	write(2, msg, ft_strlen(msg));
	exit(1);
}
