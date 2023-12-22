#include <unistd.h>

int isLastCharOfWord(char *str, int idx) 
{	// receives the whole string (a command line argument) AND the index of a char.
	// if the next char (sr[idx + 1]) is space/tab/end of string, it's the last char, 1 is returned. Else 0 i returned.
	if (str[idx + 1] == ' ' || str[idx + 1] == '\t' ||  str[idx + 1] == '\0')
		return (1);
	else
		return (0);
}
int isLowerCaser(char c)
{
	if (c >= 'a' && 'z' >= c)
		return 1;
	else
		return 0;
}
int isUpperCase(char c)
{
    return (c >= 'A' && c <= 'Z') ? 1 : 0; // ternary
}

void	rstr_capitalizer(int ac, char **av)
{
	int i = 1; 	// loop thru each args
	int k; 		// loop thru strings
	while(i < ac)
	{
		k = 0;
		while (av[i][k])
		{
			if (isLastCharOfWord(av[i], k) && isLowerCaser(av[i][k]))
				av[i][k] -= 32; 
			else if (!isLastCharOfWord(av[i], k) && isUpperCase(av[i][k]))
				av[i][k] += 32;
			write(1, &av[i][k], 1);
			k++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int main (int ac, char **av)
{
	(ac > 1) ? rstr_capitalizer(ac, av) : write(1, "\n", 1);
	return (0);
}
