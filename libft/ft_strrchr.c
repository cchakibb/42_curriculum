/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:56:43 by chbachir          #+#    #+#             */
/*   Updated: 2023/05/19 12:37:17 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strrchr() function returns a pointer to the last
occurrence of the character c in the string s.
*/
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*end_ptr;

	end_ptr = (char *)s + ft_strlen(s);
	while (end_ptr >= s)
	{
		if (*end_ptr == (unsigned char) c)
			return ((char *)end_ptr);
		end_ptr--;
	}
	return (NULL);
}
/*
int main ()
{
	char	*s = "aka";
	int	c = 'a';
	printf("%p\n", &s[2]);
	ft_strrchr(s, c);
}
*/
