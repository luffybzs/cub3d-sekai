/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:33:27 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/01/11 16:35:32 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"



int main(int ac, char **av)  // temporaire raycasting
{
	t_map_info map;
	

    (void)ac;
    (void)av;
	init_struct_temp(&map);
	
	if (init_mlx(&map) || !map.mlx.mlx || !map.mlx.win)
		return (printf("fail to init\n"));
	return (0);
}