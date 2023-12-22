/*
Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110 (== 38 in decimal)
	 ||
	 \/
 0110  0100 (== 100 in decimal)
*/

unsigned char	reverse_bits(unsigned char octet)
{
	int i = 8;
	unsigned char res = 0;

	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet /= 2;
		i--;
	}
	return (res);
}


#include <stdio.h>
int main ()
{
	unsigned char octet = 38;
	printf("%d", reverse_bits(octet)); // should give 100
}


