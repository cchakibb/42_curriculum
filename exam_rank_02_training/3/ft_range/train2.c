#include <stdlib.h>

int abs_val(int nb)
{
	if (nb < 0)
		return (-nb);
	return nb;
}

int     *ft_range(int start, int end)
{
	int *arr;
	int size;
	int i = 0;
	size = abs_val(end - start) + 1;
	arr = malloc(size * sizeof(int));
	if (!arr) return NULL;
	while (start != end)
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
	return arr;
}

#include <stdio.h>
int main ()
{
	int * tab = ft_range(1, 3);
	printf("%d %d %d", tab[0], tab[1], tab[2]);
}