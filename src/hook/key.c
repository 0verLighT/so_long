/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 00:17:56 by amartel           #+#    #+#             */
/*   Updated: 2025/12/24 01:44:01 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Code key usefull

'w' -> 26;
's' -> 22;
'd' -> 7;
'a' -> 4;
*/
void key_hook(int key, void *param)
{
	if (key == 41)
		mlx_loop_end((mlx_context)param);
}