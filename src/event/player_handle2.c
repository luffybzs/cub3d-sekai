/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_handle2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:45:58 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/11 15:46:34 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
