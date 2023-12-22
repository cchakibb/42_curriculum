int		max(int* tab, unsigned int len)
{
	if (len == 0 || !tab)
		return (0);
	int max = 0;
	int i = 0;
	while(i < len)
	{
		if(tab[i] > max)
			max = tab[i];
		i++;
	}
	return max;
}

#include <stdio.h>
int main ()
{
	int tab[] = {1, 9, 133, 12, 15, 2};
	printf("%d", max(tab, 6));
}