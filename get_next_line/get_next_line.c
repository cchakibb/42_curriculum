/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:49:36 by chbachir          #+#    #+#             */
/*   Updated: 2023/07/26 18:06:22 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next(char *stash)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == 0)
		return (NULL);
	i++;
	while (stash[i + j])
		j++;
	str = malloc (sizeof(char) * (j + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (stash[i + j])
	{
		str[j] = stash[i + j];
		j++;
	}
	str[j] = 0;
	return (str);
}

char	*ft_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (stash[i] == 0)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc (sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*ft_read(int fd, char *stash)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read != 0)
	{
		bytes_read = read (fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buffer);
			buffer = NULL;
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free (buffer);
	buffer = NULL;
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*next;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	stash = ft_read(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = ft_line(stash);
	next = stash;
	stash = ft_next(stash);
	free (next);
	next = NULL;
	return (line);
}
