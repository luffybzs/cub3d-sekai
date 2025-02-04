/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:52:32 by ayarab            #+#    #+#             */
/*   Updated: 2025/02/04 15:01:16 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d_bonus.h"

int	ft_add_WE(char *str, t_cub3d *cube3d, int i)
{
	if (!ft_strncmp(str + i, "WE", 2))
	{
		if (cube3d->WE)
			return (-1);
		cube3d->WE = ft_add_just_info(str, i + 2);
		if (!cube3d->WE)
			return (-1);
		return (1);
	}
	return (EXIT_SUCCESS);
}

int	ft_add_SO(char *str, t_cub3d *cube3d, int i)
{
	if (!ft_strncmp(str + i, "SO", 2))
	{
		if (cube3d->SO)
			return (-1);
		cube3d->SO = ft_add_just_info(str, i + 2);
		if (!cube3d->SO)
			return (-1);
		return (1);
	}
	return (EXIT_SUCCESS);
}

int	ft_add_NO(char *str, t_cub3d *cube3d, int i)
{
	if (!ft_strncmp(str + i, "NO", 2))
	{
		if (cube3d->NO)
			return (-1);
		cube3d->NO = ft_add_just_info(str, i + 2);
		if (!cube3d->NO)
			return (-1);
		return (1);
	}
	return (0);
}
int	ft_add_EA(char *str, t_cub3d *cube3d, int i)
{
	if (!ft_strncmp(str + i, "EA", 2))
	{
		if (cube3d->EA)
			return (-1);
		cube3d->EA = ft_add_just_info(str, i + 2);
		if (!cube3d->EA)
			return (-1);
		return (1);
	}
	return (0);
}
char	*ft_add_just_info(char *str, int i)
{
	int		start;
	char	*tmp;

	while (str[i] && str[i] <= 32)
		i++;
	start = i;
	while (str[i])
	{
		if (ft_cmp_xpm(str, i, ".xpm\n") == 0)
		{
			tmp = ft_substr(str, start, i + 1);
			if (!tmp)
				return (NULL);
			return (tmp);
		}
		i++;
	}
	return (NULL);
}

