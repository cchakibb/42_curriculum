/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:14:15 by chbachir          #+#    #+#             */
/*   Updated: 2023/05/19 12:35:08 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && n--)
	{
		if (*s1++ != *s2++)
			return ((unsigned char)*--s1 - (unsigned char)*--s2);
	}
	return (0);
}

/*
int main ()
{
	size_t n = 6;
	//char *s1 = "aac";
	//char *s2 = "aar";
	//printf("%d\n", ft_strncmp(s1, s2, n));
	//printf("%d\n", strncmp(s1, s2, n));
	printf("ft_strncmp : %d\n", ft_strncmp("test\200", "test\0", n));
	printf("strncmp : %d\n", strncmp("test\200", "test\0", n));
}
*/
