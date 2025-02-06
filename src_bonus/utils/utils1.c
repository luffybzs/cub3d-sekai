/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:35:33 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/06 14:35:26 by wdaoudi-         ###   ########.fr       */
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

void *ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
    void *new_ptr;
    char *src;
    char *dst;
    size_t i;

    if (!ptr && new_size)
        return (malloc(new_size));
    if (ptr && !new_size)
        return (free(ptr),NULL);
    if (!ptr && !new_size)
        return (NULL);
    
    new_ptr = malloc(new_size);
    if (!new_ptr)
        return (NULL);

    if (old_size > 0 && old_size <= new_size)
    {
        src = (char*)ptr;
        dst = (char*)new_ptr;
        i = 0;
        while (i < old_size)
        {
            dst[i] = src[i];
            i++;
        }
    }
    free(ptr);
    return (new_ptr);
}