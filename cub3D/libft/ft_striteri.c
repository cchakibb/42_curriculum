/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:45:39 by stobin            #+#    #+#             */
/*   Updated: 2023/12/08 23:35:29 by stobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	len;
	unsigned int	i;

	if (!s || !f)
		return ;
	len = (unsigned int)ft_strlen(s);
	i = 0;
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}

/*
void	cfun(unsigned int n, char *c)
{
	*c += n;
	return ;
}

#include <stdio.h>

int	main(void)
{
	char	str1[] = "abc";

	ft_striteri(str1, &cfun);
	printf("%s\n", str1);
	return (0);
}
*/
