#include <stdio.h>
#include <stdlib.h>

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    int i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            return 0;
        }
        i++;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("\n");
        return 1;
    }

    int n = atoi(argv[1]);
    int divisor = 2;
    int printed = 0;

    while (n > 1)
	{
        if (n % divisor == 0 && is_prime(divisor))
		{
            printf("%d", divisor);
            n /= divisor;
            if (n > 1) {
                printf("*");
            }
            printed = 1;
        }
		else
        	divisor++;
    }

    if (!printed) // The input number is prime
        printf("%d", n);

	printf("\n");

    return 0;
}
