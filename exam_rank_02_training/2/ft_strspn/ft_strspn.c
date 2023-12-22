#include <stddef.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;
	size_t j = 0;
	size_t count = 0;

	while (s[i])
	{
		while(accept[j])
		{
			if (s[i] == accept[j])
			{
				count++;
				break ;
			}
			j++;
		}
		i++;
	}
	return count;
}
/* 
#include <string.h>
#include <stdio.h>
int main ()
{								//   s             accept
	printf("real: %ld\n", strspn("ABCDEFG019874", "XABCD"));
	printf("me: %ld\n", ft_strspn("ABCDEFG019874", "XABCD"));
} */
