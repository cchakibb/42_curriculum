/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:41:25 by chbachir          #+#    #+#             */
/*   Updated: 2023/05/19 12:29:12 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
The  strdup() function returns a pointer to a new string which is a
duplicate of the string s. 
Memory for the new  string is obtained with  malloc(3), 
and can be freed with free(3). 
*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*duplicate;

	len = ft_strlen(s);
	duplicate = malloc((sizeof(char) * len) + 1);
	if (duplicate == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		duplicate[i] = s[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

/*
int main ()
{
	char *s = "duplicate me";
	printf("1: %p\n", s);
	ft_strdup(s);
	printf("2: %s\n", ft_strdup(s));
	printf("3: %p\n", ft_strdup(s));
}
*/
