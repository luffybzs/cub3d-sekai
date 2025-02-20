/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_handle2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:45:58 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/20 15:20:55 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	rotate_right(t_cub3d *cube)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	rot_speed = 0.1;
	old_dir_x = cube->player.dir_x;
	cube->player.dir_x = cube->player.dir_x * cos(rot_speed)
		- cube->player.dir_y * sin(rot_speed);
	cube->player.dir_y = old_dir_x * sin(rot_speed) + cube->player.dir_y
		* cos(rot_speed);
	old_plane_x = cube->player.plane_x;
	cube->player.plane_x = cube->player.plane_x * cos(rot_speed)
		- cube->player.plane_y * sin(rot_speed);
	cube->player.plane_y = old_plane_x * sin(rot_speed) + cube->player.plane_y
		* cos(rot_speed);
}

void	rotate_left(t_cub3d *cube)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	rot_speed = 0.1;
	old_dir_x = cube->player.dir_x;
	cube->player.dir_x = cube->player.dir_x * cos(-rot_speed)
		- cube->player.dir_y * sin(-rot_speed);
	cube->player.dir_y = old_dir_x * sin(-rot_speed) + cube->player.dir_y
		* cos(-rot_speed);
	old_plane_x = cube->player.plane_x;
	cube->player.plane_x = cube->player.plane_x * cos(-rot_speed)
		- cube->player.plane_y * sin(-rot_speed);
	cube->player.plane_y = old_plane_x * sin(-rot_speed) + cube->player.plane_y
		* cos(-rot_speed);
}
