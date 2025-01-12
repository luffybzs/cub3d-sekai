/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:33:27 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/01/12 17:08:51 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"

int	main(int ac, char **av) // temporaire raycasting
{
	t_cub3d cube;
	
	(void)cube;
	(void)ac;
	(void)av;
	if(init_cub3d(&cube) == 1)
		return (1);

	mlx_hook(cube.win, 17, 0, close_window, &cube);
	mlx_hook(cube.win, 2, 1L << 0, key_press, &cube);
	mlx_loop_hook(cube.mlx, /* render frame qui dessine*/ NULL, &cube);
	mlx_loop(cube.mlx);
	cleanup(&cube);
	return (0);
}