/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:23:12 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/09 18:29:47 by wdaoudi-         ###   ########.fr       */
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
	else if (keycode == XK_Escape)
		close_window(cube);
	else if (keycode == XK_space)
		handle_door(cube);
	else if (keycode == XK_Return)
	{
		if (cube->enable_mouse == 0)
		{
			printf("enabling mouse movement\n");
			cube->enable_mouse = 1;
		}
		else
		{
			printf("disabling mouse movement\n");
			cube->enable_mouse = 0;
		}
	}
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
	cube->player.dir_x = cube->player.dir_x * cos(angle) - cube->player.dir_y* sin(angle);
	cube->player.dir_y = old_dir_x * sin(angle) + cube->player.dir_y* cos(angle);
	// Rotation du plan de la caméra
	old_plane_x = cube->player.plane_x;
	cube->player.plane_x = cube->player.plane_x * cos(angle)- cube->player.plane_y * sin(angle);
	cube->player.plane_y = old_plane_x * sin(angle) + cube->player.plane_y* cos(angle);
}
void rotate_right_mouse(t_cub3d *cube)
{
	rotate_angle(cube,0.1);
}
void rotate_left_mouse(t_cub3d *cube)
{
	rotate_angle(cube,-0.1);
}

int	mouse_move(int x, int y, t_cub3d *cube)
{
	double	rotation_speed;

	(void)y;
	rotation_speed = 0.1;
	(void)rotation_speed;
	//check if mouse movement is enable
	if(!cube->enable_mouse)
		return (0);
	// en fonction de la position de la souris dans l ecran tourne dans le sens indiquee
	if (x > cube->screen_width / 2)
		rotate_right_mouse(cube);
	else if (x < cube->screen_width / 2)
		rotate_left_mouse(cube);
	//recentre la souris
	mlx_mouse_move(cube->mlx, cube->win, cube->screen_width / 2,
			cube->screen_height / 2);
	return (0);
}
