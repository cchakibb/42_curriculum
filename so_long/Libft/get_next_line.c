/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:54:07 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/06 14:54:10 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;

	line = NULL;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || (BUFFER_SIZE <= 0) || read (fd, 0, 0))
	{
		free(buffer);
		free(stash);
		buffer = NULL;
		stash = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	stash = fill_stash_buffer(fd, stash, buffer);
	if (*stash == 0)
	{
		free (stash);
		return (stash = 0);
	}
	line = extract_line_stash(line, stash);
	stash = extract_new_stash(stash);
	return (line);
}

char	*fill_stash_buffer(int fd, char *stash, char *buffer)
{
	ssize_t	nbytes;
	char	*temp;

	nbytes = 1;
	if (!stash)
		stash = ft_strdup("");
	while (nbytes > 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == -1)
			break ;
		buffer[nbytes] = 0;
		temp = stash ;
		stash = ft_strjoin(temp, buffer);
		free (temp);
		temp = NULL;
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free (buffer);
	return (stash);
}

char	*extract_line_stash(char *line, char *stash)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while ((stash[len] != '\n' && stash[len] != '\0'))
		len ++;
	if (stash[len] == '\n')
		len ++;
	line = (char *)malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = stash[i];
		i ++;
	}
	line[i] = 0;
	return (line);
}

char	*extract_new_stash(char *stash)
{
	char	*new_stash;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (stash[len] != '\n' && stash[len] != '\0')
		len ++;
	if (stash[len] == '\n')
	{
		len ++;
	}
	new_stash = (char *)malloc((ft_strlen(stash)- len + 1) * sizeof(char));
	if (!new_stash)
		return (NULL);
	while (stash[len + i])
	{
		new_stash[i] = stash[len + i];
		i ++;
	}
	free (stash);
	new_stash[i] = 0;
	return (new_stash);
}
