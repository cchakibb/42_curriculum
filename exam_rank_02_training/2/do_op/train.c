#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	do_op(int n1, char operator, int n2)
{
	int result = 0;
	if (operator == '+')
		result = n1 + n2;
	else if (operator == '-')
		result = n1 - n2;
	else if (operator == '/')
		result = n1 / n2;
	else if (operator == '*')
		result = n1 * n2;
	else if (operator == '%')
		result = n1 % n2;
	printf("%d", result);
}

int main (int ac, char **av)
{
	int n1, n2;
	char operator;
	if (ac == 4)
	{
		n1 = atoi(av[1]);
		operator = av[2][0];
		n2 = atoi(av[3]);
		do_op(n1, operator, n2);
	}
	printf("\n");
}