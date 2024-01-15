/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:34:23 by chbachir          #+#    #+#             */
/*   Updated: 2023/05/19 12:35:59 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* locate a substring in a string */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (i + j < len && haystack[i + j] == needle[j])
			{
				j++;
				if (!needle[j])
					return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (NULL);
}
/* 
int main()
{
	const char *big = "Foo Bar Baz";
    const char *little = "Bar";
	size_t len = 7;
    //char *ptr;

	//ptr = ft_strnstr(big, little, 7);
	
	//printf("%p\n", ptr);
	printf("%s\n", ft_strnstr(big, little, len));
	//printf("%s\n", strnstr(big, little, len));

}
 */
