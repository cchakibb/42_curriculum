#include <stdlib.h>

char **ft_split(char *str)
{
    int i = 0; // Index for iterating through the input string
    int wordCount = 0; // Count of words in the input string
    char **result = NULL; // Pointer to the array of strings

	// First, count the number of words in the input string
    while (str[i])
	{	// Skip leading whitespace
        while (str[i] && str[i] == ' ')
            i++;
		// If we've encountered a non-whitespace character, increment the word count
        if (str[i] && str[i] != ' ')
            wordCount++;
		// Skip the word by moving to the next whitespace or the end of the string
        while (str[i] && str[i] != ' ')
            i++;
    }

    result = (char **)malloc(sizeof(char *) * (wordCount + 1));

    if (!result)
        return NULL;

    i = 0; // Reset the index for iterating through the input string
    int wordIndex = 0; // Index for the current word in the result array

	// Split the input string into words and store them in the result array
    while (str[i])
	{	// Skip leading whitespace
        while (str[i] && str[i] == ' ')
            i++;

        if (str[i] && str[i] != ' ') // Found the start of a word
		{
            int start = i;

            while (str[i] && str[i] != ' ')  // Find the end of the word
                i++;

            int length = i - start; // Calculate the length of the word

            result[wordIndex] = (char *)malloc(length + 1); // Allocate memory for the word and copy it from the input string

            if (!result[wordIndex])
                return NULL;

            int j = 0;
            while (j < length) // Copy the word
			{
                result[wordIndex][j] = str[start + j];
                j++;
            }
            result[wordIndex][length] = '\0';

            wordIndex++;
        }
    }

    result[wordCount] = NULL; // Null-terminate the result array

    return result;
}


#include <stdio.h>
int main() {
    char input[] = "My name is chakib";
    char **result = ft_split(input);

    if (result) {
        int i = 0;
        while (result[i] != NULL) {
            printf("%s\n", result[i]);
            free(result[i]);
            i++;
        }
        free(result);
    }

    return 0;
}
