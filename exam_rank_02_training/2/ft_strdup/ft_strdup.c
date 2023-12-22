#include <stdlib.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}
char    *ft_strdup(char *src)
{
	int i = 0;
	char *dup;
	dup = malloc(ft_strlen(src) + 1);
	if (dup == NULL)
		return NULL;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return dup;
}
