/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:30:24 by stobin            #+#    #+#             */
/*   Updated: 2023/12/08 23:37:14 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*return_terminator(char *p)
{
	p = (char *)malloc(1);
	if (!p)
		return (NULL);
	*p = '\0';
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	int		i;
	int		rlen;

	if (!s)
		return (NULL);
	rlen = ft_strlen((char *)s);
	i = rlen - (int)start;
	p = NULL;
	if (start > (size_t)rlen)
		return (return_terminator(p));
	if (len > rlen - start)
		len = rlen - start;
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (s[start + i] && i < (int)len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

/*
#include <stdio.h>

int	main(void)
{
	const char	*str1 = "";

	// const char	*str1 = "A rather long string.";
	printf("%s\n", ft_substr(str1, 2, 6));
	return (0);
}
*/
