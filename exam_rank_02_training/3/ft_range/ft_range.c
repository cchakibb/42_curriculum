#include<stdlib.h>
 #include <stdio.h>
 int *ft_range(int start, int end)
 {
     int array_size;
     int * arr;
     array_size = (end - start) + 1;
     if(array_size < 0)
         array_size = -(array_size);
     arr = (int *) malloc(sizeof(int) * array_size);
     int i = 0;
     //arr[i] = start;
     if (!arr)
         return (NULL);
     while (start != end)
     {
         if (end >= start)
         {
             arr[i] = start;
             start++;
         }
         else
         {
             arr[i] = start;
             start--;
         }
         printf("%d\n",arr[i]);
         i++;
     }
     arr[i] = end;
     printf("%d\n",arr[i]);
 
     return (arr);
 }

int main ()
{
	
	ft_range(7, 11);
/* 	printf("%d\n", tab[0]);
	printf("%d\n", tab[1]);
	printf("%d\n", tab[2]);
	printf("%d\n", tab[3]); */
}
