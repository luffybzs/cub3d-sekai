/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:23:39 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/19 17:58:58 by wdaoudi-         ###   ########.fr       */
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
    int player_x = cube->player.pos_x;
    int player_y = cube->player.pos_y;
    
    // Distance maximale d'interaction (verifier les bugs avec la distance minimal)
    const double MAX_INTERACT_DISTANCE = 2.0;
    
    // Calcule la case ciblée (round arrondit entier plus proche)
    int target_x = player_x + round(cube->player.dir_x);
    int target_y = player_y + round(cube->player.dir_y);
    
    // Calcule la distance pythagore
    double distance = sqrt(pow(target_x - player_x, 2) + pow(target_y - player_y, 2));
    
    if (distance <= MAX_INTERACT_DISTANCE)
    {
        // Interaction avec la porte
        if (cube->all_maps[target_y][target_x] == 'D')
        {
            cube->all_maps[target_y][target_x] = 'O';
            printf("Porte ouverte\n");
        }
        else if (cube->all_maps[target_y][target_x] == 'O')
        {
            cube->all_maps[target_y][target_x] = 'D';
            printf("Porte fermée\n");
        }
    }
}
