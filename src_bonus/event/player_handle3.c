/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_handle3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:56:44 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/24 16:39:31 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	mouse_move(int x, int y, t_cub3d *cube)
{
	double	rotation_speed;

	(void)y;
	rotation_speed = 0.1;
	(void)rotation_speed;
	if (!cube->enable_mouse)
		return (0);
	if (x > cube->screen_width / 2)
		rotate_right_mouse(cube);
	else if (x < cube->screen_width / 2)
		rotate_left_mouse(cube);
	mlx_mouse_move(cube->mlx, cube->win, cube->screen_width / 2,
		cube->screen_height / 2);
	return (0);
}

void	key_press2(t_cub3d *cube, int keycode)
{
	if (keycode == 65307)
		close_window(cube);
	else if (keycode == 32)
		handle_door(cube);
	else if (keycode == 65293)
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
}
