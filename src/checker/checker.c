/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 01:19:32 by amartel           #+#    #+#             */
/*   Updated: 2025/12/24 01:42:07 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
int	checker(char **av)
{
	return (0);
}