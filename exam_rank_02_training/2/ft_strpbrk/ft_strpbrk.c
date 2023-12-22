char	*ft_strpbrk(const char *s1, const char *s2)
{
	const char *ret = (void *)0;
	int i = 0;
	int j = 0;

	while (s2[i])
	{
		j = 0;
		while(s1[j])
		{
			if (s1[j] == s2[i])
			{
				ret = &s1[j];
				return ((char *)ret);
			}		
			j++;
		}
		i++;
	}
	return ((char *)ret);
}

/* #include <string.h>
#include <stdio.h>
int main ()
{
	char *s1 = "chakib";
	char *s2 = "ix";
	printf("%s\n", ft_strpbrk(s1, s2));
	printf("%s\n", strpbrk(s1, s2));

} */
