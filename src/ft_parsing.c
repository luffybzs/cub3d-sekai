/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:28:56 by ayarab            #+#    #+#             */
/*   Updated: 2025/01/20 02:29:27 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"

int	ft_check_av1(t_cub3d *cube3d)
{
	int	point;

	point = ft_strlen(cube3d->av1) - 4;
	if (ft_strlen(cube3d->av1) < 4)
		return (EXIT_FAILURE);
	if (ft_strcmp(&cube3d->av1[point], ".cub") != 0)
		return (EXIT_FAILURE);
	if (cube3d->av1[point - 1] == '/')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
int ft_fill_info(t_cub3d *cube3d, char *str)
{
	int i;
	int res;

	i = 0;
	while (str[i] && str[i] <= 32)
		i++;
	if (str)
	{
		res = ft_add_cardinal_points(str, cube3d , i);
		if (res == -1)
			return (-1);
		return(res);
	}
	return (0);
}

int ft_cmp_xpm(char *str, int i, char *cmp)
{
	int j = 0;
	while (str[i] && cmp[j])
	{
		if (str[i] != cmp[j])
			return (str[i] - cmp[j]);
		i++;
		j++;
	}
	//if (str[i])
	//	return (-1);
	return (str[i] - cmp[j]);
}



char *ft_add_just_info(char *str, int i)
{
	int start;
	char *tmp;
	while (str[i] && str[i] <= 32)
		i++;
	start = i;
	while (str[i])
	{
		if (ft_cmp_xpm(str, i, ".xpm\n") == 0)
		{
			tmp = ft_substr(str, start, i + 1) ;
			if (!tmp)
				return (NULL);
			return (tmp);
		}
		i++;
	}
	return (NULL);	
}
int	ft_search_info(char *av1, t_cub3d *cube3d)
{
	int		fd;
	char	*line;
	int count;

	fd = open(av1, O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count += ft_fill_info(cube3d, line);
		if (count == - 1 || count > 6)
			return (free(line),close(fd),EXIT_FAILURE);
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), EXIT_SUCCESS);
}
int ft_all_one(char *str)
{
	int i = 0;
	while (str[i] && str[i] <= 32)
		i++;
	if (str[i] != '1')
		return (-1);
	return (0);
	
}


int	ft_search_maps(char *av1, t_cub3d *cube3d)
{
	int		fd;
	char	*line;
	char *res;
	int flag = 0;
	fd = open(av1, O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_all_one(line) && flag == 0)
			flag = 1;
		if (flag == 1)
		{
			res = ft_strjoin_free(res, line);
			if (!res)
				return (free(line), close(fd), EXIT_FAILURE);
		}
		free(line);
		line = get_next_line(fd);
	}
	cube3d->all_maps = ft_split(res, '\n');
	if (!cube3d->all_maps)
		return (close(fd), free(res),EXIT_FAILURE); 
	return (close(fd),free(res), EXIT_SUCCESS);
}

int ft_add_WE(char *str, t_cub3d *cube3d, int i)
{
	if (!ft_strncmp(str + i, "WE",2) && !cube3d->WE)
	{
		if (cube3d->WE)
			return (-1);
		cube3d->WE = ft_add_just_info(str, i + 2);
		if (!cube3d->WE)
			return (-1);		
	}
	return (EXIT_SUCCESS);
}

int ft_add_SO(char *str, t_cub3d *cube3d , int i)
{
	if (!ft_strncmp(str + i, "SO",2))
	{
		if (cube3d->SO)
			return (-1);
		cube3d->SO = ft_add_just_info(str, i + 2);
		if (!cube3d->SO)
			return (-1);		
	}
	return (EXIT_SUCCESS);
	
}

int ft_add_NO(char *str, t_cub3d *cube3d , int i)
{
	if (!ft_strncmp(str + i, "NO", 2))
	{
		if (cube3d->NO)
			return (-1);
		cube3d->NO = ft_add_just_info(str, i + 2);
		if (!cube3d->NO)
			return (-1);		
	}
	return (EXIT_SUCCESS);
	
}
int ft_add_EA(char *str, t_cub3d *cube3d, int i)
{
	if (!ft_strncmp(str + i, "EA",2) && !cube3d->EA)
	{
		if (cube3d->EA)
			return (-1);
		cube3d->EA = ft_add_just_info(str, i + 2);
		if (!cube3d->EA)
			return (-1);
		return(1);		
	}
	return (EXIT_SUCCESS);
}
int ft_add_F(char *str, t_cub3d *cube3d)
{
	if (ft_strnstr(str, "F", 1) != NULL)
		{
			if (cube3d->F)
				return (-1);
			cube3d->F = ft_strdup(str + 1);
			if (!cube3d->F)
				return (-1);
			return (1);
		}
		return (EXIT_SUCCESS);
}
int ft_add_C(char *str, t_cub3d *cube3d)
{
	if (ft_strnstr(str, "C", 1) != NULL)
		{
			if (cube3d->C)
				return (-1);
			cube3d->C = ft_strdup(str + 1);
			if (!cube3d->C)
				return (-1);
			return (1);
		}
		return (EXIT_SUCCESS);
}


int ft_add_cardinal_points(char *str,t_cub3d *cube3d, int i)
{

	if (ft_add_WE(str,cube3d, i) == -1 || ft_add_SO(str,cube3d , i) == -1)
		return (-1);
	if (ft_add_NO(str,cube3d , i) == -1 || ft_add_EA(str,cube3d , i) == -1)
		return (-1);
	if (ft_add_F(str, cube3d) == -1 || ft_add_C(str, cube3d) == -1)
		return (-1);
	if (ft_add_WE(str,cube3d, i) == 1 || ft_add_SO(str,cube3d , i) == 1)
		return (1);
	if (ft_add_NO(str,cube3d , i) == 1 || ft_add_EA(str,cube3d , i) == 1)
		return (1);
	if (ft_add_F(str, cube3d) == -1 || ft_add_C(str, cube3d) == -1)
		return (1);
	return (0);
}

int	ft_fill_data(int ac, char **av, t_cub3d *cube3d)
{
	cube3d->ac = ac;
	cube3d->av1 = av[1];
	if (ft_check_av1(cube3d) == EXIT_FAILURE)
		return (ft_putstr_fd("Error\n", 2), EXIT_FAILURE);
	if (ft_search_info(cube3d->av1, cube3d) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_search_maps(cube3d->av1, cube3d) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_fill_color(cube3d) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	//if (ft_check_asset(cube3d) == EXIT_FAILURE)
	//	return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}