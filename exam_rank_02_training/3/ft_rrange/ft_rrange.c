#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
	int *arr;
	int i = 0;
	int arr_size = (end - start) + 1;
	if (arr_size < 0)
		arr_size = -arr_size;
	arr = (int *)malloc(sizeof(int) * arr_size);
	if (!arr)
		return NULL;
	while (start != end)
	{
		if (start <= end)
		{
			arr[i] = end;
			end--;
		}
		else
		{
			arr[i] = start;
			start++;
		}
		i++;
	}
	arr[i] = start;
	return (arr);
}

#include <stdio.h>
int main ()
{
	int * tab = ft_rrange(0, -3);
	printf("%d %d %d %d", tab[0], tab[1], tab[2], tab[3]);
}

/* #include <stdio.h>
int main ()
{
	int start = -1;
	int end = 3;
	int i = 0;
	int *tab = ft_rrange(start, end);
	while (i < end)
	{
		printf("%d ", tab[i]);
		i++;
	}
	return (0);
} */