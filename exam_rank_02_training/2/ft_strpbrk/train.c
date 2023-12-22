char	*ft_strpbrk(const char *s1, const char *s2)
{
	const char *ret = (void*)0;
	int i = 0;
	int j;
	while(s1[i])
	{
		j = 0;
		while(s2[j])
		{
			if(s1[i] == s2[j])
			{
				ret = &s1[i];
				return ((char *)ret) ;
			}
			j++;	
		}
		i++;
	}
	return ((char *)ret);
}

#include <stdio.h>
int main ()
{
	char *s1 = "helloChakib";
	char *s2 = "wakib";
	printf("%s", ft_strpbrk(s1, s2));
}