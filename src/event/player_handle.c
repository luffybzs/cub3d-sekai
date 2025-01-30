/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:23:12 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/01/30 22:41:26 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//gerer les mouvements horizontaux de la souris (encore a faire)
int	key_press(int keycode, t_cub3d *cube)
{
	if (keycode == KEY_W || keycode == KEY_S ||
		keycode == KEY_A || keycode == KEY_D)
	{
		// Gestion du mouvement du joueur
		if (keycode == KEY_W)
			move_forward(cube);
		else if (keycode == KEY_S)
			move_backward(cube);
		else if (keycode == KEY_A)
			rotate_left(cube);
		else if (keycode == KEY_D)
			rotate_right(cube);
	}
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		// Gestion de la rotation de la caméra
		if (keycode == KEY_LEFT)
			rotate_left(cube);
		else
			rotate_right(cube);
	}
	else if (keycode == XK_Escape)
		close_window(cube);
	return (0);
}
void	move_forward(t_cub3d *cube)
{
	double	newX;
	double	newY;
	double	moveSpeed;

	moveSpeed = 0.1;
	// Calcul de la nouvelle position
	newX = cube->player.pos_x + cube->player.dir_x * moveSpeed;
	newY = cube->player.pos_y + cube->player.dir_y * moveSpeed;
	// Vérification des collisions avec les murs
	if (cube->all_maps[(int)cube->player.pos_y][(int)newX] != '1')
		cube->player.pos_x = newX;
	if (cube->all_maps[(int)newY][(int)cube->player.pos_x] != '1')
		cube->player.pos_y = newY;
}


void	move_backward(t_cub3d *cube)
{
	double newX;
	double newY;
	double moveSpeed;

	moveSpeed = 0.1;

	// Calcul de la nouvelle position (en sens inverse du mouvement avant)
	newX = cube->player.pos_x - cube->player.dir_x * moveSpeed;
	newY = cube->player.pos_y - cube->player.dir_y * moveSpeed;

	// Vérification des collisions avec les murs
	if (cube->all_maps[(int)cube->player.pos_y][(int)newX] != '1')
		cube->player.pos_x = newX;
	if (cube->all_maps[(int)newY][(int)cube->player.pos_x] != '1')
		cube->player.pos_y = newY;
}
void	rotate_right(t_cub3d *cube)
{
	double	oldDirX;
	double	oldPlaneX;
	double	rotSpeed;

	rotSpeed = 0.1;
	oldDirX = cube->player.dir_x;
	// Rotation de la direction
	cube->player.dir_x = cube->player.dir_x * cos(rotSpeed)
		- cube->player.dir_y * sin(rotSpeed);
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
	cube->player.dir_x = cube->player.dir_x * cos(-rotSpeed) - cube->player.dir_y
		* sin(-rotSpeed);
	cube->player.dir_y = oldDirX * sin(-rotSpeed) + cube->player.dir_y
		* cos(-rotSpeed);
	// Rotation du plan de la caméra
	oldPlaneX = cube->player.plane_x;
	cube->player.plane_x = cube->player.plane_x * cos(-rotSpeed)
		- cube->player.plane_y * sin(-rotSpeed);
	cube->player.plane_y = oldPlaneX * sin(-rotSpeed) + cube->player.plane_y
		* cos(-rotSpeed);
}
