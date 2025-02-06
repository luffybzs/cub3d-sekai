/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:23:39 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/06 15:28:12 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

// int ft_check_door(t_cub3d *cube3d)
// {
// 	int i = 0;
// 	int j = 0;
// 	bool door = false;

// 	while (cube3d->all_maps[j])
// 	{
// 		i = 0;
// 		while (cube3d->all_maps[j][i])
// 		{
// 			if ((cube3d->all_maps[j][i]) == 'D')
// 			{
				
// 				cube3d->x_door = i;
// 				cube3d->y_door = j;
// 			}
// 			i++;
// 		}
// 		j++;
// 	}
// 	if (player == false)
// 		return (EXIT_FAILURE);
// 	return (EXIT_SUCCESS);
// } 

void handle_door(t_cub3d *cube)
{
	int player_x;
	int player_y;
	
	player_x = cube->player.pos_x;
	player_y = cube->player.pos_y;
	
	if (cube->all_maps[player_y][player_x + 1] == 'D' ||
	cube->all_maps[player_y][player_x - 1] == 'D' ||
	cube->all_maps[player_y + 1][player_x] == 'D' ||
	cube->all_maps[player_y - 1][player_x] == 'D' ||)
	{
		//transformer le D en O 
		return;
	}
	else if (cube->all_maps[player_y][player_x + 1] == 'O' ||
	cube->all_maps[player_y][player_x - 1] == 'O' ||
	cube->all_maps[player_y + 1][player_x] == 'O' ||
	cube->all_maps[player_y - 1][player_x] == 'O' ||)
	{
		//transformer le O en D
		return;
	}
	return;
}