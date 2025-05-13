/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:14:28 by stobin            #+#    #+#             */
/*   Updated: 2024/06/15 17:14:12 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	build_line(t_glist *chunk, char **line)
{
	int	i;
	int	j;

	if (chunk)
	{
		count_line(chunk, line);
		if (!*line)
			return ;
		j = 0;
		while (chunk)
		{
			i = 0;
			while (chunk->txt[i])
			{
				if ('\n' == chunk->txt[i])
				{
					(*line)[j++] = chunk->txt[i];
					break ;
				}
				(*line)[j++] = chunk->txt[i++];
			}
			chunk = chunk->nxt;
		}
		(*line)[j] = '\0';
	}
}

t_bool	line_broke(t_glist *chunk)
{
	ssize_t	i;

	i = 0;
	if (chunk)
	{
		chunk = ft_lstlastg(chunk);
		while (chunk->txt[i])
		{
			if ('\n' == chunk->txt[i])
				return (TRUE);
			i++;
		}
	}
	return (FALSE);
}

void	grab_chunk(t_glist **chunk, char *buf, int bread)
{
	size_t	i;
	t_glist	*last;
	t_glist	*extra;

	extra = (t_glist *)malloc(sizeof(t_glist));
	if (!extra)
		return ;
	extra->txt = (char *)malloc((bread + 1) * sizeof(char));
	if (!extra->txt)
		return ;
	i = 0;
	extra->nxt = NULL;
	while (buf[i] && (int)i < bread)
	{
		extra->txt[i] = buf[i];
		i++;
	}
	extra->txt[i] = '\0';
	if (!*chunk)
		*chunk = extra;
	else
	{
		last = ft_lstlastg(*chunk);
		last->nxt = extra;
	}
}

void	load_buf(int fd, t_glist **chunk)
{
	char	*buf;
	int		bread;

	bread = 1;
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buf)
	{
		while (bread && FALSE == line_broke(*chunk))
		{
			bread = read(fd, buf, BUFFER_SIZE);
			if (-1 == bread || (0 == bread && NULL == *chunk))
			{
				free(buf);
				buf = NULL;
				if (-1 == bread)
					drop_chunks(*chunk);
				*chunk = NULL;
				return ;
			}
			buf[bread] = '\0';
			grab_chunk(chunk, buf, bread);
		}
		free(buf);
		buf = NULL;
	}
}

char	*get_next_line(int fd)
{
	static t_glist	*chunk = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	load_buf(fd, &chunk);
	if (!chunk)
		return (NULL);
	build_line(chunk, &line);
	chunk = clean_tail(&chunk);
	if (!chunk)
		return (NULL);
	if ('\0' == *line)
	{
		drop_chunks(chunk);
		chunk = NULL;
		free(line);
		line = NULL;
		return (NULL);
	}
	return (line);
}
