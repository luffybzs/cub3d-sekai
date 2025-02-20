/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:52:28 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/20 18:10:51 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	init_player(t_cub3d *cube)
{
	cube->player.pos_x = cube->x_spwan_p + 0.5;
	cube->player.pos_y = cube->y_spwan_p + 0.5;
	if (cube->direction == 'N')
	{
		cube->player.dir_x = 0;
		cube->player.dir_y = -1;
		cube->player.plane_x = 0.66;
		cube->player.plane_y = 0;
	}
	if (cube->direction == 'S')
	{
		cube->player.dir_x = 0;
		cube->player.dir_y = 1;
		cube->player.plane_x = -0.66;
		cube->player.plane_y = 0;
	}
	init_player2(cube);
}

void	init_player2(t_cub3d *cube)
{
	if (cube->direction == 'E')
	{
		cube->player.dir_x = 1;
		cube->player.dir_y = 0;
		cube->player.plane_x = 0;
		cube->player.plane_y = 0.66;
	}
	if (cube->direction == 'W')
	{
		cube->player.dir_x = -1;
		cube->player.dir_y = 0;
		cube->player.plane_x = 0;
		cube->player.plane_y = -0.66;
	}
}
