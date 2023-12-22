/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:49:36 by chbachir          #+#    #+#             */
/*   Updated: 2023/07/26 17:00:34 by chbachir         ###   ########.fr       */
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
	while (stash[i] != 0 && stash[i] != '\n')
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

char	*get_next_line(int fd) 	//This is the main function for reading the next line from the given file descriptor (fd). 
	//It returns a dynamically allocated string, representing the line read.
{
	static char	*stash; //A static variable (stash) is used to keep track of the remaining content from the previous reads.
	char		*line; //it will be used to store the current line being read.
	char		*next; //it will be used to store the content of stash that comes after the current line.

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	stash = ft_read(fd, stash); //Calls the ft_read function to read data from the file descriptor (fd) and appends 
				   //it to the existing stash. The new stash is then assigned to the static variable.
	if (stash == NULL)
		return (NULL);
	line = ft_line(stash); //Calls the ft_line function to extract the current line from stash and assigns it to line.
	next = stash; //assigns the current stash to the next variable.
	stash = ft_next(stash); //updates stash by calling the ft_next function, which removes the current line from stash.
	free (next); //frees the memory occupied by the content of stash before the current line (stored in next).
	next = NULL;
	return (line); //the current line that was read from the file.
}
