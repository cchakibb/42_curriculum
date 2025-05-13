/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:47:29 by stobin            #+#    #+#             */
/*   Updated: 2024/04/17 21:19:39 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	substrlen(char *str, char c)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

static char	**allocate_and_fill(char **arr, char *s, int j, int k)
{
	arr[j] = (char *)malloc(sizeof(char) * (k + 1));
	if (!(arr[j]))
	{
		while (j >= 0)
			free(arr[j--]);
		free(arr);
		return (NULL);
	}
	arr[j][k--] = '\0';
	while (k >= 0)
	{
		arr[j][k] = s[k];
		k--;
	}
	return (arr);
}

static char	**make_array(char **arr, char *s, char c, int i)
{
	int	j;
	int	k;

	j = 0;
	while (j < i)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			k = substrlen(s, c);
			if (k > 0)
			{
				arr = allocate_and_fill(arr, s, j, k);
				if (NULL == arr)
					break ;
			}
			s += k;
		}
		j++;
	}
	if (NULL == arr)
		return (NULL);
	arr[j] = NULL;
	return (arr);
}

static int	count_strings(char *s, char c, int i)
{
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			i++;
		s++;
	}
	return (i);
}

char	**ft_split(char *s, char c)
{
	int		i;
	char	**arr;

	if (s == NULL)
		return (NULL);
	if (*s == '\0')
	{
		arr = (char **)malloc(sizeof(char *));
		if (!arr)
			return (NULL);
		arr[0] = NULL;
		return (arr);
	}
	i = 0;
	i = count_strings(s, c, i);
	if (i < 0)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (i + 1));
	if (!arr)
		return (NULL);
	return (make_array(arr, s, c, i));
}

/*
#include <stdio.h>

int	main(void)
{
	char		**arr;
	int			i;
	const char	*str = "hello!";
	// const char	*str = "lorem ipsum dolor sit amet, consectetur adipiscing
	// elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet,
	// adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam.
	// Maecenas ligula massa, varius a, semper congue, euismod non, mi.";
	// const char	*str = "\0aa\0bbb";
	//	const char	*str = "Hello world. This is my string!";
	// arr = NULL;
	// arr = ft_split(str, '\0');
	arr = ft_split(str, ' ');
	i = 0;
	if (arr == NULL)
		printf("%p\n", arr);
	else
	{
		while (arr[i])
		{
			printf("%s\n", arr[i]);
			i++;
		}
		i = 0;
		while (arr[i] != NULL)
		{
			free(arr[i]);
			if(arr[i] != NULL)
			{
				i++;
				continue ;
			}
		}
		free(arr);
	}
	//ft_split("\0a\0bbb", '\0');
	return (0);
}
*/
