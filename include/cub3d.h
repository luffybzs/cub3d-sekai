/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:03:47 by ayarab            #+#    #+#             */
/*   Updated: 2025/01/11 04:45:56 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cube3d_h
# define cube3d_h

#include "gc.h"
#include "./../libft/libft.h"
#include "./../libft/get_next_line/get_next_line.h"
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_cub3d
{
    char **all_maps;
	char **map;
    char *av1;
    char *EA;
    char *WE;
    char *SO;
    char *NO;
	char *F;
	char *C;
    int    ac;
}    t_cub3d;

int ft_check_av1(t_cub3d *cube3d);
void ft_fail_free(t_cub3d *cube3d);
int ft_fill_data(int ac, char **av, t_cub3d *cube3d);
int ft_search_cardinal_points(t_cub3d *cube3d);
int ft_search_info(char *av1, t_cub3d *cube3d);

#endif