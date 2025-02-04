/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:35:33 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/04 15:01:50 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void ft_error(t_cub3d *cube, char *msg, int error_code)
{
    //choisir si garder error_code 
    //centralisation de la gestion des erreur
    ft_putendl_fd(msg,2);
    cleanup(cube);
    exit(error_code);//garder exit ou prendre un simple return
}

void test_print(char **map)
{
    int i = 0, j = 0;
    
    printf("\n=== Map Content ===\n");

    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            printf("[%c]",map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}