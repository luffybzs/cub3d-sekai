/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:23:12 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/24 12:42:26 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	key_press(int keycode, t_cub3d *cube)
{
	if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A
		|| keycode == KEY_D)
	{
		if (keycode == KEY_W)
			move_forward(cube);
		else if (keycode == KEY_S)
			move_backward(cube);
		else if (keycode == KEY_A)
			move_left(cube);
		else if (keycode == KEY_D)
			move_right(cube);
	}
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		if (keycode == KEY_LEFT)
			rotate_left(cube);
		else
			rotate_right(cube);
	}
	else if (keycode == XK_Escape)
		close_window(cube);
	return (0);
}

void	move_backward(t_cub3d *cube)
{
	double	new_x;
	double	new_y;
	double	move_speed;

	move_speed = 0.1;
	new_x = cube->player.pos_x - cube->player.dir_x * move_speed;
	new_y = cube->player.pos_y - cube->player.dir_y * move_speed;
	if (cube->all_maps[(int)cube->player.pos_y][(int)new_x] != '1')
		cube->player.pos_x = new_x;
	if (cube->all_maps[(int)new_y][(int)cube->player.pos_x] != '1')
		cube->player.pos_y = new_y;
}

void	move_forward(t_cub3d *cube)
{
	double	new_x;
	double	new_y;
	double	move_speed;

	move_speed = 0.1;
	new_x = cube->player.pos_x + cube->player.dir_x * move_speed;
	new_y = cube->player.pos_y + cube->player.dir_y * move_speed;
	if (cube->all_maps[(int)cube->player.pos_y][(int)new_x] != '1')
		cube->player.pos_x = new_x;
	if (cube->all_maps[(int)new_y][(int)cube->player.pos_x] != '1')
		cube->player.pos_y = new_y;
}

void	move_right(t_cub3d *cube)
{
	double	new_x;
	double	new_y;
	double	move_speed;

	move_speed = 0.1;
	new_x = cube->player.pos_x + cube->player.plane_x * move_speed;
	new_y = cube->player.pos_y + cube->player.plane_y * move_speed;
	if (cube->all_maps[(int)cube->player.pos_y][(int)new_x] != '1')
		cube->player.pos_x = new_x;
	if (cube->all_maps[(int)new_y][(int)cube->player.pos_x] != '1')
		cube->player.pos_y = new_y;
}

void	move_left(t_cub3d *cube)
{
	double	new_x;
	double	new_y;
	double	move_speed;

	move_speed = 0.1;
	new_x = cube->player.pos_x - cube->player.plane_x * move_speed;
	new_y = cube->player.pos_y - cube->player.plane_y * move_speed;
	if (cube->all_maps[(int)cube->player.pos_y][(int)new_x] != '1')
		cube->player.pos_x = new_x;
	if (cube->all_maps[(int)new_y][(int)cube->player.pos_x] != '1')
		cube->player.pos_y = new_y;
}
