/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:16:06 by chbachir          #+#    #+#             */
/*   Updated: 2023/05/19 12:27:27 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
s: The string to be split.
c: The delimiter character. 
Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.
*/
/*
#include "libft.h"

static	char	**to_free(char **pt)
{
	int	i;

	i = 0;
	while (pt[i])
	{
		free(pt[i]);
		i++;
	}
	free(pt);
	return (0);
}

static int	ft_wordlength(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

static int	ft_countwords(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**pt;
	int		i;
	int		t;

	i = 0;
	t = 0;
	if (!s)
		return (0);
	pt = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!pt)
		return (0);
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			pt[t] = ft_substr(s, i, ft_wordlength(&s[i], c));
			if (!pt[t])
				return (to_free(pt));
			i = i + ft_strlen(pt[t]) - 1;
			t++;
		}
		i++;
	}
	pt[t] = 0;
	return (pt);
}*/
/* 
int	main(void)
{
	int	i = 0;
	char	**tab;
	
	tab = ft_split("", ' ');
	while (i < 2)
	{
		printf("string %d : %s\n", i, tab[i]);
		i++;
	}
	return (0);
}
 */
