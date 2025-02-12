/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_handle2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:55:31 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/12 13:56:53 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	rotate_right(t_cub3d *cube)
{
	double	oldDirX;
	double	oldPlaneX;
	double	rotSpeed;

	rotSpeed = 0.1;
	oldDirX = cube->player.dir_x;
	// Rotation de la direction
	cube->player.dir_x = cube->player.dir_x * cos(rotSpeed) - cube->player.dir_y
		* sin(rotSpeed);
	cube->player.dir_y = oldDirX * sin(rotSpeed) + cube->player.dir_y
		* cos(rotSpeed);
	// Rotation du plan de la caméra
	oldPlaneX = cube->player.plane_x;
	cube->player.plane_x = cube->player.plane_x * cos(rotSpeed)
		- cube->player.plane_y * sin(rotSpeed);
	cube->player.plane_y = oldPlaneX * sin(rotSpeed) + cube->player.plane_y
		* cos(rotSpeed);
}
void	rotate_left(t_cub3d *cube)
{
	double	oldDirX;
	double	oldPlaneX;
	double	rotSpeed;

	rotSpeed = 0.1;
	oldDirX = cube->player.dir_x;
	// Rotation de la direction (dans le sens inverse des aiguilles d'une montre)
	cube->player.dir_x = cube->player.dir_x * cos(-rotSpeed)
		- cube->player.dir_y * sin(-rotSpeed);
	cube->player.dir_y = oldDirX * sin(-rotSpeed) + cube->player.dir_y
		* cos(-rotSpeed);
	// Rotation du plan de la caméra
	oldPlaneX = cube->player.plane_x;
	cube->player.plane_x = cube->player.plane_x * cos(-rotSpeed)
		- cube->player.plane_y * sin(-rotSpeed);
	cube->player.plane_y = oldPlaneX * sin(-rotSpeed) + cube->player.plane_y
		* cos(-rotSpeed);
}

void	rotate_angle(t_cub3d *cube, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cube->player.dir_x;
	//rotation du vecteur
	cube->player.dir_x = cube->player.dir_x * cos(angle) - cube->player.dir_y
		* sin(angle);
	cube->player.dir_y = old_dir_x * sin(angle) + cube->player.dir_y
		* cos(angle);
	// Rotation du plan de la caméra
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