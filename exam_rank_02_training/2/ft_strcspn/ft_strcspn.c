#include <stddef.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t i = 0;
	size_t j = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i) ;
			j++;
		}
		i++;
	}
	return (i);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%lu\n", ft_strcspn("test", "e"));
	printf("%lu\n", strcspn("test", "e"));
	printf("%lu\n", ft_strcspn("test", "f"));
	printf("%lu\n", strcspn("test", "f"));
} */

