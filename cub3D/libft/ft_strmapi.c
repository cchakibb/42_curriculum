/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:58:55 by stobin            #+#    #+#             */
/*   Updated: 2023/12/08 23:50:23 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*newstr;
	char	*str;

	if (!s || !f)
		return (NULL);
	str = (char *)s;
	len = ft_strlen(str);
	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		newstr[i] = (*f)(i, str[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

/*
char	cfun(unsigned int n, char c)
{
	return (c + n);
}

#include <stdio.h>

int	main(void)
{
	char	(*cfunptr)(unsigned int, char);

	(cfunptr)(unsigned int, char) = &cfun;
	printf("%s\n", ft_strmapi("abc", (*cfunptr)));
	return (0);
}
*/
