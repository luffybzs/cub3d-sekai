/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:01:34 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/01/12 17:25:24 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void put_pixel(t_img *img, int x, int y, int color)
{
    char *dst;

    if (x >= 0 && x < img->width && y >= 0 && y < img->height)
    {
        dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
        *(unsigned int*)dst = color;
    }
}

int get_pixel(t_img *img, int x, int y)
{
    char *src;

    if (x >= 0 && x < img->width && y >= 0 && y < img->height)
    {
        src = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
        return (*(unsigned int*)src);
    }
    return (0);
}

// Pour créer une couleur RGB
int create_rgb(int r, int g, int b)
{
    return (r << 16 | g << 8 | b);
}