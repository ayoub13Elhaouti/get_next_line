/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoel-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:05:55 by ayoel-ha          #+#    #+#             */
/*   Updated: 2023/12/21 12:18:58 by ayoel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	str = malloc((ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!str)
		return (NULL);
	while (str1 && str1[i])
	{
		str[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2 && str2[j])
	{
		str[i + j] = str2[j];
		j++;
	}
	str[i + j] = '\0';
	free(str1);
	return (str);
}

char	*ft_line(char *str)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!str[0])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		line = (char *)malloc(sizeof(char) * (i + 2));
	else if (!str[i])
		line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_next(char *str)
{
	char	*next;
	size_t	i;
	size_t	j;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	if (!str || !str[i])
	{
		free(str);
		return (NULL);
	}
	next = (char *)malloc(sizeof(char) * (ft_strlen(str) - i) + 1);
	if (!next)
	{
		free(str);
		return (NULL);
	}
	j = 0;
	while (str[++i])
		next[j++] = str[i];
	next[j] = '\0';
	free(str);
	return (next);
}
