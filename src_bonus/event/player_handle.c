/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:23:12 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/12 14:03:19 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

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
		else if (keycode == KEY_A) // gerer les mouvements lateraux
			move_left(cube);
		else if (keycode == KEY_D)
			move_right(cube);
	}
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		// Gestion de la rotation de la caméra
		if (keycode == KEY_LEFT)
			rotate_left(cube);
		else
			rotate_right(cube);
	}
	else
		key_press2(cube,keycode);
	return (0);
}

void	move_backward(t_cub3d *cube)
{
	double	newX;
	double	newY;
	double	moveSpeed;

	moveSpeed = 0.1;
	// Calcul de la nouvelle position (en sens inverse du mouvement avant)
	newX = cube->player.pos_x - cube->player.dir_x * moveSpeed;
	newY = cube->player.pos_y - cube->player.dir_y * moveSpeed;
	// Vérification des collisions avec les murs
	if (cube->all_maps[(int)cube->player.pos_y][(int)newX] != '1'
		&& cube->all_maps[(int)cube->player.pos_y][(int)newX] != 'D')
		cube->player.pos_x = newX;
	if (cube->all_maps[(int)newY][(int)cube->player.pos_x] != '1'
		&& cube->all_maps[(int)newY][(int)cube->player.pos_x] != 'D')
		cube->player.pos_y = newY;
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
	if (cube->all_maps[(int)cube->player.pos_y][(int)newX] != '1'
		&& cube->all_maps[(int)cube->player.pos_y][(int)newX] != 'D')
		cube->player.pos_x = newX;
	if (cube->all_maps[(int)newY][(int)cube->player.pos_x] != '1'
		&& cube->all_maps[(int)newY][(int)cube->player.pos_x] != 'D')
		cube->player.pos_y = newY;
}

void	move_right(t_cub3d *cube)
{
	double	newX;
	double	newY;
	double	moveSpeed;

	moveSpeed = 0.1;
	// Calcul de la nouvelle position (en sens inverse du mouvement avant)
	newX = cube->player.pos_x + cube->player.plane_x * moveSpeed;
	//cube->player.pos_x +(cube->player.dir_x)* moveSpeed;
	newY = cube->player.pos_y + cube->player.plane_y * moveSpeed;
	// Vérification des collisions avec les murs
	if (cube->all_maps[(int)cube->player.pos_y][(int)newX] != '1'
		&& cube->all_maps[(int)cube->player.pos_y][(int)newX] != 'D')
		cube->player.pos_x = newX;
	if (cube->all_maps[(int)newY][(int)cube->player.pos_x] != '1'
		&& cube->all_maps[(int)newY][(int)cube->player.pos_x] != 'D')
		cube->player.pos_y = newY;
}

void	move_left(t_cub3d *cube)
{
	double	newX;
	double	newY;
	double	moveSpeed;

	moveSpeed = 0.1;
	// Calcul de la nouvelle position (en sens inverse du mouvement avant)
	newX = cube->player.pos_x - cube->player.plane_x * moveSpeed;
	newY = cube->player.pos_y - cube->player.plane_y * moveSpeed;
	// Vérification des collisions avec les murs
	if (cube->all_maps[(int)cube->player.pos_y][(int)newX] != '1'
		&& cube->all_maps[(int)cube->player.pos_y][(int)newX] != 'D')
		cube->player.pos_x = newX;
	if (cube->all_maps[(int)newY][(int)cube->player.pos_x] != '1'
		&& cube->all_maps[(int)newY][(int)cube->player.pos_x] != 'D')
		cube->player.pos_y = newY;
}
