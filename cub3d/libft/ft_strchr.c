/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:49:59 by stobin            #+#    #+#             */
/*   Updated: 2023/12/10 12:01:06 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int cc)
{
	unsigned char	c;

	c = (unsigned char) cc;
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	// printf("%s\n", ft_strchr("helooooo!", '!'));
	// printf("%p\n", ft_strchr("helooooo!", '!'));
	// printf("%s\n", ft_strchr("helooooo!", '\0'));
	// printf("%p\n", ft_strchr("helooooo!", '\0'));
	// printf("%s\n", ft_strchr("", '\0'));
	// printf("%p\n", ft_strchr("", '\0'));
	// printf("%p\n", ft_strchr("tripouille", 't' + 256));
	// printf("%s\n", ft_strchr("tripouille", 't' + 256));
	// printf("%p\n", strchr("tripouille", 't' + 256));
	// printf("%s\n", strchr("tripouille", 't' + 256));
	printf("%p\n", ft_strchr("teste", 'e'));
	printf("%s\n", ft_strchr("teste", 'e'));
	printf("%p\n", strchr("teste", 'e'));
	printf("%s\n", strchr("teste", 'e'));
	printf("%p\n", ft_strchr("teste", '\0'));
	printf("%s\n", ft_strchr("teste", '\0'));
	printf("%p\n", strchr("teste", '\0'));
	printf("%s\n", strchr("teste", '\0'));
	printf("%p\n", ft_strchr("test\xe9", (int)'\xe9'));
	printf("%s\n", ft_strchr("test\xe9", (int)'\xe9'));
	printf("%p\n", strchr("test\xe9", (int)'\xe9'));
	printf("%s\n", strchr("test\xe9", (int)'\xe9'));
	//// printf("%p\n", ft_strchr("testé", (int)'é'));
	//// printf("%s\n", ft_strchr("testé", (int)'é'));
	//// printf("%p\n", strchr("testé", (int)'é'));
	//// printf("%s\n", strchr("testé", (int)'é'));
	return (0);
}
*/
