 #include <unistd.h>

int	ft_strlen(char *s)
{
	int len = 0;
	while(s[len])
		len++;
	return len;
}

void	wdmatch(char **av)
{
	int count = 0;
	int i = 0;
	int k = 0;
	char *s1 = av[1];
	char *s2 = av[2];

	while(s1[i])
	{
		while(s2[k])
		{
			if (s1[i] == s2[k])
			{
				count++;
				break ;
			}	
				
			k++;
		}
		i++;
	}

	if (count == ft_strlen(s1))
	{
		while(*s1)
		{
			write(1, s1, 1);
			s1++;
		}
	}
}

 int main (int ac, char **av)
 {
	if (ac == 3)
		wdmatch(av);
	write(1, "\n", 1);
 }