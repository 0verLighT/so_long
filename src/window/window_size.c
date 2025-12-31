/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 23:23:56 by amartel           #+#    #+#             */
/*   Updated: 2025/12/31 23:33:21 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	get_size(char **map)
{
	t_point	size;
	size_t	i;

	i = 0;
	while (map[i])
		++i;
	size.x = (ft_strlen(map[0]) * 16);
	size.y = i * 16;
	return (size);
}
