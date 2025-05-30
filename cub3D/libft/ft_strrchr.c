/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:05:03 by stobin            #+#    #+#             */
/*   Updated: 2023/12/10 12:02:42 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*get_null_location(const char *s)
{
	if (!*s)
		return ((char *)s);
	if (*s)
		s++;
	while (*s || (*(s - 1) && *s == '\0'))
	{
		if ('\0' == *s)
			return ((char *)s);
		s++;
	}
	return ((char *)s);
}

char	*ft_strrchr(const char *s, int cc)
{
	unsigned char	c;
	char			*p;

	c = (unsigned char) cc;
	p = 0;
	if (!c)
		return (get_null_location(s));
	if (!*s)
		return (p);
	if (*s)
	{
		if (c == *s)
			p = (char *)s;
		s++;
	}
	while (*s || (*(s - 1) && *s == '\0'))
	{
		if ('\0' == *s)
			return (p);
		if (c == *s)
			p = (char *)s;
		s++;
	}
	return (p);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	// char	*src;
	// char	*d1;
	// char	*d2;

	//// printf("%s\n", ft_strrchr("helooooo!", '!'));
	//// printf("%p\n", ft_strrchr("helooooo!", '!'));
	//// printf("%s\n", ft_strrchr("helooooo!", '\0'));
	//// printf("%p\n", ft_strrchr("helooooo!", '\0'));
	// src = "the cake is a lie !\0I'm hidden lol\r\n";
	// d1 = strrchr(src, ' ');
	// printf("%s\n", d1);
	// d2 = ft_strrchr(src, ' ');
	// printf("%s\n", d2);
	// printf("%p\n", ft_strrchr("tripouille", 't' + 256));
	// printf("%s\n", ft_strrchr("tripouille", 't' + 256));
	printf("%p\n", strrchr("tripouille", 't' + 256));
	printf("%s\n", strrchr("tripouille", 't' + 256));
	// printf("%p\n", ft_strrchr("teste", 'e'));
	// printf("%s\n", ft_strrchr("teste", 'e'));
	// printf("%p\n", strrchr("teste", 'e'));
	// printf("%s\n", strrchr("teste", 'e'));
	// printf("%p\n", ft_strrchr("teste", '\0'));
	// printf("%s\n", ft_strrchr("teste", '\0'));
	// printf("%p\n", strrchr("teste", '\0'));
	// printf("%s\n", strrchr("teste", '\0'));
	// printf("%p\n", ft_strrchr("test\xe9", (int)'\xe9'));
	// printf("%s\n", ft_strrchr("test\xe9", (int)'\xe9'));
	// printf("%p\n", strrchr("test\xe9", (int)'\xe9'));
	// printf("%s\n", strrchr("test\xe9", (int)'\xe9'));
	return (0);
}
*/
