/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:44:00 by amartel           #+#    #+#             */
/*   Updated: 2025/12/25 01:10:00 by amartel          ###   ########.fr       */
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
