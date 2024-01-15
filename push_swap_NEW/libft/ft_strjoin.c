/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:40:12 by chbachir          #+#    #+#             */
/*   Updated: 2023/05/19 12:29:51 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’. */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	char	*s3;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc((sizeof(char) * total_len) + 1);
	if (!s3)
		return (NULL);
	i = 0;
	while (*s1)
		s3[i++] = *s1++;
	while (*s2)
		s3[i++] = *s2++;
	s3[i] = '\0';
	return (s3);
}
/* 
int main ()
{
	char *s1 = "It should";
	char *s2 = " work, maybe";
	printf("%s\n", ft_strjoin(s1, s2));
}
 */
