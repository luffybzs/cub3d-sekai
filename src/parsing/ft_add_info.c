/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:52:32 by ayarab            #+#    #+#             */
/*   Updated: 2025/02/24 12:35:32 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"

int	ft_add_we(char *str, t_cub3d *cube3d, int i)
{
	if (!ft_strncmp(str + i, "WE", 2))
	{
		if (cube3d->we)
			return (-1);
		cube3d->we = ft_add_just_info(str, i + 2);
		if (!cube3d->we)
			return (-1);
		return (1);
	}
	return (EXIT_SUCCESS);
}

int	ft_add_so(char *str, t_cub3d *cube3d, int i)
{
	if (!ft_strncmp(str + i, "SO", 2))
	{
		if (cube3d->so)
			return (-1);
		cube3d->so = ft_add_just_info(str, i + 2);
		if (!cube3d->so)
			return (-1);
		return (1);
	}
	return (EXIT_SUCCESS);
}

int	ft_add_no(char *str, t_cub3d *cube3d, int i)
{
	if (!ft_strncmp(str + i, "NO", 2))
	{
		if (cube3d->no)
			return (-1);
		cube3d->no = ft_add_just_info(str, i + 2);
		if (!cube3d->no)
			return (-1);
		return (1);
	}
	return (0);
}

int	ft_add_ea(char *str, t_cub3d *cube3d, int i)
{
	if (!ft_strncmp(str + i, "EA", 2))
	{
		if (cube3d->ea)
			return (-1);
		cube3d->ea = ft_add_just_info(str, i + 2);
		if (!cube3d->ea)
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
			tmp = ft_strtrim(str + start, "\n");
			if (!tmp)
				return (NULL);
			return (tmp);
		}
		i++;
	}
	return (NULL);
}
