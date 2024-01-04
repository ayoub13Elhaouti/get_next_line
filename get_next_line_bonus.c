/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoel-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:54:38 by ayoel-ha          #+#    #+#             */
/*   Updated: 2024/01/04 18:36:28 by ayoel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(char *str, int fd)
{
	char	*buffer;
	int		bytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(str, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(str);
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[FOPEN_MAX];
	char		*line;

	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = ft_read(str[fd], fd);
	if (!str[fd])
		return (NULL);
	line = ft_line(str[fd]);
	str[fd] = ft_next(str[fd]);
	return (line);
}
/*
int main(void)
{
	char	*str[FOPEN_MAX];
	int	fd1 = open("file1", O_RDWR | O_CREAT, 0777);
	int     fd2 = open("file2", O_RDWR | O_CREAT, 0777);
	int     fd3 = open("file3", O_RDWR | O_CREAT, 0777);

	if (fd1 == -1 || fd2 == -1 || fd3 == -1)
		printf("There's An Error");
	for (int i = 0; i < FOPEN_MAX; i++)
		str[i] = NULL;
	while ((str[fd1] = get_next_line(fd1)) != NULL || 
	(str[fd2] = get_next_line(fd2)) != NULL || 
	(str[fd3] = get_next_line(fd3))!= NULL)
	{
		printf("The Strings In FD1 Are: %s\n", str[fd1]);
		free(str[fd1]);
		printf("The Strings In FD2 Are: %s\n", str[fd2]);
                free(str[fd2]);
		printf("The Strings In FD3 Are: %s\n", str[fd3]);
                free(str[fd3]);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/
