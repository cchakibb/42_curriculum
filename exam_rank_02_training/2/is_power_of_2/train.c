int	    is_power_of_2(unsigned int n)
{
	if (n == 0)
		return 0;
	if ((n & (n - 1)) == 0)
		return 1;
	else
		return 0;
}

/* #include <stdio.h>
int main()
{
	printf("%d\n", is_power_of_2(4));
	printf("%d\n", is_power_of_2(8));
	printf("%d\n", is_power_of_2(0));
	printf("%d\n", is_power_of_2(17));
	printf("%d\n", is_power_of_2(256));
} */

/* 
	we compare the binary representation of the number 
	to check with the number itself - 1, using bitwise '&' AND.

010000000 = 128 
001111111 = 127
000000000 = 0 if it's 0 it's a power of 2.

*/
