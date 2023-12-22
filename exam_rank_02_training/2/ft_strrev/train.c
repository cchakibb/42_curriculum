char    *ft_strrev(char *str)
{
	int start = 0;
	int end = 0;
	char temp;
	while (str[end])
		end++;
	end--;

	while(start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		end--;
		start++;
	}
	return (str);
}

/* #include <stdio.h>
int main()
{
	char str[] = "chakib";
	printf("%s", ft_strrev(str)); 
} */