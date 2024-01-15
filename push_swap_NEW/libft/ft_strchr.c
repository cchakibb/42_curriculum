/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:56:07 by chbachir          #+#    #+#             */
/*   Updated: 2023/05/19 12:28:05 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The  strchr() function returns a pointer to the first occurrenceof the character 
c in the string s.
The strchr() function returns a pointer to the matched character or NULL if the 
character is not found.
The terminating null byte is considered part of the string, so that if c is 
specified as '\0', these functions return a pointer to the terminator.
*/
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
	{
		if (*s == 0)
			return (NULL);
		s++;
	}
	return ((char *)s);
}
/* 
int	main()
{
	char *s = "Chakib Bachir";
	int c = 'k';
	printf("%s\n", ft_strchr(s, c));	
}
*/
