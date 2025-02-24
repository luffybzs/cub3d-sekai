/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:30:57 by ayarab            #+#    #+#             */
/*   Updated: 2025/02/24 12:38:12 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"

int	ft_add_last_color(int *start, int *j, char *str)
{
	int	tmp;

	if (str[*j] && !ft_isdigit(str[*j]))
		return (-1);
	(*start) = (*j);
	while (str[*j] && ft_isdigit(str[*j]))
		(*j)++;
	tmp = ft_atoi_rgb(str, *start, *j);
	if (str[*j] != '\n')
		return (-1);
	return (tmp);
}

int	ft_add_color(int *start, int *j, int *comma, char *str)
{
	int	tmp;

	if (str[*j] && !ft_isdigit(str[*j]))
		return (-1);
	(*start) = (*j);
	while (str[*j] && ft_isdigit(str[*j]))
		(*j)++;
	tmp = ft_atoi_rgb(str, *start, *j);
	if (str[*j] != ',' || !ft_isdigit(str[*j + 1]))
		return (-1);
	(*j)++;
	(*start) = (*j);
	(*comma)++;
	return (tmp);
}

int	ft_fill_floor_color(t_cub3d *cube3d)
{
	int	j;
	int	comma;
	int	start;

	start = 0;
	j = 0;
	comma = 0;
	while (cube3d->f[j] && cube3d->f[j] <= 32)
		j++;
	cube3d->f_r = ft_add_color(&start, &j, &comma, cube3d->f);
	if (comma == 1)
		cube3d->f_g = ft_add_color(&start, &j, &comma, cube3d->f);
	if (comma == 2)
		cube3d->f_b = ft_add_last_color(&start, &j, cube3d->f);
	if (cube3d->f_r < 0 || cube3d->f_g < 0 || cube3d->f_b < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_fill_cloud_color(t_cub3d *cube3d)
{
	int	j;
	int	comma;
	int	start;

	start = 0;
	j = 0;
	comma = 0;
	while (cube3d->c[j] && cube3d->c[j] <= 32)
		j++;
	cube3d->c_r = ft_add_color(&start, &j, &comma, cube3d->c);
	if (comma == 1)
		cube3d->c_g = ft_add_color(&start, &j, &comma, cube3d->c);
	if (comma == 2)
		cube3d->c_b = ft_add_last_color(&start, &j, cube3d->c);
	if (comma != 2)
		return (EXIT_FAILURE);
	if (cube3d->c_r < 0 || cube3d->c_g < 0 || cube3d->c_b < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_fill_color(t_cub3d *cube3d)
{
	if (ft_fill_floor_color(cube3d) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_fill_cloud_color(cube3d) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
