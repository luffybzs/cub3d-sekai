/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:23:12 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/01/19 17:07:54 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int key_press(int keycode, t_cub3d *cube)
{
    if (keycode == KEY_W || keycode == KEY_S || 
        keycode == KEY_A || keycode == KEY_D)
    {
        // Gestion du mouvement du joueur
        if (keycode == KEY_W)
            printf("fornt\n");//move_forward(cube);
        else if (keycode == KEY_S)
            printf("back\n");//move_backward(cube);
        else if (keycode == KEY_A)
            printf("left\n");//move_left(cube);
        else if (keycode == KEY_D)
            printf("right\n");//move_right(cube);
    }
    else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
    {
        // Gestion de la rotation de la caméra
        if (keycode == KEY_LEFT)
            printf("rotate left\n");//rotate_left(cube);
        else
            printf("rotate right\n");//rotate_right(cube);
    }
    else if (keycode == XK_Escape)
        close_window(cube);

    return (0);
}
