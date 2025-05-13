/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:08:24 by stobin            #+#    #+#             */
/*   Updated: 2023/12/10 11:42:43 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_set(char c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

static int	trim_start(char const *s, char const *set)
{
	int	i;

	i = 0;
	while (s[i] && char_in_set(s[i], set))
		i++;
	return (i);
}

static int	trim_end(char const *s, char const *set)
{
	int	i;

	i = ft_strlen((char *)s) - 1;
	while (i >= 0 && char_in_set(s[i], set))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	start = trim_start(s1, set);
	end = trim_end(s1, set);
	if (start > end)
		return (ft_strdup(""));
	return (ft_substr(s1, start, end - start + 1));
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[] = " \t\n\r";
	char	set[] = " \t\r\t\v\n,";

	// char	str[] = ", \t,,,\r,\n,Hello ,World!,\t,\n,\r,,,,\v, ";
	// char	set[] = " \t\r\t\v\n,";
	printf("%s\n%s\n", str, ft_strtrim(str, set));
	return (0);
}
*/
