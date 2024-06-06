/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:53:56 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/06 14:53:57 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		i ++;
	}
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*strdup;
	int		i;

	i = 0;
	strdup = (char *)malloc((ft_strlen(str)+1) * sizeof(char));
	if (!strdup)
		return (NULL);
	while (str[i])
	{
		strdup[i] = str[i];
		i ++;
	}
	strdup[i] = 0;
	return (strdup);
}

char	*ft_strjoin(const char *str, const char *str1)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = (char *)malloc((ft_strlen(str) + ft_strlen(str1) + 1) * sizeof(char));
	if (!res)
		res = NULL;
	while (str[i])
	{
		res[i] = str[i];
		i ++;
	}
	while (str1[j])
	{
		res[i + j] = str1[j];
		j ++;
	}
	res [i + j] = '\0';
	return (res);
}

char	*ft_strchr(const char *str, const char ch)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == ch)
		return ((char *)&str[i]);
	return (NULL);
}
