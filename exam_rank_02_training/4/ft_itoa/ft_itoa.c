#include <stdio.h>
#include <stdlib.h>

char *ft_itoa(int nbr)
{
    int temp = nbr;
    int length = 0;
    // Calculate the length of the string
    while (temp != 0)
	{
        temp /= 10;
        length++;
    }
    if (nbr <= 0)
        length++;  // Account for the negative sign or '0'

    // Allocate memory for the string, including space for the null terminator
    char *result = (char *)malloc(length + 1);
    if (!result)
        return NULL; // Memory allocation failed

    if (nbr < 0)
	{
        result[0] = '-';
        nbr = -nbr;
    }
	else if (nbr == 0)
        result[0] = '0';

    int i = length - 1;
    while (nbr > 0)
	{
        result[i] = (char)((nbr % 10) + '0');
        nbr /= 10;
        i--;
    }
    result[length] = '\0';

    return result;
}

int main() {
    int number = -2147483647;
    char *str = ft_itoa(number);

    if (str != NULL) {
        printf("Integer: %d\nString: %s\n", number, str);
        free(str);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
