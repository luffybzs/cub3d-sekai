/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:28:56 by ayarab            #+#    #+#             */
/*   Updated: 2025/02/06 19:17:54 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d_bonus.h"

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

int	ft_fill_info(t_cub3d *cube3d, char *str)
{
	int	i;
	int	res;

	i = 0;
	while (str[i] && str[i] <= 32)
		i++;
	if (str)
	{
		res = ft_add_cardinal_points(str, cube3d, i);
		if (res == -1)
			return (-1);
		return (res);
	}
	return (0);
}

int	ft_search_info(char *av1, t_cub3d *cube3d)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(av1, O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count += ft_fill_info(cube3d, line);
		if (count == -1 || count > 6)
			return (free(line), close(fd), EXIT_FAILURE);
		free(line);
		line = get_next_line(fd);
	}
	if (!cube3d->WE || !cube3d->SO || !cube3d->EA || !cube3d->NO || !cube3d->F || !cube3d->C)
		return (close(fd) , EXIT_FAILURE);
	return (close(fd), EXIT_SUCCESS);
}

int ft_add_door(char *str, t_cub3d *cube3d, int i)
{
	if (!ft_strncmp(str, "D", 1))
	{
		if (cube3d->door.path)
			return (-1);
		cube3d->door.path = ft_add_just_info(str ,i + 1);
		if (!cube3d->door.path)
			return (-1);
		return (1);
	}
	return (EXIT_SUCCESS);
}



int	ft_add_cardinal_points(char *str, t_cub3d *cube3d, int i)
{
	if (ft_add_NO(str, cube3d, i) == -1 || ft_add_EA(str, cube3d, i) == -1)
		return (-1);
	if (ft_add_WE(str, cube3d, i) == -1 || ft_add_SO(str, cube3d, i) == -1)
		return (-1);
	if (ft_add_F(str, cube3d) == -1 || ft_add_C(str, cube3d) == -1)
		return (-1);
	if (ft_add_WE(str, cube3d, i) == 1 || ft_add_SO(str, cube3d, i) == 1)
		return (1);
	if (ft_add_NO(str, cube3d, i) == 1 || ft_add_EA(str, cube3d, i) == 1)
		return (1);
	if (ft_add_F(str, cube3d) == 1 || ft_add_C(str, cube3d) == 1)
		return (1);
	if (ft_add_door(str, cube3d, i) == 1)
		return (1);
	if (ft_add_door(str, cube3d, i) == -1)
		return (-1);
	printf("WE = {%s}\nSO = {%s}\nEA = {%s}\nNO = {%s}\nF = {%s}\nC = {%s}\nDoor = {%s}\n",cube3d->WE,cube3d->SO,cube3d->EA,cube3d->NO,cube3d->F,cube3d->C, cube3d->door.path);
	
	return (0);
}

int ft_check_line(char **tab)
{
	int i;
	int len;
	
	len = (ft_strlen_2d(tab) - 1);
	i = 0;
	while (tab[0][i] && tab[0][i] <= 32)
		i++;
	while (tab[0][i])
	{
		if (tab[0][i] != '1' && tab[0][i] != ' ')
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (tab[len][i] && tab[len][i] <= 32)
		i++;
	while (tab[len][i])
	{
		if (tab[len][i] != '1' && tab[len][i] != ' ')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
int ft_ft(t_cub3d *cube3d, int i, int j)
{
	if (cube3d->all_maps[j][i] == 'W')
		return (1);
	if (cube3d->all_maps[j][i] == 'S')
		return (1);
	if (cube3d->all_maps[j][i] == 'E')
		return (1);
	if (cube3d->all_maps[j][i] == 'N')
		return (1);
	if (cube3d->all_maps[j][i] == '0')
		return (1);
	if (cube3d->all_maps[j][i] == '1')
		return (1);
	if (cube3d->all_maps[j][i] == 'D')
		return (1);
	return (0);
}

int ft_is_good(t_cub3d *cube3d, int j, int i)
{
	if (!ft_ft(cube3d,i,j - 1))
		return (EXIT_FAILURE);
	if (!ft_ft(cube3d, i , j + 1))
		return (EXIT_FAILURE);
	if (!ft_ft(cube3d,i + 1, j))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
int ft_skip(char **tab, int j)
{
	int i = 0;

	while (tab[j][i] && tab[j][i] <= 32)
		i++;
	if (tab[j][i] == '1')
		return (0);
	return (-1);
}

int ft_player(char c);//ayoub tentative d ajout d acceptation des portes;
int ft_maps_is_good(t_cub3d *cube3d)
{
	int i;
	int j;

	i = 0;
	j = 1;
	if (ft_check_line(cube3d->all_maps) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (cube3d->all_maps[j])
	{
		if (ft_skip(cube3d->all_maps, j) == -1)
			return (EXIT_FAILURE);
		while (cube3d->all_maps[j][i])
		{
			if (cube3d->all_maps[j][i] == '0' || ft_player(cube3d->all_maps[j][i]) == 0 ||  cube3d->all_maps[j][i] == 'D')
			{
				if (ft_is_good(cube3d,j, i) == EXIT_FAILURE)
					return (EXIT_FAILURE);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (EXIT_SUCCESS);
}
int ft_check_char(char c)
{
	if (c == 'N')
		return (EXIT_SUCCESS);
	if (c == 'S')
		return (EXIT_SUCCESS);
	if (c == 'E')
		return (EXIT_SUCCESS);
	if (c == 'W')
		return (EXIT_SUCCESS);
	if (c == '1')
		return (EXIT_SUCCESS);
	if (c == '0')
		return (EXIT_SUCCESS);
	if (c == 'D')
		return (EXIT_SUCCESS);
	if (c <= 32)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}


int ft_is_all_good_char(t_cub3d *cube3d)
{
	int i;
	int j = 0;

	while (cube3d->all_maps[j])
	{
		i = 0;
		while (cube3d->all_maps[j][i])
		{
			if (ft_check_char(cube3d->all_maps[j][i]) == EXIT_FAILURE)
				return (EXIT_FAILURE);
			i++;
		}
		j++;
	}
	return (EXIT_SUCCESS);
}
int ft_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int ft_check_player(t_cub3d *cube3d)
{
	int i = 0;
	int j = 0;
	bool player = false;

	while (cube3d->all_maps[j])
	{
		i = 0;
		while (cube3d->all_maps[j][i])
		{
			if (ft_player(cube3d->all_maps[j][i]) == EXIT_SUCCESS)
			{
				if (player == true)
					return (EXIT_FAILURE);
				cube3d->direction = cube3d->all_maps[j][i];
				cube3d->x_spwan_p = i;
				cube3d->y_spwan_p = j;
				player = true;
			}
			i++;
		}
		j++;
	}
	if (player == false)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
} 


int	ft_fill_data(int ac, char **av, t_cub3d *cube3d)
{
	cube3d->ac = ac;
	cube3d->av1 = av[1];
	
	if (ft_check_av1(cube3d) == EXIT_FAILURE)
		return (ft_putstr_fd("Error\n", 2), EXIT_FAILURE);
	if (ft_search_info(cube3d->av1, cube3d) == EXIT_FAILURE)
		return (ft_putendl_fd(ERROR_FOR_INFO, 2),EXIT_FAILURE);
	if (ft_search_maps(cube3d->av1, cube3d) == EXIT_FAILURE)
		return (ft_putendl_fd("Error\nMap Not Found" ,2) ,EXIT_FAILURE);
	if (ft_fill_color(cube3d) == EXIT_FAILURE)
		return (ft_putendl_fd("Error\nRGB Is Not Good",2) ,EXIT_FAILURE);
	if (ft_is_all_good_char(cube3d) == EXIT_FAILURE)
		return (ft_putendl_fd("Error\nMap Invalid Char", 2) ,EXIT_FAILURE);
	if (ft_maps_is_good(cube3d) == EXIT_FAILURE)
		return (ft_putendl_fd("Error\nMap Is Not Close",2) , EXIT_FAILURE);
	if (ft_check_player(cube3d) == EXIT_FAILURE)
		return (ft_putendl_fd("Error\nNot Or Too Many Player", 2), EXIT_FAILURE);
	// test_print(cube3d->all_maps);
	// ft_check_door(cub3d);//gerer la creation d un tableau avec les infos sur les differentes portes

	return (EXIT_SUCCESS);
}

// int ft_check_door(t_cub3d *cube3d)
// {
// 	int i = 0;
// 	int j = 0;
// 	bool door = false;

// 	while (cube3d->all_maps[j])
// 	{
// 		i = 0;
// 		while (cube3d->all_maps[j][i])
// 		{
// 			if ((cube3d->all_maps[j][i]) == 'D')
// 			{
				
// 				cube3d->x_door = i;
// 				cube3d->y_door = j;
// 			}
// 			i++;
// 		}
// 		j++;
// 	}
// 	if (player == false)
// 		return (EXIT_FAILURE);
// 	return (EXIT_SUCCESS);
// } 