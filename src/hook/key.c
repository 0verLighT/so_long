/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 00:17:56 by amartel           #+#    #+#             */
/*   Updated: 2025/12/31 19:59:12 by amartel          ###   ########.fr       */
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
void	key_hook(int key, void *param)
{
	t_m	*m;

	m = (t_m *)param;
	if (key == 41)
		mlx_loop_end(m->mlx);
	if (key == 26)
		on_up(m);
	if (key == 22)
		on_down(m);
	if (key == 7)
		on_right(m);
	if (key == 4)
		on_left(m);
}
