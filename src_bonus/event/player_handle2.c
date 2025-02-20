/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_handle2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:55:31 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/20 16:19:36 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

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

void	rotate_angle(t_cub3d *cube, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cube->player.dir_x;
	cube->player.dir_x = cube->player.dir_x * cos(angle) - cube->player.dir_y
		* sin(angle);
	cube->player.dir_y = old_dir_x * sin(angle) + cube->player.dir_y
		* cos(angle);
	old_plane_x = cube->player.plane_x;
	cube->player.plane_x = cube->player.plane_x * cos(angle)
		- cube->player.plane_y * sin(angle);
	cube->player.plane_y = old_plane_x * sin(angle) + cube->player.plane_y
		* cos(angle);
}

void	rotate_right_mouse(t_cub3d *cube)
{
	rotate_angle(cube, 0.1);
}

void	rotate_left_mouse(t_cub3d *cube)
{
	rotate_angle(cube, -0.1);
}
