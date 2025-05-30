/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:47:18 by stobin            #+#    #+#             */
/*   Updated: 2024/04/19 13:23:51 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*copy_loop(char *p, char *tmp, int len)
{
	int	i;

	if (NULL != tmp && NULL != p)
	{
		i = 0;
		while (len > 0 && tmp[i])
		{
			p[i] = tmp[i];
			i++;
			len--;
		}
		p[i] = '\0';
		return (&p[i]);
	}
	return ((char *)"");
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*p;
	char	*start;

	len = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	start = p;
	p = copy_loop(p, s1, len);
	p = copy_loop(p, s2, len);
	return (start);
}

/*
#include <stdio.h>

int	main(void)
{
	const char	s1[7] = "Hello ";
	const char	s2[7] = "World!";

	printf("%s\n", ft_strjoin(s1, s2));
	printf("%p\n", ft_strjoin(s1, s2));
	return (0);
}
*/
