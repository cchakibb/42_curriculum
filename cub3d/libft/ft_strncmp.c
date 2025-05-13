/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:09:58 by stobin            #+#    #+#             */
/*   Updated: 2023/12/08 23:45:45 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	if (0 == n)
		return (0);
	while ((*s1 && *s2) && (*s1 == *s2) && (n - 1 > 0))
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_strncmp(" ", " ", 1));
	return (0);
}
*/
