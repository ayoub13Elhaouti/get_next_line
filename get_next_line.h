/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoel-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:26:08 by ayoel-ha          #+#    #+#             */
/*   Updated: 2024/01/04 18:04:30 by ayoel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0 
# endif

char	*get_next_line(int fd);
char	*ft_read(char *str, int fd);
char	*ft_next(char *str);
char	*ft_line(char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strdup(char *str);
int		ft_strchr(char *str, int c);
size_t	ft_strlen(char *str);

#endif
