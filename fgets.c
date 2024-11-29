#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char nom[10];

    printf("Quel est votre nom ? ");
    fgets(nom, 10, stdin);
    printf("Ah ! Vous vous appelez donc %s !\n\n", nom);

    return 0;
}