#include <unistd.h>

int is_blank(char c)
{
	return(c <= ' ');
}
int is_low_case(char c)
{
	return (c >= 'a' && 'z' >= c);
}
int is_upper_case(char c)
{
	return (c >= 'A' && 'Z' >= c);
}
int is_last_char_of_word(int idx, char *str)
{
	return (is_blank(str[idx + 1]) || str[idx + 1] == '\0');
}

void	rstr_capitalizer(int ac, char **av)
{
	int i = 1; //exclude prog name
	int k = 0;
	while (i < ac)
	{
		k = 0;
		while(av[i][k])
		{
			if(is_last_char_of_word(k, av[i]) && is_low_case(av[i][k]))
				av[i][k] -= 32;
			if(!is_last_char_of_word(k, av[i]) && is_upper_case(av[i][k]))
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
	if (ac > 1)
		rstr_capitalizer(ac, av);
	if (ac == 1)	
		write(1, "\n", 1);
}
// "SecONd teST A LITtle BiT   Moar comPLEX" "  But... This iS not THAT COMPLEX" "     Okay, this is the last 12301 but not    the least    t" | cat -e