/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:03:47 by ayarab            #+#    #+#             */
/*   Updated: 2025/01/09 21:08:52 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cube3d_h
# define cube3d_h

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
    char *av1;
    char *EA;
    char *WE;
    char *SO;
    char *NO;
    int    ac;
}    t_cub3d;


#endif