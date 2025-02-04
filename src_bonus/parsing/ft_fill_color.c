/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:30:57 by ayarab            #+#    #+#             */
/*   Updated: 2025/02/04 15:01:30 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d_bonus.h"


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
	while (cube3d->F[j] && cube3d->F[j] <= 32)
		j++;
	cube3d->F_R = ft_add_color(&start, &j, &comma, cube3d->F);
	if (comma == 1)
		cube3d->F_G = ft_add_color(&start, &j, &comma, cube3d->F);
	if (comma == 2)
		cube3d->F_B = ft_add_last_color(&start, &j, cube3d->F);
	if (cube3d->F_R < 0 || cube3d->F_G < 0 || cube3d->F_B < 0)
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
	while (cube3d->C[j] && cube3d->C[j] <= 32)
		j++;
	cube3d->C_R = ft_add_color(&start, &j, &comma, cube3d->C);
	if (comma == 1)
		cube3d->C_G = ft_add_color(&start, &j, &comma, cube3d->C);
	if (comma == 2)
		cube3d->C_B = ft_add_last_color(&start, &j, cube3d->C);
	if (comma != 2)
		return (EXIT_FAILURE);
	if (cube3d->C_R < 0 || cube3d->C_G < 0 || cube3d->C_B < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_fill_color(t_cub3d *cube3d)
{
	if (ft_fill_floor_color(cube3d) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	printf("la valeur de R_F = {%d}\nla valeur de G_F = {%d}\nla valeur de B_F = {%d}\n",
		cube3d->F_R, cube3d->F_G, cube3d->F_B);
	if (ft_fill_cloud_color(cube3d) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	printf("la valeur de R_C = {%d}\nla valeur de G_C = {%d}\nla valeur de B_C = {%d}\n",
		cube3d->C_R, cube3d->C_G, cube3d->C_B);
	return (EXIT_SUCCESS);
}
