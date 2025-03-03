/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:58:05 by ayarab            #+#    #+#             */
/*   Updated: 2025/02/28 17:26:26 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"


int	ft_add_f(char *str, t_cub3d *cube3d)
{
	if (!ft_strncmp(str, "F", 1))
	{
		if (cube3d->f)
			return (-1);
		cube3d->f = ft_strdup(str + 1);
		if (!cube3d->f)
			return (-1);
		return (1);
	}
	return (EXIT_SUCCESS);
}

int	ft_add_c(char *str, t_cub3d *cube3d)
{
	if (!ft_strncmp(str, "C", 1))
	{
		if (cube3d->c)
			return (-1);
		cube3d->c = ft_strdup(str + 1);
		if (!cube3d->c)
			return (-1);
		return (1);
	}
	return (EXIT_SUCCESS);
}

int	ft_cmp_xpm(char *str, int i, char *cmp)
{
	int	j;

	j = 0;
	while (str[i] && cmp[j])
	{
		if (str[i] != cmp[j])
			return (str[i] - cmp[j]);
		i++;
		j++;
	}
	return (str[i] - cmp[j]);
}

int	ft_all_one(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] <= 32)
		i++;
	if (str[i] == '1')
		return (1);
	return (0);
}


