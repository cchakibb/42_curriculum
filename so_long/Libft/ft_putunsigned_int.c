/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:53:52 by chbachir          #+#    #+#             */
/*   Updated: 2024/06/06 14:53:52 by chbachir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

int	ft_unsigned_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num <= 0)
	{
		len ++;
	}
	while (num != 0)
	{
		num = num / 10;
		len ++;
	}
	return (len);
}

int	ft_put_unsigned_int(unsigned int num)
{
	char	*str;
	int		len;

	len = 0;
	if (num <= 0)
		len = 1;
	len = ft_unsigned_len(num);
	str = (char *) malloc((len + 1) * sizeof(char));
	str[len] = '\0';
	if (str == NULL)
		return (0);
	while (len > 0)
	{
		str[len - 1] = (num % 10) + 48;
		num = num / 10;
		len --;
	}
	ft_putstring(str);
	free(str);
	return (1);
}

int	ft_putunsigned_int(unsigned int num)
{
	int	len;

	len = 0;
	len = ft_unsigned_len(num);
	ft_put_unsigned_int(num);
	return (len);
}

/*int main(void)
{
  unsigned int num = 10;
  ft_putunsigned_int(num);
}*/
