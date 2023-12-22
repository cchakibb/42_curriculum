char    *ft_strrev(char *str)
{	
	int end = 0;
	int i = 0;
	char temp;
	while (str[end])
		end++;
	end--;
	while (end > i)
	{
		temp = str[i];
		str[i] = str[end];
		str[end] = temp;
		end--;
		i++;
	}
	return (str);	
}

/* #include <stdio.h>
int main ()
{
	char s[50] = "ChaKib1";
	printf("%s\n", ft_strrev(s));
	return 0;
} */
