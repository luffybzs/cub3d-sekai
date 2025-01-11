/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 22:42:46 by ayarab            #+#    #+#             */
/*   Updated: 2025/01/11 04:32:11 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_tab_and_return(char **res, int i)
{
	while (--i >= 0)
		free(res[i]);
	free(res);
}

char	**ft_strjoin_2d(char **tab, char *str)
{
	char	**res;
	int		i;
	int		len;

	if (!tab || !str)
		return (NULL);
	len = 0;
	while (tab[len])
		len++;
	res = malloc(sizeof(char *) * (len + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = ft_strdup(tab[i]);
		if (!res[i])
			return (free_tab_and_return(res, i), NULL);
		i++;
	}
	res[len] = ft_strdup(str);
	if (!res[len])
		return (free_tab_and_return(res, i), NULL);
	res[len + 1] = NULL;
	return (res);
}

void	ft_free_2d(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
