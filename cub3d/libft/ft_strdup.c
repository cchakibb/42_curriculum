/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:23:50 by stobin            #+#    #+#             */
/*   Updated: 2023/12/08 23:45:14 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dup;

	i = 0;
	while (src[i])
		i++;
	dup = (char *)malloc((i + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	dup[i--] = '\0';
	while (i >= 0)
	{
		dup[i] = src[i];
		i--;
	}
	return (dup);
}

/*
#include <stdio.h>

int	main(void)
{
	const char	str[] = "Original contents!";
	char		*new_str;

	new_str = ft_strdup(str);
	printf("%s\n", new_str);
	free(new_str);
	return (0);
}
*/
