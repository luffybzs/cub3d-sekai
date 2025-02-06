/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:33:27 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/06 17:34:25 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d_bonus.h"

int	game_loop(t_cub3d *cube)
{
	if (!cube || !cube->mlx || !cube->win)
		return (1);
	if (cube->map_width == 0 || cube->map_height == 0)
	{
		printf("Error: Invalid map dimensions in game loop\n");
		return (1);
	}
	ft_memset(cube->buffer.addr, 0, cube->screen_width * cube->screen_height
		* sizeof(int));
	if (draw_background(cube))
		return (1);
	raycasting(cube);
	draw_minimap(cube);
	if (cube->buffer.img)
		mlx_put_image_to_window(cube->mlx, cube->win, cube->buffer.img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_cub3d cube = {0};

	// temporaire pour les tests
	if (ac != 2)
		return (ft_putendl_fd("Error\nNot Enough argument", 2), 1);
	if (ft_fill_data(ac, av, &cube) == EXIT_FAILURE)
		return (ft_fail_free(&cube), EXIT_FAILURE);
	if (init_cub3d(&cube) == 1)
		return (cleanup(&cube), 1);
	if (cube.mlx && cube.win)
	{
		mlx_hook(cube.win, 17, 0, close_window, &cube);
		mlx_hook(cube.win, 2, 1L << 0, key_press, &cube);
		mlx_loop_hook(cube.mlx, game_loop, &cube);
		mlx_loop(cube.mlx);
	}
	cleanup(&cube);
	return (ft_fail_free(&cube), EXIT_SUCCESS);
}