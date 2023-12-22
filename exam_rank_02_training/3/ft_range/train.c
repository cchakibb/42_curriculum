#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int *arr;
	int arr_size;
	int i = 0;
	arr_size = (end - start) + 1;
	if (arr_size < 0)
		arr_size = -(arr_size);
	arr = (int *)malloc(sizeof(int) * arr_size);
	if (!arr)
		return (NULL);
	while(start != end)
	{
		if (start <= end)
		{
			arr[i] = start;
			start++;
		}
		else
		{
			arr[i] = start;
			start--;
		}
		i++;
	}
	arr[i] = end;
	return (arr);
}

#include <stdio.h>
int main ()
{
	int start = -5;
	int end = 7;
	int i = 0;
	int *tab = ft_range(start, end);
	while (i < 15)
	{
		printf("%d ", tab[i]);
		i++;
	}
	return (0);
}