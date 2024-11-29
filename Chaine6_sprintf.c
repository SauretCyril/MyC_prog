#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *chaine;
    int age = 15;
    int length;

    // Calculate the length of the string
    length = snprintf(NULL, 0, "Tu as %d ans !", age) + 1;

    // Allocate memory for the string
    chaine = (char *)malloc(length * sizeof(char));
    if (chaine == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Write the formatted string into chaine
    sprintf(chaine, "Tu as %d ans !", age);

    // Print chaine to verify it contains the correct string
    printf("%s", chaine);

    // Free the allocated memory
    free(chaine);

    return 0;
}