/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_asset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:44:11 by ayarab            #+#    #+#             */
/*   Updated: 2025/02/05 19:43:17 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d_bonus.h"

int	ft_atoi_rgb(char *str, int start, int end)
{
	int	res;

	res = 0;
	while (start < end)
	{
		res *= 10;
		res += str[start] - 48;
		if (res > 255)
			return (-1);
		start++;
	}
	return (res);
}

void	ft_fail_free(t_cub3d *cube3d)
{
	if (cube3d->EA)
		free(cube3d->EA);
	if (cube3d->NO)
		free(cube3d->NO);
	if (cube3d->WE)
		free(cube3d->WE);
	if (cube3d->SO)
		free(cube3d->SO);
	if (cube3d->F)
		free(cube3d->F);
	if (cube3d->C)
		free(cube3d->C);
	if (cube3d->all_maps)
		ft_free_2d(cube3d->all_maps);
	return ;
}