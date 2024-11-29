#include <stdio.h>
#include <stdlib.h>

int tableau[4];

int main()
{
    tableau[0] = 10;
    tableau[1] = 23;
    tableau[2] = 505;
    tableau[3] = 8;
    printf("adresse tableau %d \n", tableau);
    printf("element 1 %d \n", tableau[0]);
    printf("element 1 avec pointeur %d \n", *tableau);
    printf("element 2 avec pointeur %d \n", *(tableau + 1)); // Identique : renvoie la valeur contenue dans la seconde case

    return 0;
}