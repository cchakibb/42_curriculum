#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 4)
	{
		char operator = av[2][0];
		int op1 = atoi(av[1]);
		int op2 = atoi(av[3]);
		int result = 0;

		if(operator == '+')
			result = op1 + op2;
		else if (operator == '-')
			result = op1 - op2;
		else if (operator == '*')
			result = op1 * op2;
		else if (operator == '/')
			result = op1 / op2;
		else if (operator == '%')
			result = op1 % op2;
		printf("%d\n", result);
	}
	else
		write(1, "\n", 1);
	return (0);
}


