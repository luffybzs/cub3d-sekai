/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:23:12 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/24 16:40:33 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	key_press(int keycode, t_cub3d *cube)
{
	if (keycode == 119 || keycode == 115 || keycode == 97 || keycode == 100)
	{
		if (keycode == 119)
			move_forward(cube);
		else if (keycode == 115)
			move_backward(cube);
		else if (keycode == 97)
			move_left(cube);
		else if (keycode == 100)
			move_right(cube);
	}
	else if (keycode == 65361 || keycode == 65363)
	{
		if (keycode == 65361)
			rotate_left(cube);
		else
			rotate_right(cube);
	}
	else if (keycode == 65307)
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
