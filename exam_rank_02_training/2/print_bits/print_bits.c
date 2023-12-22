#include <unistd.h>


void print_bits(unsigned char octet)
{
	int	i = 7;
	unsigned char 	bit;

	while (i >= 0)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
		i--;
	}
}


// OR

void    print_bits(unsigned char octet)
{
   int i = 7;

   while (i >= 0)
   {
        if (octet & (1 << i))
            write (1, "1", 1);
        else
            write (1, "0", 1);
        i--;
   }
}


