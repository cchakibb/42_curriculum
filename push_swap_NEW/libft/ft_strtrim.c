/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:56:59 by chbachir          #+#    #+#             */
/*   Updated: 2023/05/19 12:37:36 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.

1 - Find the first non-set character
2 - Find the last non-set character
3- 	Allocate memory for the trimmed string
4 - Copy the trimmed string into the new memory block
*/

#include "libft.h"

static char	*ft_strncpy(char *dest, char const *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	len;
	size_t	start;
	size_t	end;

	len = ft_strlen(s1);
	start = 0;
	end = len;
	while (start < len && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	trimmed = (char *)malloc((end - start + 1) * sizeof(char));
	if (!trimmed)
		return (NULL);
	ft_strncpy(trimmed, s1 + start, end - start);
	trimmed[end - start] = '\0';
	return (trimmed);
}
/* 
int main ()
{
	char const	*s1 = "Trim me please";
	char const	*set = "please";
	printf("%s\n", ft_strtrim(s1, set));
}
 */
