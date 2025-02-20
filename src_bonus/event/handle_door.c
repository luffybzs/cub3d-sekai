/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:23:39 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/20 18:10:39 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	handle_door(t_cub3d *cube)
{
	t_trash_2	full;

	full.max_interact_distance = 2.0;
	full.player_x = cube->player.pos_x;
	full.player_y = cube->player.pos_y;
	full.target_x = full.player_x + round(cube->player.dir_x);
	full.target_y = full.player_y + round(cube->player.dir_y);
	full.distance = sqrt(pow(full.target_x - full.player_x, 2)
			+ pow(full.target_y - full.player_y, 2));
	if (full.distance <= full.max_interact_distance)
	{
		if (cube->all_maps[full.target_y][full.target_x] == 'D')
		{
			cube->all_maps[full.target_y][full.target_x] = 'O';
			printf("Porte ouverte\n");
		}
		else if (cube->all_maps[full.target_y][full.target_x] == 'O')
		{
			cube->all_maps[full.target_y][full.target_x] = 'D';
			printf("Porte fermée\n");
		}
	}
}

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