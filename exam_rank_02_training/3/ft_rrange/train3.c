#include <stdlib.h>

int abs_val(int nb)
{
	if (nb < 0)
		return (-nb);
	return nb;
}


int     *ft_rrange(int start, int end)

{
	int *tab;
	int i = 0;
	int size = abs_val(end - start) + 1;
	tab = malloc(sizeof(int) * size);

	while(start != end)
	{
		if (start <= end)
		{
			tab[i] = end;
			end--;
		}
		else
		{
			tab[i] = end;
			end++;
		}
		i++;
	}
	tab[i] = start;

	return tab;
}
#include <stdio.h>
int main ()
{
	int * tab = ft_rrange(0, -3);
	printf("%d %d %d %d", tab[0], tab[1], tab[2], tab[3]/*, tab[4], tab[5], tab[6] */);
}