/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:47:26 by stobin            #+#    #+#             */
/*   Updated: 2024/06/15 22:53:59 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	count_line(t_glist *chunk, char **line)
{
	int	i;
	int	len;

	len = 0;
	while (chunk)
	{
		i = 0;
		while (chunk->txt[i])
		{
			if ('\n' == chunk->txt[i])
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		chunk = chunk->nxt;
	}
	*line = malloc((len + 1) * sizeof(char));
	if (!*line)
	{
		free(*line);
		*line = NULL;
	}
}

t_glist	*clean_tail(t_glist **chunk)
{
	ssize_t	i;
	t_glist	*last;
	t_glist	*tail;

	tail = (t_glist *)malloc(sizeof(t_glist));
	if (!chunk || !tail)
	{
		free_drop(tail, chunk);
		return (NULL);
	}
	tail->nxt = NULL;
	last = ft_lstlastg(*chunk);
	i = 0;
	while (last->txt[i] && last->txt[i] != '\n')
		i++;
	if ('\n' == last->txt[i])
		i++;
	tail->txt = trim_tail(last, i);
	if (!tail->txt)
	{
		free_tail(tail);
		return (NULL);
	}
	drop_chunks(*chunk);
	return (tail);
}

char	*trim_tail(t_glist *last, ssize_t i)
{
	ssize_t	j;
	ssize_t	len;
	char	*txt;

	len = 0;
	while (last->txt[len])
		len++;
	txt = (char *)malloc((len - i + 1));
	if (!txt)
	{
		txt = NULL;
		return (NULL);
	}
	j = 0;
	while (last->txt[i])
		txt[j++] = last->txt[i++];
	txt[j] = '\0';
	return (txt);
}

void	drop_chunks(t_glist *chunk)
{
	t_glist	*temp;

	while (chunk)
	{
		temp = chunk;
		chunk = chunk->nxt;
		free(temp->txt);
		free(temp);
	}
	chunk = NULL;
}

t_glist	*ft_lstlastg(t_glist *chunk)
{
	if (!chunk)
		return (NULL);
	while (chunk->nxt != NULL)
		chunk = chunk->nxt;
	return (chunk);
}
