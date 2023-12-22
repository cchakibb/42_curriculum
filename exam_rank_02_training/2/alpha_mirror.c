#include <unistd.h>

void	alpha_mirror(char *s)
{
	while(*s)
	{
		if(*s >= 'A' && 'Z' >= *s)
			*s = 'M' - (*s - 'N');
		else if(*s >= 'a' && 'z' >= *s)
			*s = 'm' - (*s - 'n');
		write(1, s, 1);
		s++;
	} 
}

int main(int ac, char **av)
{
	if (ac == 2)
		alpha_mirror(av[1]);
	write(1, "\n", 1);
}

/* 
Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.

Case is not changed.

If the number of arguments is not 1, display only a newline.

Examples:

$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>
 */