/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:35:33 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/01/28 23:38:18 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void ft_error(t_cub3d *cube, char *msg, int error_code)
{
    //choisir si garder error_code 
    //centralisation de la gestion des erreur
    ft_putendl_fd(message,2);
    cleanup(cube);
    exit(error_code);//garder exit ou prendre un simple return
}