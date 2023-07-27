/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:08:59 by chbachir          #+#    #+#             */
/*   Updated: 2023/07/27 15:48:42 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
s: The string from which to create the substring.
start: The start index of the substring in the string ’s’.
len: The maximum length of the substring.
Returns: The substring or NULL if the allocation fails.
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	if (!s || ft_strlen(s) <= start || !len)
		return (ft_strdup(""));
	i = start;
	while (s[i] != '\0')
		i++;
	if (len > (i - start))
		len = i - start;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

/*
int main ()
{
	char *s = "Chakib";
	printf("%s\n", ft_substr(s, 2, 2)); // ak
} */
