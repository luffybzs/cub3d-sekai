/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:41:18 by ayarab            #+#    #+#             */
/*   Updated: 2025/03/03 16:55:53 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif
# include "../libft.h"
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strdup_gnl(char *stock, char c);
void	ft_clean_buf(char *buff);
int		ft_check_gnl(char *stock, char x);
char	*get_next_line(int fd);
void	copy_after_newline(char *all, char *buff);
char	*before_newline(char *all);
char	ft_get_line(char *line, char *buff, int lu, int fd);

#endif