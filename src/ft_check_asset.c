/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_asset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:44:11 by ayarab            #+#    #+#             */
/*   Updated: 2025/01/16 23:14:05 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"

int	ft_skip_space(char *str, int *i)
{
	if (!str)
		return (EXIT_FAILURE);
    while (str[*i] && str[*i] <= 32)
        (*i)++;
    if (str[*i])
        return (EXIT_FAILURE);
    return(EXIT_SUCCESS);
}


int ft_check_asset(t_cub3d *cube3d)
{
    (void)cube3d;
    return (EXIT_SUCCESS);
}
